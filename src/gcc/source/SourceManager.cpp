#include <utility>

#include "gcc/source/SourceManager.hpp"

#include <algorithm>
#include <fstream>

#include "gcc/lexer/Token.hpp"

SourceManager::SourceManager(std::filesystem::path path): path_(std::move(path)) {

    // Reading the source code
    source_ = readFile(path_);

    buildLineTable();
}

SourceManager::SourceManager(std::string source): source_(std::move(source)) {
    buildLineTable();
}

std::filesystem::path SourceManager::path() const noexcept {
    return path_;
}

std::string SourceManager::filename() const {
    return path_.filename().string();
}

std::string_view SourceManager::source() const {
    return source_;
}


std::size_t SourceManager::size() const noexcept {
    return source_.size();
}

bool SourceManager::empty() const noexcept {
    return source_.empty();
}

/*
 * Returns the character at the specified offset
 */
char SourceManager::operator[](std::size_t offset) const noexcept {
    return source_[offset];
}

/*
 * Returns whether the specified offset is valid.
 */
bool SourceManager::isValidOffset(std::size_t offset) const noexcept {
    return offset < source_.size();
}

/*
 * Returns the source location corresponding to a character offset.
 *
 * Converts a zero-based character offset into a SourceLocation containing
 * the corresponding line and column numbers.
 */
SourceLocation SourceManager::location(std::size_t offset) const {

    if (offset > source_.size()) {
        offset = source_.size();
    }

    auto it = std::upper_bound(
        lineOffsets_.begin(),
        lineOffsets_.end(),
        offset);

    std::size_t line =
        std::distance(lineOffsets_.begin(), it);

    std::size_t lineStart =
        lineOffsets_[line - 1];

    return {
        offset,
        line,
        offset - lineStart + 1
    };
}

/*
 * Returns the contents of a source line.
 */
std::string_view SourceManager::line(std::size_t lineNumber) const {

    if (lineNumber == 0 ||
        lineNumber > lineOffsets_.size()) {
        return {};
        }

    std::size_t begin =
        lineOffsets_[lineNumber - 1];

    std::size_t end =
        (lineNumber == lineOffsets_.size())
            ? source_.size()
            : lineOffsets_[lineNumber];

    while (end > begin &&
           (source_[end - 1] == '\n' ||
            source_[end - 1] == '\r')) {
        --end;
            }

    return std::string_view(source_).substr(begin, end - begin);
}

/*
 * Returns the source text (lexene) corresponding to a token.
 *
 * The returned string view refers directly to the managed source text
 * and remains valid for as long as the SourceManager exists.
 */
std::string_view SourceManager::lexeme(const Token& token) const
{
    return std::string_view(
        source_.data() + token.offset,
        token.length
    );
}

/*
 *  Records the starting character offset of each line in the source
 *  text to enable efficient offset-to-line/column mapping.
 */
void SourceManager::buildLineTable() {

    lineOffsets_.clear();

    lineOffsets_.push_back(0);

    for (std::size_t i = 0; i < source_.size(); ++i) {

        if (source_[i] == '\n') {
            lineOffsets_.push_back(i + 1);
        }
    }
}

std::string SourceManager::readFile(const std::filesystem::path&  path) const {
    std::ifstream file(path);

    if (!file)
    {
        throw std::runtime_error("Could not open file: " + path.string());
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

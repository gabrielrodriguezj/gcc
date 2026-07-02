#include <utility>

#include "gcc/source/SourceManager.hpp"

#include <fstream>

#include "gcc/lexer/Token.hpp"

SourceManager::SourceManager(std::filesystem::path path): path_(std::move(path)) {

    // Reading the source code
    source_ = readFile(path_);
}

SourceManager::SourceManager(std::string source): source_(std::move(source)) {}

std::string_view SourceManager::lexeme(const Token& token) const
{
    return std::string_view(
        source_.data() + token.offset,
        token.length
    );
}

std::string_view SourceManager::source() const {
    return source_;
}

std::string SourceManager::filename() const {
    return path_.filename().string();
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

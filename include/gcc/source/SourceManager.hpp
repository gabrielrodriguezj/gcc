#ifndef GCC_SOURCEMANAGER_HPP
#define GCC_SOURCEMANAGER_HPP
#include <filesystem>
#include <string>
#include <string_view>

#include "gcc/lexer/Token.hpp"

class SourceManager {
public:
    explicit SourceManager(std::filesystem::path );
    explicit SourceManager(std::string);
    std::string_view lexeme(const Token& token) const;
    std::string_view source() const;
    std::string filename() const;

private:
    std::filesystem::path path_;
    std::string source_;

    std::string readFile(const std::filesystem::path&) const;
};

#endif //GCC_SOURCEMANAGER_HPP

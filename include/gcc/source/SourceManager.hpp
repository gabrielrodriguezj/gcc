#ifndef GCC_SOURCEMANAGER_HPP
#define GCC_SOURCEMANAGER_HPP
#include <string>
#include <string_view>

#include "gcc/lexer/Token.hpp"

class SourceManager {
public:

    explicit SourceManager(std::string source)
        : source_(std::move(source))
    {}

    std::string_view lexeme(const Token& token) const;
    const std::string& source() const;

private:
    std::string source_;
};

#endif //GCC_SOURCEMANAGER_HPP

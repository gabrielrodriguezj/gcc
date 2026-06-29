#include "gcc/source/SourceManager.hpp"

#include "gcc/lexer/Token.hpp"

std::string_view SourceManager::lexeme(const Token& token) const
{
    return std::string_view(
        source_.data() + token.offset,
        token.length
    );
}

const std::string& SourceManager::source() const {
    return source_;
}

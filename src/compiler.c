#include "compiler.h"

#include "scanner.h"

bool compile(const char* source) {
    init_scanner(source);

    while (true) {
        const token_t token = scan_token();
        print_token(token);

        if (token.type == TOKEN_EOF) {
            break;
        }

        if (token.type == TOKEN_ERROR) {
            return false;
        }
    }
    return true;
}

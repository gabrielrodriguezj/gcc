#ifndef GCC_SCANNER_H
#define GCC_SCANNER_H
#include "token.h"

void init_scanner(const char* source);
Token scan_token();
#endif //GCC_SCANNER_H
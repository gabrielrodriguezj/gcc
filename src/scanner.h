#ifndef GCC_SCANNER_H
#define GCC_SCANNER_H
#include "token.h"

void initScanner(const char* source);
Token scanToken();
#endif //GCC_SCANNER_H
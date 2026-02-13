#include <stdio.h>
#include <stdlib.h>

#include "compiler.h"

// Read the input file
static int readFile(char** buffer, const char* path) {
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file \"%s\".\n", path);
        exit(74);
    }

    // Move to the end of the file, take the size
    // of the file and back to the beginning
    fseek(file, 0L, SEEK_END);
    const size_t fileSize = ftell(file);
    rewind(file);

    // allocating the needed memory space
    *buffer = malloc(sizeof(char)*fileSize + 1);
    if (*buffer == NULL) {
        fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
        return -1;
    }

    size_t bytesRead = fread(*buffer, sizeof(char), fileSize, file);
    if (bytesRead < fileSize) {
        fprintf(stderr, "Could not read file \"%s\".\n", path);
        return -1;
    }

    // Adding the EOF character
    (*buffer)[bytesRead] = '\0';
    fclose(file);

    return 0;
}

int main(const int argc, const char* argv[]) {
    if(argc == 1) {
        fprintf(stderr, "Error: no input files");
        exit(64);
    }

    if (argc != 2) {
        fprintf(stderr, "For the moment, only one parameter is accepted");
        exit(64);
    }

    char* buffer = nullptr;
    if (readFile(&buffer, argv[1]) != 0) {
        exit(74);
    }

    // Start the compilation process
    compile(buffer);
    
    free(buffer);
}

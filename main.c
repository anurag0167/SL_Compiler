#include <stdio.h>
#include "lexerf.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    // Open the source file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    printf("Tokenizing the input file '%s':\n\n", argv[1]);

    Token token;

    // Tokenize the input file
    do {
        getNextToken(file, &token);
        printf("Token Type: %d, Text: %s\n", token.type, token.text);
    } while (token.type != TOKEN_EOF);

    fclose(file);
    return 0;
}

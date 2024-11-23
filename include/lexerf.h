#ifndef LEXERF_H_
#define LEXERF_H_

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LEN 100

// Enum for token types
typedef enum {
    TOKEN_INT,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_ASSIGN,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_IF,
    TOKEN_EQUAL,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_SEMICOLON,
    TOKEN_UNKNOWN,
    TOKEN_EOF
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char text[MAX_TOKEN_LEN];
} Token;

// Function prototypes
void getNextToken(FILE *file, Token *token);

#endif

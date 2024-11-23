#ifndef TOKEN_H
#define TOKEN_H

#include "string_view.h"
#include <stdint.h>

typedef enum {
    TOKEN_INT,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_ASSIGN,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_IF,
    TOKEN_EQUAL,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_SEMICOLON,
    TOKEN_WS,
    TOKEN_UNKNOWN,
    TOKEN_EOF
} enum_token_type;

const char* enum_token_type_to_string(enum_token_type token_type);

typedef struct
{
    string_view text;
    enum_token_type type;
} token;

#endif

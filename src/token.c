
#include "token.h"

const char* enum_token_type_to_string(enum_token_type token_type)
{
    switch(token_type)
    {
        case TOKEN_INT:
            return "TOKEN_INT";
        case TOKEN_IDENTIFIER:
            return "TOKEN_IDENTIFIER";
        case TOKEN_NUMBER:
            return "TOKEN_NUMBER";
        case TOKEN_ASSIGN:
            return "TOKEN_ASSIGN";
        case TOKEN_PLUS:
            return "TOKEN_PLUS";
        case TOKEN_MINUS:
            return "TOKEN_MINUS";
        case TOKEN_IF:
            return "TOKEN_IF";
        case TOKEN_EQUAL:
            return "TOKEN_EQUAL";
        case TOKEN_LPAREN:
            return "TOKEN_LPAREN";
        case TOKEN_RPAREN:
            return "TOKEN_RPAREN";
        case TOKEN_LBRACE:
            return "TOKEN_LBRACE";
        case TOKEN_RBRACE:
            return "TOKEN_RBRACE";
        case TOKEN_SEMICOLON:
            return "TOKEN_SEMICOLON";
        case TOKEN_WS:
            return "TOKEN_WS";
        case TOKEN_UNKNOWN:
            return "TOKEN_UNKNOWN";
        case TOKEN_EOF:
            return "TOKEN_EOF";
    }

    return "";
}

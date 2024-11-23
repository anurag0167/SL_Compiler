#include "types.h"
#include "token.h"
#include <ctype.h>
#include "keywords.h"

static void classify_identifier_keyword(token* token)
{
    const string_view string_view_keyword_int = MAKE_STRING_VIEW(KEYWORD_INT);
    const string_view string_view_keyword_if = MAKE_STRING_VIEW(KEYWORD_IF);

    if(is_equal(token->text, string_view_keyword_if))
    {
        token->type = TOKEN_IF;
    }
    else if(is_equal(token->text, string_view_keyword_int))
    {
        token->type = TOKEN_INT;
    }
    else
    {
        token->type = TOKEN_IDENTIFIER;
    }
}

void generate_next_token(c_str buffer, u64* index, token* token)
{
    char current = buffer[*index];
    token->text.begin = buffer + *index;

    if(current == 0)
    {
        (*index)++;
        token->type = TOKEN_EOF;
        token->text.end = buffer + *index;
        return;
    }

    if(isspace(current))
    {
        (*index)++;
        token->text.end = buffer + *index;
        token->type = TOKEN_WS;
        return;
    }

    if(isalpha(current))
    {
        (*index)++;

        while(1)
        {
            current = buffer[*index];

            if(!isalpha(current))
            {
                token->text.end = buffer + (*index);
                classify_identifier_keyword(token);
                return;
            }

            (*index)++;
        }
    }

    if(isdigit(current))
    {
        (*index)++;

        while(1)
        {
            current = buffer[*index];

            if(!isdigit(current))
            {
                token->text.end = buffer + (*index);
                token->type = TOKEN_NUMBER;
                return;
            }

            (*index)++;
        }
    }

    if(current == '+')
    {
        (*index)++;

        token->text.end = token->text.begin + 1;
        token->type = TOKEN_PLUS;
        return;
    }

    if(current == '-')
    {
        (*index)++;
        token->text.end = token->text.begin + 1;
        token->type = TOKEN_MINUS;
        return;
    }

    if(current == '=')
    {
        (*index)++;
        current = buffer[*index];

        if(current == '=')
        {
            (*index)++;
            token->text.end = buffer + *index;
            token->type = TOKEN_EQUAL;
            return;
        }

        token->text.end = buffer + *index;
        token->type = TOKEN_ASSIGN;
        return;
    }

    if(current == '{')
    {
        (*index)++;
        token->text.end = buffer + *index;
        token->type = TOKEN_LBRACE;
        return;
    }

    if(current == '}')
    {
        (*index)++;
        token->text.end = buffer + *index;
        token->type = TOKEN_RBRACE;
        return;
    }

    if(current == ';')
    {
        (*index)++;
        token->text.end = buffer + *index;
        token->type = TOKEN_SEMICOLON;
        return;
    }

    if(current == '(')
    {
        (*index)++;
        token->text.end = buffer + *index;
        token->type = TOKEN_LPAREN;
        return;
    }

    if(current == ')')
    {
        (*index)++;
        token->text.end = buffer + *index;
        token->type = TOKEN_RPAREN;
        return;
    }

    token->text.end = buffer + *index;
    token->type = TOKEN_UNKNOWN;
    return;
}

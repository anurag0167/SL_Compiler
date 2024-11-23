#include "lexerf.h"

// Function to get the next token from the file
void getNextToken(FILE* file, Token* token)
{
    int c;

    while((c = fgetc(file)) != EOF)
    {
        // Skip whitespace
        if(isspace(c))
            continue;

        // Handle identifiers and keywords
        if(isalpha(c))
        {
            int len = 0;
            token->text[len++] = c;
            while(isalnum(c = fgetc(file)))
            {
                if(len < MAX_TOKEN_LEN - 1)
                {
                    token->text[len++] = c;
                }
            }
            ungetc(c, file);
            token->text[len] = '\0';

            // Keyword detection
            if(strcmp(token->text, "int") == 0)
            {
                token->type = TOKEN_INT;
            }
            else if(strcmp(token->text, "if") == 0)
            {
                token->type = TOKEN_IF;
            }
            else
            {
                token->type = TOKEN_IDENTIFIER;
            }
            return;
        }

        // Handle numbers
        if(isdigit(c))
        {
            int len = 0;
            token->text[len++] = c;
            while(isdigit(c = fgetc(file)))
            {
                if(len < MAX_TOKEN_LEN - 1)
                {
                    token->text[len++] = c;
                }
            }
            ungetc(c, file);
            token->text[len] = '\0';
            token->type = TOKEN_NUMBER;
            return;
        }

        // Handle operators and symbols
        switch(c)
        {
            case '=':
                token->type = TOKEN_ASSIGN;
                token->text[0] = '=';
                token->text[1] = '\0';
                return;
            case '+':
                token->type = TOKEN_PLUS;
                token->text[0] = '+';
                token->text[1] = '\0';
                return;
            case '-':
                token->type = TOKEN_MINUS;
                token->text[0] = '-';
                token->text[1] = '\0';
                return;
            case '{':
                token->type = TOKEN_LBRACE;
                token->text[0] = '{';
                token->text[1] = '\0';
                return;
            case '}':
                token->type = TOKEN_RBRACE;
                token->text[0] = '}';
                token->text[1] = '\0';
                return;
            case ';':
                token->type = TOKEN_SEMICOLON;
                token->text[0] = ';';
                token->text[1] = '\0';
                return;
            default:
                token->type = TOKEN_UNKNOWN;
                token->text[0] = c;
                token->text[1] = '\0';
                return;
        }
    }

    // End of file
    token->type = TOKEN_EOF;
    token->text[0] = '\0';
}

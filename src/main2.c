
#include <stdio.h>
// #include "lexerf.h"
#include <stdlib.h>
#include "lexerf2.h"

#include "types.h"
#include "token.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    // Open the source file
    FILE* file = fopen(argv[1], "r");
    if(!file)
    {
        perror("Failed to open file");
        return 1;
    }

    fseek(file, 0, SEEK_END);

    u64 file_size = ftell(file);
    printf("file_size: %lu\n", file_size);

    char* buffer = malloc(file_size);
    u64 index = 0;

    fseek(file, 0, SEEK_SET);

    char c;

    while((c = fgetc(file)) != EOF)
    {
        buffer[index++] = c;
    }

    buffer[index] = 0;

    fclose(file);


    token t;
    index = 0;

    while(index != file_size)
    {
        generate_next_token(buffer, &index, &t);
        printf("token{ type: %s, text: ", enum_token_type_to_string(t.type));
        print_string_view(t.text);
        printf("} \n");
    }
    //  printf("Tokenizing the input file '%s':\n\n", argv[1]);

    // Token token;

    // Tokenize the input file
    // do
    // {
    // getNextToken(file, &token);
    // printf("Token Type: %d, Text: %s\n", token.type, token.text);
    // printf("hello world");
    // }
    // while(token.type != TOKEN_EOF);

    // fclose(file);
    return 0;
}

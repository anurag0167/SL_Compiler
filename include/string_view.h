#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <stdio.h>
#include "types.h"

typedef struct
{
    c_str begin;
    c_str end;
} string_view;

#define MAKE_STRING_VIEW(char_array) { char_array, char_array + sizeof(char_array) - 1 }


int is_equal(string_view a, string_view b);
void print_string_view(string_view s);

#endif

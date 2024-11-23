#include "string_view.h"

void print_string_view(string_view s)
{
    while(s.begin != s.end)
    {
        char c = *s.begin;
        switch(c)
        {
            case '\n':
                printf("\\n");
                break;
            case '\v':
                printf("\\v");
                break;
            case '\t':
                printf("\\t");
                break;
            case '\r':
                printf("\\r");
                break;
            case '\f':
                printf("\\f");
                break;
            case '\\':
                printf("\\\\");
                break;
            default:
                if(c >= 32 && c <= 126) // Printable ASCII range
                    printf("%c", c);
                else
                    printf("\\x%02x", (unsigned char) c); // Non-printable, print as hex
                break;
        }
        s.begin++;
    }
}

int is_equal(string_view a, string_view b)
{
    while(a.begin != a.end && b.begin != b.end)
    {
        if(*(a.begin) != *(b.begin))
        {
            return 0;
        }

        a.begin++, b.begin++;
    }

    if(a.begin != a.end || b.begin != b.end)
    {
        return 0;
    }

    return 1;
}

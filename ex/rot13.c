#include <string.h>
#include <stdio.h>

int rot13(char *text)
{
    int i = 0;
    printf("%s\n", text);

    while (*(text + i) != 0)
    {
        if (109 < *(text + i) && *(text + i) < 123 || 77 < *(text + i) && *(text + i) < 91)
        {
            printf("%c", *(text + i) - 13);
        }
        if (96 < *(text + i) && *(text + i) < 110 || 64 < *(text + i) && *(text + i) < 78)
        {
            printf("%c", *(text + i) + 13);
        }
        i++;
    }
    printf("\n");
    return 0;
}
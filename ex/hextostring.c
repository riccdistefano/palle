#include <stdio.h>
#include <string.h>

int hex_to_string()
{
    int toconv;
    scanf("%x", &toconv);
    printf("%s\n", (char*)&toconv);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ip_to_int()
{
    unsigned char ip[4];
    int n = scanf("%hhu.%hhu.%hhu.%hhu", ip + 3, ip + 2, ip + 1, ip + 0);

    if(n != 4)
    {
        printf("Not a valid ip address\n");
    }
    else
    {
        printf("Ip: %u\n", *(unsigned int*)ip);
    }
    
    return 0;
}
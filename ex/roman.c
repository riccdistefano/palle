#include <string.h>
#include <stdio.h>

int roman(int num)
{
    int i = 0;

    while (num != 0)
    {
        if (num >= 900)
        {
            if (num >= 1000)
            {
                printf("M");
                num -= 1000;
                continue;
            }
            else
            {
                printf("CM");
                num -= 900;
                continue;
            }
        }
        if (num >= 400)
        {
            if (num >= 500)
            {
                printf("D");
                num -= 500;
                continue;
            }
            else
            {
                printf("CD");
                num -= 400;
                continue;
            }
        }
        if (num >= 90)
        {
            if (num >= 100)
            {
                printf("C");
                num -= 100;
                continue;
            }
            else
            {
                printf("XC");
                num -= 90;
                continue;
            }
        }
        if (num >= 40)
        {
            if (num >= 50)
            {
                printf("L");
                num -= 50;
                continue;
            }
            else
            {
                printf("XL");
                num -= 40;
                continue;
            }
        }
        if (num >= 9)
        {
            if (num >= 10)
            {
                printf("X");
                num -= 10;
                continue;
            }
            else
            {
                printf("IX");
                num -= 9;
                continue;
            }
        }
        if (num >= 4)
        {
            if (num >= 5)
            {
                printf("V");
                num -= 5;
                continue;
            }
            else
            {
                printf("IV");
                num -= 4;
                continue;
            }
        }
        printf("I");
        num -= 1;
        continue;
    }
    return 0;
}
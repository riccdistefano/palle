// #include <unistd.h>
// gcc main.c -o test && ./test
#include <stdio.h>
#include <string.h>

void sh_echo(char *cmd) {}
void sh_cd(char *cmd) {}
void sh_mkdir() {}

void sh_rmdir()
{
    // rmdir(char*)
}

void sh_cat() {}
void sh_ls() {}
void sh_touch() {}

void sh_help(char *args)
{
    printf("hai fatto help\n");
}

void sh_clear() {}
void sh_rm() {}

int main()
{
    char kin[100];
    char cmd[10];
    char *args;

    for (;;)
    {
        fputs("sexshell ? ", stdout);
        fgets(kin, sizeof(kin), stdin);
        args = memchr(kin, ' ', sizeof(kin));
        if (args != NULL)
        {
            *args = 0;
            args++;
        }

        // debug
        printf("Command: %s\n", kin);
        if (args != NULL)
        {
            printf("Arguments: %s\n", args);
        }

        // comands
        if (memcmp(kin, "stop", 4) == 0)
        {
            return 0;
        }
        else if (memcmp(kin, "help", 4) == 0)
        {
            sh_help(args);
        }
    }
}
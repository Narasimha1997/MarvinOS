#include "startup.h"
#include "input/stdin.h"
#include "cshell/cshell.h"
#include "display.h"
#include "stdio.h"
#include "string.h"

void delegate_to_console()
{
    printf(STARTUP_MESSAGE);
    while (1)
    {
        printf(SHELL_BEGIN_OPERATOR);

        char input[40];

        kb_read_line(input);

        if (strcmp(CSHELL_LOGIN_COMMAND, input) == 0)
        {
           init();
           *input = 0;
        }
        else
        {
            printf("Invalid command\n");
        }
    }
}
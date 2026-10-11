#include "headers.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[MAX_STRING_LENGTH];
    bool done = false;

    while (!done)
    {
        if (read_string(string, MAX_STRING_LENGTH))
        {
            printf("Length of the string is '%zu'\n", strlen(string));
            done = strcmp(string, STOP_WORD) == 0;
        }
        else
        {
            done = true;
        }
    }

    return 0;
}

bool read_string(char *string, const int size)
{
    printf("Enter a string (or type 'stop' to quit): ");
    if (fgets(string, size, stdin) == NULL)
    {
        return false;
    }

    const size_t string_length = strlen(string);
    if (string[string_length - 1] == '\n')
    {
        string[string_length - 1] = '\0';
    }
    else
    {
        clear_input();
    }
    return true;
}

void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

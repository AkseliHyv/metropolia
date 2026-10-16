#include "headers.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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

    return EXIT_SUCCESS;
}

// Reads input from stdin into 'string', which holds 'size' amount of characters. 
// Removes newline and empties buffer. Returns false if reading failed.
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
        while ((getchar()) != '\n')
        {
        }
    }
    return true;
}

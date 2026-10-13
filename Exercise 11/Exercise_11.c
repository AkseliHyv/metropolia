#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char string[MAX_STRING_LENGTH];
    char replace_pair[REPLACE_PAIR_BUFLENGTH];

    printf("Enter a string: ");
    if (!read_string(string, MAX_STRING_LENGTH))
    {
        return EXIT_FAILURE;
    }

    printf("Enter a replacement pair (eg. 'ae' to replace every 'a' with 'e'): ");
    if (!read_string(replace_pair, REPLACE_PAIR_BUFLENGTH))
    {
        return EXIT_FAILURE;
    }

    const int amount_changed = replace_char(string, replace_pair);
    if (amount_changed > 0)
    {
        printf("Amount of letters changed: '%d'\nNew string: '%s'\n", amount_changed, string);
    }
    else
    {
        printf("String was not modified.\n");
    }

    return EXIT_SUCCESS;
}

// Reads input from stdin into 'string', which can hold 'size' characters including the '\0'.
// Removes newline, and clears extra characters from the buffer. Returns false if nothing could be
// read.
bool read_string(char *string, const int size)
{
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

// Replaces every occurrence of the first character of 'replace_pair' in 'string' with its
// second character. Returns the amount of characters replaced, or 0 if 'replace_pair'
// is not exactly two characters long.
int replace_char(char *string, const char *replace_pair)
{
    if (strlen(replace_pair) != REPLACE_PAIR_LENGTH)
    {
        return 0;
    }

    int amount_changed = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == replace_pair[0])
        {
            string[i] = replace_pair[1];
            amount_changed++;
        }
    }
    return amount_changed;
}

#include "headers.h"
#include <ctype.h>
#include <string.h>

// Reads input from stdin into 'string', which holds 'size' amount of characters.
// Removes newline and empties buffer. Returns false if reading failed.
bool get_string(char *string, const int size)
{
    if (fgets(string, size, stdin))
    {
        clear_buffer(string);
        trim_whitespace(string);
        return true;
    }
    return false;
}

// Clears the rest of the line from stdin if 'string' did not fit the whole line.
void clear_buffer(char *string)
{
    size_t length = strlen(string);
    if (string[length - 1] != '\n')
    {
        while (getchar() != '\n')
        {
        }
    }
}

// Removes all whitespace from beginning and end of 'string'.
void trim_whitespace(char *string)
{
    size_t length = strlen(string);

    for (int c = length - 1; c >= 0 && isspace((unsigned char)string[c]); c--)
    {
        string[c] = '\0';
    }

    while (isspace((unsigned char)string[0]))
    {
        for (int c = 0; string[c] != '\0'; c++)
        {
            string[c] = string[c + 1];
        }
    }
}

// Checks 'string' for any occurrences of 'character'.
bool char_in_string(const char *string, char character)
{
    for (int c = 0; string[c] != '\0'; c++)
    {
        if (string[c] == character)
        {
            return true;
        }
    }

    return false;
}
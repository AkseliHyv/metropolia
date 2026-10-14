#include "headers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Reads input from stdin into 'string', which can hold 'size' characters including the '\0'.
// Clears extra characters from the buffer and trims whitespace. Returns false if nothing could
// be read.
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

// Clears the rest of the line from stdin if 'string' did not fit the whole line, meaning it
// does not end with a newline.
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

// Removes all whitespace, including the newline, from the beginning and end of 'string'.
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

// Reads 'string' for any occurrences of 'character'. Returns true if found, false if not.
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
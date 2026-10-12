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

/*
Write a function called replace_char that takes two strings as parameters and returns an integer.
The first string is the string to modify and the second is a string containing two characters. The
function finds every occurrence of the first character of the second string and replaces them with
the second character. For example:
char text[80] = “I am so tired of Python. C is much better language”;
count = replace_char(test, “e3”);
The call above will find every occurrence of ‘e’ and replace it with ‘3’.
Prototype of the function:
int replace_char(char *str, const char *repl);
The function returns the number of characters replaced. The return value can be zero if no
characters were found or if the second string does not contain two characters.
Write a program that asks user to enter both strings and then calls replace_char. The program prints
both return value and the modified string if the return value is greater than zero. If the return
value is zero program prints “String was not modified”.
*/
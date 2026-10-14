#include "debug.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 5
#define MAX_DEBUG_LEVEL 4

static bool read_string(char *string, const int size);
static bool get_integer(const char *string, int *number);
static void generate_messages(const int max_debug_level);

int main(void)
{
    srand(time(NULL));
    char input[MAX_STRING_LENGTH] = "";
    int debug_level = 0;

    while (strcmp(input, "end"))
    {
        printf("Enter the debug level or 'end' to end: ");
        if (!read_string(input, MAX_STRING_LENGTH))
        {
            fprintf(stderr, "Could not read user input.\n");
            return EXIT_FAILURE;
        }

        if (get_integer(input, &debug_level))
        {
            if (debug_level > MAX_DEBUG_LEVEL)
            {
                fprintf(stderr, "Highest allowed debug level is %d.\n", MAX_DEBUG_LEVEL);
            }
            else if (debug_level < 0)
            {
                fprintf(stderr, "Debug level must be atleast 0.\n");
            }
            else
            {
                set_debug_level(debug_level);
                generate_messages(MAX_DEBUG_LEVEL);
            }
        }
    }

    return EXIT_SUCCESS;
}

// Reads input from stdin into 'string', which holds 'size' amount of characters.
// Removes newline and empties buffer. Returns false if reading failed.
static bool read_string(char *string, const int size)
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

// Checks if 'string' contains an integer number, and assigns it to 'number' if it does.
// Returns false if number is not a valid integer, or the string contains text.
static bool get_integer(const char *string, int *number)
{
    long int temp_num;
    char extra;
    if (sscanf(string, "%ld%c", &temp_num, &extra) != 1)
    {
        if (strcmp(string, "end"))
        {
            printf("Invalid input.\n");
        }
        return false;
    }

    if (temp_num > INT_MAX || temp_num < INT_MIN)
    {
        printf("Number is not a valid integer.\n");
        return false;
    }
    *number = temp_num;
    return true;
}

static void generate_messages(int max_debug_level)
{
    for (int i = 1; i <= 5; i++)
    {
        int debug_level = rand() % (max_debug_level + 1);
        dprintf(debug_level, "DEBUG MESSAGE Nr.%d\n", i);
    }
}

/*
Implement a program that consists of three files: main.c, debug.c and debug.h.

Debug.c contains two functions:

    •   set_debug_level
    •   dprintf

Set_debug_level takes one integer parameter (debug level) and stores the value in a static variable
that is accessible to all functions in the file but not globally.
        void set_debug_level(int debug_level);

Dprintf works like printf but there is an extra integer parameter (debug level) that comes before
the usual printf parameters: int dprintf(int debug_level, const char *fmt, …);

If dprintf debug level is lower or equal to the stored debug level then function prints the output
to stderr prefixed with [DBGx] , where x is the debug level given as parameter. Otherwise, function
prints nothing and returns zero.

Write a program that asks user to enter debug level in range 0 – 4 and calls set_debug_level with
the number. Then program prints five messages with a random debug level in range 0 – 4 using
dprintf. Get a new random debug level for each message. The messages must have at least one
numerical argument that is a running index that starts from one. First message has index 1,second
message 2, etc
*/

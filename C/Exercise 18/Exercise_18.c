#include "headers.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    char input[MAX_INPUT_SIZE];
    int number = 0;

    while (number >= 0)
    {
        printf("Enter number between 0-%d, or a negative number to stop: ", HIGHEST_NUM);
        if (!read_string(input, MAX_INPUT_SIZE))
        {
            fprintf(stderr, "Could not read user input.\n");
            return EXIT_FAILURE;
        }

        if (get_integer(input, &number))
        {
            if (number > HIGHEST_NUM)
            {
                fprintf(stderr, "Number %d is too big, highest allowed number is %d.\n", number,
                        HIGHEST_NUM);
            }
            else if (number >= 0)
            {
                print_hex(number);
            }
        }
    }

    return EXIT_SUCCESS;
}

// Reads input from stdin into 'string', which holds 'size' amount of characters.
// Removes newline and empties buffer. Returns false if reading failed.
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

// Checks if 'string' contains an integer number, and assigns it to 'number' if it does.
// Returns false if number is not a valid integer, or the string contains text.
bool get_integer(const char *string, int *number)
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

// Generates random number, moves bits to right by 'num', clears bits other than 0-5, and prints to
// stdout.
void print_hex(const int num)
{
    int rand_num = rand();
    printf("0x%x\n", rand_num);

    int result = rand_num >> num;
    result = result & BIT_MASK;
    printf("0x%02x\n", result);
}

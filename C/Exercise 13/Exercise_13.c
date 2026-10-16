#include "headers.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char file_name[MAX_FILE_NAME_SIZE];

    printf("Enter a file to search for: ");
    if (!read_string(file_name, MAX_FILE_NAME_SIZE))
    {
        fprintf(stderr, "Could not read a file name\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(file_name, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s\n", file_name);
        return EXIT_FAILURE;
    }

    read_file(file, file_name);
    fclose(file);

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

// Reads integers from 'file' until no more are found. Prints amount of integers
// found, along with the highest and smallest integer found.
void read_file(FILE *file, const char *file_name)
{
    int numbers_found = 0;
    int highest_number = INT_MIN;
    int smallest_number = INT_MAX;

    int value;
    while (fscanf(file, "%d", &value) == 1)
    {
        if (value > highest_number)
        {
            highest_number = value;
        }
        if (value < smallest_number)
        {
            smallest_number = value;
        }
        numbers_found++;
    }

    printf("Results of file %s:\n", file_name);
    if (numbers_found == 0)
    {
        printf("No numbers were found\n");
    }
    else
    {
        printf("\nHighest number: %d\nSmallest number: %d\nNumbers in total: %d\n", 
            highest_number, smallest_number, numbers_found);
    }
}

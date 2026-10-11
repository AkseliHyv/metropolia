#include "headers.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
    char file_name[MAX_FILE_NAME_SIZE];

    read_string(file_name, MAX_FILE_NAME_SIZE, "Enter a file to search for: ");
    FILE *file = fopen(file_name, "r");

    if (file != NULL)
    {
        read_file(file, file_name);
        fclose(file);
    }
    else
    {
        fprintf(stderr, "Could not open file %s\n", file_name);
    }

    return 0;
}

bool read_string(char *string, const int size, const char *prompt)
{
    printf("%s", prompt);
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

    print_results(file_name, numbers_found, highest_number, smallest_number);
}

void print_results(const char *file_name, const int numbers_found, const int highest_number,
                   const int smallest_number)
{
    printf("Results of file %s:\n", file_name);
    if (numbers_found == 0)
    {
        printf("No numbers were found\n");
    }
    else
    {
        printf("\nHighest number: %d\nSmallest number: %d\nNumbers in total: %d\n", highest_number,
               smallest_number, numbers_found);
    }
}

/*
Write a program that asks user to enter a filename. Then program tries to open the file in textmode
for reading. If opening the file fails the program prints an error message with the filename to
stderr and then exits. If the file is opened the program starts reading integers from the file until
reading fails or the file ends. When reading stops the program prints the count of numbers and the
lowest and highest number that was read from the file. Then program closes the file.

For testing make a few text files with integers using your favourite text editor.
*/

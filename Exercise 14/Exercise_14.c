#include "headers.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char file_name[MAX_FILE_NAME_SIZE];
    char lines[MAX_LINE_AMOUNT][MAX_LINE_LENGTH];
    int line_count = 0;

    printf("Enter a file to search for: ");
    if (!read_string(file_name, MAX_FILE_NAME_SIZE))
    {
        fprintf(stderr, "Could not read a file name\n");
        return EXIT_FAILURE;
    }

    if (!read_file_lines(file_name, MAX_LINE_LENGTH, MAX_LINE_AMOUNT, lines, &line_count))
    {
        fprintf(stderr, "Could not open file %s\n", file_name);
        return EXIT_FAILURE;
    }

    to_upper(MAX_LINE_LENGTH, lines, line_count);

    if (!update_file(file_name, MAX_LINE_LENGTH, lines, line_count))
    {
        fprintf(stderr, "Could not open file %s, it was likely deleted mid-process.\n", file_name);
        return EXIT_FAILURE;
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

// Opens file 'file_name' and stores all of its lines as strings into a multidimensional array
// 'lines'. Returns false if the file could not be opened.
bool read_file_lines(const char *file_name, const int line_length, const int max_line_amount,
                     char lines[][line_length], int *line_count)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        return false;
    }

    while (!feof(file) && *line_count < max_line_amount)
    {
        if (fgets(lines[*line_count], line_length, file) != NULL)
        {
            (*line_count)++;
        }
    }

    fclose(file);
    return true;
}

// Reads through multidimensional array 'lines', and converts all characters to upper case.
void to_upper(const int line_length, char lines[][line_length], const int line_count)
{
    for (int l = 0; l < line_count; l++)
    {
        for (int c = 0; lines[l][c] != '\0'; c++)
        {
            lines[l][c] = toupper(lines[l][c]);
        }
    }
}

// Opens file 'file_name' for writing, and replaces its contents with the lines in 'lines'.
// Returns false if the file could not be opened.
bool update_file(const char *file_name, const int line_length, char lines[][line_length],
                 const int line_count)
{
    FILE *file = fopen(file_name, "w");
    if (file == NULL)
    {
        return false;
    }

    for (int l = 0; l < line_count; l++)
    {
        fputs(lines[l], file);
    }

    fclose(file);
    return true;
}

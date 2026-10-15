#include "headers.h"
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

    if (!check_file(file_name, MAX_LINE_LENGTH))
    {
        fprintf(stderr, "Could not open file %s\n", file_name);
        return EXIT_FAILURE;
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

// Checks file 'file_name' line by line, returning [OK] if checksum is fine, else [FAIL]. Skips
// invalid lines.
bool check_file(const char *file_name, const int line_length)
{
    char line[line_length];

    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        return false;
    }

    while (fgets(line, line_length, file) != NULL)
    {
        char data[line_length];
        unsigned int checksum;

        if (sscanf(line, "$%255[^*]*%x", data, &checksum) == 2)
        {
            if (calculate_checksum(data) == checksum)
            {
                fprintf(stdout, "[ OK ] ");
            }
            else
            {
                fprintf(stdout, "[FAIL] ");
            }

            fprintf(stdout, "%s", line);
        }
    }

    fclose(file);
    return true;
}

// Calculates checksum by XORing all characters in 'data'.
unsigned int calculate_checksum(const char *data)
{
    unsigned int final_hex = 0;
    for (int c = 0; data[c] != '\0'; c++)
    {
        final_hex = final_hex ^ data[c];
    }
    return final_hex;
}

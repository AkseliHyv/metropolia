#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char file_name[MAX_FILE_NAME_SIZE];
    menu_item items[MAX_ITEM_AMOUNT];
    int item_count = 0;

    printf("Enter a file to search for: ");
    if (!read_string(file_name, MAX_FILE_NAME_SIZE))
    {
        fprintf(stderr, "Could not read a file name\n");
        return EXIT_FAILURE;
    }

    if (!read_file_items(file_name, MAX_ITEM_AMOUNT, items, &item_count))
    {
        fprintf(stderr, "Could not open file %s\n", file_name);
        return EXIT_FAILURE;
    }

    print_items(items, item_count);

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

// Opens file 'file_name' and stores all of its items into menu_item struct array 'items'.
// Returns false if the file could not be opened.
bool read_file_items(const char *file_name, const int max_item_amount, menu_item items[],
                     int *item_count)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        return false;
    }

    while (!feof(file) && *item_count < max_item_amount)
    {
        int stored =
            fscanf(file, " %49[^;\n]; %lf", items[*item_count].name, &items[*item_count].price);
        if (stored >= 1)
        {
            if (stored == 1)
            {
                items[*item_count].price = NO_PRICE_VALUE;
            }
            (*item_count)++;
        }
    }

    fclose(file);
    return true;
}

// Prints every item in menu_item struct array 'items' into stdout.
void print_items(const menu_item items[], const int item_count)
{
    for (int i = 0; i < item_count; i++)
    {
        if (items[i].price == NO_PRICE_VALUE)
        {
            printf("%8s %s\n", "", items[i].name);
        }
        else
        {
            printf("%8.2lf %s\n", items[i].price, items[i].name);
        }
    }
}

/*
Write a program that reads data from a text file into an array of structures. The size of the array
is 40 elements.

The structure is defined as:
        typedef struct menu_item_ {
              char name[50];
              double price;
        } menu_item;

The program asks user to enter a filename. Then program tries to open the file in textmode for
reading. If opening the file fails the program prints an error message with the filename to stderr
and then exits.

Program reads data from the text file into the array until end of file or the array is full. Each
row of the file contains data of one structure. The members are separated by semicolons. For
example: Mega double burger with bacon and cheese; 23.50 Belgian style fries with vegan mayo; 5.60

When reading ends the program closes the file and prints the content of the array in formatted
columns. Price is printed into a field of eight characters with two decimals precision followed by
the name of the item. Unused elements are not printed.
*/

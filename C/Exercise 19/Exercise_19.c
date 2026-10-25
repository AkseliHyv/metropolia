#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char file_name[MAX_STRING_SIZE];
    menu_item items[MAX_ITEM_AMOUNT];
    int item_count = 0;
    char sorting[MAX_STRING_SIZE];
    int (*cmp_func)(const void *, const void *);

    printf("Enter a file to search for: ");
    if (!read_string(file_name, MAX_STRING_SIZE))
    {
        fprintf(stderr, "Could not read a file name\n");
        return EXIT_FAILURE;
    }

    if (!read_file_items(file_name, MAX_ITEM_AMOUNT, items, &item_count))
    {
        fprintf(stderr, "Could not open file %s\n", file_name);
        return EXIT_FAILURE;
    }

    printf("Sort by (price/name): ");
    if (!read_string(sorting, MAX_STRING_SIZE))
    {
        fprintf(stderr, "Could not read user input.\n");
        return EXIT_FAILURE;
    }

    if (!get_cmp_func(&cmp_func, sorting))
    {
        fprintf(stderr, "Invalid sorting operation.\n");
        return EXIT_FAILURE;
    }

    qsort(items, item_count, sizeof(menu_item), cmp_func);
    print_items(items, item_count);
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

// Opens file 'file_name' and stores all of its items into menu_item struct array 'items'.
// Returns false if file could not be opened.
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

// Stores the comparison function to be used in 'cmp_func' according to specified 'sorting' method.
// Returns false if sorting method was invalid.
bool get_cmp_func(int (**cmp_func)(const void *, const void *), char *sorting)
{
    if (!strcmp(sorting, "price"))
    {
        *cmp_func = cmp_price;
        return true;
    }
    else if (!strcmp(sorting, "name"))
    {
        *cmp_func = cmp_name;
        return true;
    }
    return false;
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

// Returns 1 if item 'a' is more expensive than 'b', -1 if 'b' is more expensive than 'a', 0 if they
// are the same price.
int cmp_price(const void *a, const void *b)
{
    menu_item ca = *(const menu_item *)a;
    menu_item cb = *(const menu_item *)b;

    if (ca.price > cb.price)
    {
        return 1;
    }
    else if (ca.price < cb.price)
    {
        return -1;
    }
    return 0;
}

// Uses the nature of strcmp to check whether 'a' or 'b' are alphabetically first. Returns 1 if item
// 'a' is alphabetically before 'b', -1 if 'b' is alphabetically before 'a', 0 if they are the same
// string.
int cmp_name(const void *a, const void *b)
{
    menu_item ca = *(const menu_item *)a;
    menu_item cb = *(const menu_item *)b;

    return strcmp(ca.name, cb.name);
}

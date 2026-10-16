#ifndef HEADERS_H
#define HEADERS_H
#include <limits.h>
#include <stdbool.h>

#define MAX_FILE_NAME_SIZE 20
#define MAX_ITEM_AMOUNT 40
#define NO_PRICE_VALUE INT_MIN

typedef struct menu_item_
{
    char name[50];
    double price;
} menu_item;

bool read_string(char *string, const int size);
bool read_file_items(const char *file_name, const int max_item_amount, menu_item items[],
                     int *item_count);
void print_items(const menu_item items[], const int item_count);

#endif // HEADERS_H

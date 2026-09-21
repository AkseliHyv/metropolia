#include "headers.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    srand(time(NULL));
    unsigned int numbers[ARRAY_SIZE];
    fill_array(numbers, ARRAY_SIZE);
    print_array(numbers);

    int input;
    do
    {
        input = get_input();
        handle_input(numbers, input);
    } while (input != 0);
    return 0;
}

void fill_array(unsigned int *array, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = 1 + rand() % 20;
    }
    array[size - 1] = 0;
}

void print_array(const unsigned int *array)
{
    int i = 0;
    while (array[i] != 0)
    {
        printf("%u\n", array[i]);
        i++;
    }
    printf("%u\n", array[i]);
}

int get_input(void)
{
    int input;
    bool valid = false;
    do
    {
        printf("Enter a number to search for or enter 0 to quit:\n");
        valid = scanf("%d", &input);
        while (getchar() != '\n') {}
    } while (!valid);
    return input;
}

void handle_input(const unsigned int *array, int input)
{
    if (input != 0)
    {
        const int index = find_first(array, input);
        if (index != -1)
        {
            printf("Number found at index %d\n", index);
        }
        else
        {
            printf("Number not found.\n");
        }
    }
}

int find_first(const unsigned int *array, const unsigned int what)
{
    int i = 0;
    while (array[i] != 0)
    {
        if (array[i] == what)
        {
            return i;
        }
        i++;
    }
    return -1;
}
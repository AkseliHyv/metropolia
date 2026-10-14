#include "headers.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        numbers[i] = rand() % RAND_ROOF;
    }
    print_numbers(numbers, ARRAY_SIZE);
    return 0;
}

void print_numbers(const int *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%8d\n", array[i]);
    }
}
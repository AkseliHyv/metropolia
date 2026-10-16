#include <stdio.h>
#include <stdbool.h>
#include "headers.h"

int main(void) {
    int number;
    float number_total = 0;
    int numbers_added = 0;

    do
    {
        number = read_integer();
        if (number > 0)
        {
            number_total += (float)number;
            numbers_added++;
        }
    } while (number >= 0);

    average(number_total, numbers_added);
    return 0;
}

int read_integer(void) {
    bool valid;
    int number;
    do
    {
        printf("Enter positive numbers or negative to stop: ");
        valid = scanf("%d", &number) && number != 0;
        if (!valid)
        {
            printf("Invalid input.\n");
        }
        while (getchar() != '\n') {}
    } while (!valid);
    return number;
}

void average(const float number_total, const int numbers_added)
{
    if (numbers_added > 0)
    {
        const float average = number_total / (float)numbers_added;
        printf("You entered %d positive numbers. The average is: %.3f.\n", numbers_added, average);
    }
    else
    {
        printf("You did not enter any positive numbers.\n");
    }
}
#include "headers.h"
#include <stdio.h>

int main(void)
{
    int guess;
    int incorrect_values = 0;
    while (incorrect_values < 3)
    {

        if (read_positive(&guess))
        {
            printf("You guessed wrong, I have %d€!\n", 
                guess * MULTIPLIER + ADDITIVE);
        }
        else 
        {
            printf("Incorrect input.\n");
            incorrect_values++;
        }
    }
    printf("I give up. See ya.\n");
    return 1;
    
}

bool read_positive(int *value)
{
    int input;
    printf("Try to guess how much money I have!\nEnter a positive number: ");
    if (scanf("%d", &input))
    {
        if (input > 0)
        {
            while (getchar() != '\n') {}
            *value = input;
            return true;
        }
    }
    while (getchar() != '\n') {}
    return false;
}
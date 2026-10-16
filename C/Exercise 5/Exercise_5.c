#include <stdio.h>
#include <stdbool.h>
#include "headers.h"

int main(void)
{
    printf("Hello... I want to play a game.\nYou need to defeat me at least once in a game of dice once to win.\nLet the game begin.\n");
    for (int i = 0; i < ROUNDS; i++)
    {
        const int result = read_range(LOW, HIGH);
        if (result != HIGH)
        {
            printf("I got %d. I win.\n", result + 1);
        }
        else
        {
            printf("I got %d. It is a tie.\n", result);
        }
    }
    printf("Game over.\n");
    return 0;
}

int read_range(const int low, const int high) {
    bool valid;
    int number;
    do
    {
        printf("Roll a die and enter your result.\nEnter a number between %d and %d: ", low, high);
        valid = scanf("%d", &number);
        if (!valid)
        {
            printf("Invalid input.\n");
        }
        else if (number < low || number > high)
        {
            printf("Number is not within the specified range.\n");
            valid = false;
        }
        while (getchar() != '\n') {}
    } while (!valid);
    return number;
}
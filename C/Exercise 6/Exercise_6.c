#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int main(void)
{
    srand(time(NULL));
    int selection;
    do
    {
        selection = handle_menu();
        if (selection != -1 && selection != 3)
        {
            roll_die(selection);
        }
    } while (selection != 3);
    return 0;
}

int handle_menu(void) {
    int selection;
    printf("1.) Roll D6\n2.) Roll D10\n3.) Quit\n");
    const bool valid = scanf("%d", &selection);
    while (getchar() != '\n') {}
    if (!valid)
    {
        printf("Please enter your selection as a number.\n");
        return -1;
    }
    if (selection < 1 || selection > 3)
    {
        printf("Number is not within the specified options.\n");
        return -1;
    }
    return selection;
}

void roll_die(const int selection) {
    int roll;
    switch (selection)
    {
        case 1:
            roll = rand() % 6 + 1;
            break;
        case 2:
            roll = rand() % 10 + 1;
            break;
        default:
            printf("Invalid selection.\n");
            return;
    }
    printf("You rolled %d.\n", roll);
}
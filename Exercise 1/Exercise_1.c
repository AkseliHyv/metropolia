#include <stdbool.h>
#include <stdio.h>

float busPrice, taxiPrice, balance;

void init(void) {
    bool passed;
    do { // Stay in loop till scanf successfully 
        printf("Enter price of bus ticket: ");
        passed = scanf("%f", &busPrice) == 1 && busPrice >= 0;
        while (getchar() != '\n'); // Clear everything left over from buffer after the scan
    } while (!passed);
    do {
        printf("Enter price of taxi: ");
        passed = scanf("%f", &taxiPrice) == 1 && taxiPrice >= 0;
        while (getchar() != '\n');
    } while (!passed);
    do {
        printf("Enter balance: ");
        passed = scanf("%f", &balance) == 1 && balance >= 0;
        while (getchar() != '\n');
    } while (!passed);
}

int getTravelMethod(void) {
    bool passed;
    int option;
    do {
        printf("How do you want to travel\n 1.) Bus (%.2f€)\n 2.) Taxi (%.2f€)\nEnter option: ",
            busPrice, taxiPrice);
        passed = scanf("%d", &option);
        while (getchar() != '\n');
    } while (!passed);
    return option;
}

void travel(int option) {
    switch (option) {
        case 1:
            if (busPrice > balance) printf("You can't afford the ticket.\n");
            else {
                printf("You traveled by bus.\n");
                balance -= busPrice;
            }
            break;
        case 2:
            if (taxiPrice > balance) printf("You can't afford the ticket.\n");
            else {
                printf("You traveled by taxi.\n");
                balance -= taxiPrice;
            }
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    printf("You have %.2f€ left.\n", balance);
}

int main(void) {
    init();
    while (balance >= busPrice || balance >= taxiPrice) {
        travel(getTravelMethod());
    }
    printf("Take a hike brokie.\n");
}
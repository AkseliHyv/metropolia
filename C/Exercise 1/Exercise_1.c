#include <stdbool.h>
#include <stdio.h>

float bus_price, taxi_price, balance;

void init(void) {
    bool passed;
    do { // Stay in loop till scanf successfully 
        printf("Enter price of bus ticket: ");
        passed = scanf("%f", &bus_price) == 1 && bus_price >= 0;
        while (getchar() != '\n'); // Clear everything left over from buffer after the scan
    } while (!passed);
    do {
        printf("Enter price of taxi: ");
        passed = scanf("%f", &taxi_price) == 1 && taxi_price >= 0;
        while (getchar() != '\n');
    } while (!passed);
    do {
        printf("Enter balance: ");
        passed = scanf("%f", &balance) == 1 && balance >= 0;
        while (getchar() != '\n');
    } while (!passed);
}

int get_travel_method(void) {
    bool passed;
    int option;
    do {
        printf("How do you want to travel\n 1.) Bus (%.2f€)\n 2.) Taxi (%.2f€)\nEnter option: ",
            bus_price, taxi_price);
        passed = scanf("%d", &option);
        while (getchar() != '\n');
    } while (!passed);
    return option;
}

void travel(int option) {
    switch (option) {
        case 1:
            if (bus_price > balance) printf("You can't afford the ticket.\n");
            else {
                printf("You traveled by bus.\n");
                balance -= bus_price;
            }
            break;
        case 2:
            if (taxi_price > balance) printf("You can't afford the ticket.\n");
            else {
                printf("You traveled by taxi.\n");
                balance -= taxi_price;
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
    while (balance >= bus_price || balance >= taxi_price) {
        travel(get_travel_method());
    }
    printf("Take a hike brokie.\n");
}
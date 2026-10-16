#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char user_option[MAX_OPTION_SIZE] = "";

    print_splash();
    while (strcmp(user_option, QUIT_OPTION))
    {
        print_menu();

        printf("Enter option: ");
        if (!get_string(user_option, MAX_OPTION_SIZE))
        {
            fprintf(stderr, "\nThere was an issue in retrieving user input.\nPlease relaunch the "
                            "program and try again.\n");
            return EXIT_FAILURE;
        }
        else if (strcmp(user_option, QUIT_OPTION))
        {
            handle_menu_selection(user_option);
        }
    }

    return EXIT_SUCCESS;
}

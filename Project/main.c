#include "headers.h"
#include "string_helpers.c"
#include "game_functions.c"
#include <string.h>
#include <stdio.h>

int main(void) {
    bool quit_pending = false;
    char user_option[MAX_OPTION_SIZE];

    print_splash();
    while (!quit_pending) {
        print_menu();
        get_string("Enter option: ", user_option, MAX_OPTION_SIZE);

        if (strcmp(user_option, QUIT_OPTION) == 0) {
            quit_pending = true;
        }
        else {
            handle_menu_selection(user_option);
        }
    };
    return 0;
}

void print_splash(void) {

}

void print_menu(void) {
    printf("'%s': Search for existing games\n'%s': Add a new game\n'%s': Quit the launcher\n",
        SEARCH_OPTION, ADD_OPTION, QUIT_OPTION);
}

void handle_menu_selection(const char *user_selection) {
    if (strcmp(user_selection, SEARCH_OPTION) == 0) {
        search_game();
    }
    else if (strcmp(user_selection, ADD_OPTION) == 0) {
        add_game();
    }
    else {
        printf("Invalid option.\n");
    }
}

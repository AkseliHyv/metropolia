#include "headers.h"
#include <stdio.h>
#include <string.h>

// Prints the splash screen into stdout when the launcher starts.
void print_splash(void) {}

// Prints the available menu options and what each of them does into stdout.
void print_menu(void)
{
    printf("'%s': Search for existing games\n'%s': Add a new game\n'%s': Quit the launcher\n",
           SEARCH_OPTION, ADD_OPTION, QUIT_OPTION);
}

// Runs the action matching 'user_selection'. Prints an error if it is not a valid option.
void handle_menu_selection(const char *user_selection)
{
    if (strcmp(user_selection, SEARCH_OPTION) == 0)
    {
        search_game();
    }
    else if (strcmp(user_selection, ADD_OPTION) == 0)
    {
        add_game();
    }
    else
    {
        printf("Invalid option.\n");
    }
}

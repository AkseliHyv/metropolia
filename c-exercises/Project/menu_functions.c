#include "headers.h"
#include <string.h>

// Prints the launcher's splash screen. It looks hideous thanks to clang-format.
void print_splash(void)
{
    const char *splash_ascii =
        "    _    _  ______  _____ _        _   _   _ _   _  ____ _   _ _____ ____  \n   / \\  | "
        "|/ / ___|| ____| |      / \\ | | | | \\ | |/ ___| | | | ____|  _ \\ \n  / _ \\ | ' /\\___ "
        "\\|  _| | |     / _ \\| | | |  \\| | |   | |_| |  _| | |_) |\n / ___ \\| . \\ ___) | "
        "|___| |___ / ___ \\ |_| | |\\  | |___|  _  | |___|  _ < \n/_/   "
        "\\_\\_|\\_\\____/|_____|_____/_/   \\_\\___/|_| \\_|\\____|_| |_|_____|_| \\_\\ ";
    printf("%s\n\n", splash_ascii);
}

// Prints the menu into stdout.
void print_menu(void)
{
    printf("'%s': Search for existing games\n'%s': Add a new game\n'%s': Quit the launcher\n",
           SEARCH_OPTION, ADD_OPTION, QUIT_OPTION);
}

// Handles the user's menu selection 'user_selection'.
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
        fprintf(stderr, "Invalid option.\n");
    }
}

#ifndef MENU_FUNCTIONS_H
#define MENU_FUNCTIONS_H

#define SEARCH_OPTION "search"
#define ADD_OPTION "add"
#define QUIT_OPTION "quit"

void print_splash(void);
void print_menu(void);
void handle_menu_selection(const char *user_selection);

#endif // MENU_FUNCTIONS_H

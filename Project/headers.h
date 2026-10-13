#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

typedef struct game_metadata game;

void print_splash(void);
void print_menu(void);
void handle_menu_selection(const char *user_selection);

void search_game();

void add_game();
bool set_name(game *game);
bool set_genres(game *game);
bool set_image_path(game *game);

bool get_string(const char *prompt, char *string, int size);
void parse_string(char *string);

#define SEARCH_OPTION "search"
#define CANCEL_OPTION "cancel"
#define ADD_OPTION "add"
#define QUIT_OPTION "quit"
#define END_OPTION "end"

#define MAX_OPTION_SIZE 7
#define EXTRA_BUFFER 2 // extra char for detecting going over + space for \0
#define MAX_THUMBNAIL_PATH_LENGTH (50 + EXTRA_BUFFER)
#define MAX_GAME_NAME_SIZE (25 + EXTRA_BUFFER)
#define MAX_GENRE_NAME_SIZE (15 + EXTRA_BUFFER)
#define MAX_GENRE_AMOUNT 10
#define MAX_PROMPT_SIZE 70

#endif // HEADERS_H

#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

#define SEARCH_OPTION "search"
#define CANCEL_OPTION "cancel"
#define ALL_OPTION "all"
#define ADD_OPTION "add"
#define QUIT_OPTION "quit"
#define END_OPTION "end"

#define EXTRA_BUFFER 2 // extra char for detecting going over + space for \0
#define MAX_OPTION_SIZE 8
#define MAX_GAME_NAME_SIZE (50 + EXTRA_BUFFER)
#define MAX_GENRE_NAME_SIZE (15 + EXTRA_BUFFER)
#define MAX_GENRE_AMOUNT 10

typedef struct game_metadata
{
    char name[MAX_GAME_NAME_SIZE];
    char genres[MAX_GENRE_AMOUNT][MAX_GENRE_NAME_SIZE];
    int genre_amount;
    double playtime;
} game;

void print_splash(void);
void print_menu(void);
void handle_menu_selection(const char *user_selection);

void search_game(void);

void add_game(void);
bool set_name(game *game);
bool is_valid_game_name(const char *game_name);
bool set_genres(game *game);
bool is_valid_genre_name(const char *genre_name);
game *find_games(char *game_name, int *games_found);
void display_games(game *game, int games_found);

bool get_string(char *string, const int size);
void clear_buffer(char *string);
void trim_whitespace(char *string);
bool char_in_string(const char *string, char character);

#endif // HEADERS_H

#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>
#include <stdio.h>

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
#define MAX_LINE_LENGTH 128
#define METADATA_FILE "metadata.txt"

typedef enum game_genre
{
    GENRE_ACTION = 1 << 0,
    GENRE_ADVENTURE = 1 << 1,
    GENRE_RPG = 1 << 2,
    GENRE_STRATEGY = 1 << 3,
    GENRE_SIMULATION = 1 << 4,
    GENRE_PUZZLE = 1 << 5,
    GENRE_PLATFORMER = 1 << 6,
    GENRE_SHOOTER = 1 << 7,
    GENRE_RACING = 1 << 8,
    GENRE_SPORTS = 1 << 9,
    GENRE_HORROR = 1 << 10,
    GENRE_SURVIVAL = 1 << 11,
    GENRE_SANDBOX = 1 << 12,
    GENRE_ROGUELIKE = 1 << 13,
    GENRE_FIGHTING = 1 << 14,
    GENRE_MULTIPLAYER = 1 << 15
} genre;

#define GENRE_AMOUNT 16

typedef struct game_metadata
{
    char name[MAX_GAME_NAME_SIZE];
    unsigned int genres;
    double playtime;
} game;

// menu_functions.c
void print_splash(void);
void print_menu(void);
void handle_menu_selection(const char *user_selection);

// game_functions.c
void add_game(void);
bool set_name(game *game);
bool set_genres(game *game);

void search_game(void);
game *find_games(char *game_name, int *games_found);
bool valid_search_result(const char *line, const char *game_name, game *game_,
                         const int line_index);
bool store_game(game **games, int *games_found, game *game_);
void skip_line(FILE *file);
void display_games(game *games, int games_found);
bool is_valid_game_name(const char *game_name);
unsigned int get_genre_bitwise(const char *genre_name);
bool get_game_from_line(const char *line, game *game_, const int line_index);

// string_helpers.c
bool get_string(char *string, const int size);
void clear_buffer(char *string);
void trim_whitespace(char *string);
bool char_in_string(const char *string, char character);

#endif // HEADERS_H

#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H
#include <stdbool.h>
#include <stdio.h>

#define CANCEL_OPTION "cancel"
#define ALL_OPTION "all"
#define END_OPTION "end"

#define EXTRA_BUFFER 2 // extra char for detecting going over + space for \0
#define MAX_GAME_NAME_SIZE (50 + EXTRA_BUFFER)
#define MAX_GENRE_NAME_SIZE (15 + EXTRA_BUFFER)
#define MAX_LINE_LENGTH 128
#define METADATA_FILE "metadata.txt"

#define GENRE_AMOUNT 16

typedef struct game_metadata
{
    char name[MAX_GAME_NAME_SIZE];
    unsigned int genres;
    double playtime;
} game;

void add_game(void);
bool set_name(game *game);
bool set_genres(game *game);
unsigned int get_genre_bitwise(const char *genre_name);

void search_game(void);
game *find_games(char *game_name, int *games_found);
void skip_line(FILE *file);
bool valid_search_result(const char *line, const char *game_name, game *game_,
                         const int line_index);
bool get_game_from_line(const char *line, game *game_, const int line_index);
bool store_game(game **games, int *games_found, game *game_);
void display_games(game *games, int games_found);

bool is_valid_game_name(const char *game_name);

#endif // GAME_FUNCTIONS_H

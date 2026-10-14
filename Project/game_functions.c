#include "headers.h"
#include <stdio.h>
#include <string.h>

// Asks the user for a new game's name and genres, and appends the game into metadata.txt.
// If the user cancels at any point, the game is discarded without saving.
void add_game(void)
{
    game new_game;

    if (!set_name(&new_game) || !set_genres(&new_game))
    {
        return;
    }
    else
    {
        FILE *metadata_file = fopen("metadata.txt", "a");
        if (metadata_file == NULL)
        {
            fprintf(stderr,
                    "Could not open file 'metadata.txt'. Ensure that read & write permissions "
                    "are enabled for the file.\n");
            return;
        }
        fprintf(metadata_file, "%s;", new_game.name);
        for (int g = 0; g < new_game.genre_amount; g++)
        {
            fprintf(metadata_file, "%s,", new_game.genres[g]);
        }
        fprintf(metadata_file, ";%lf\n", 0.0);
        fclose(metadata_file);
    }
}

// Asks the user for a game name until a valid one is given, and stores it into 'game'.
// Returns true if the name was stored, false if the user cancelled or input failed.
bool set_name(game *game)
{
    char game_name[MAX_GAME_NAME_SIZE] = "";
    bool name_accepted = false;

    while (!name_accepted)
    {
        printf("Enter the name of the game (max %d char) or '%s' to cancel: ",
               MAX_GAME_NAME_SIZE - EXTRA_BUFFER, CANCEL_OPTION);
        if (!get_string(game_name, MAX_GAME_NAME_SIZE))
        {
            return false;
        }

        if (is_valid_game_name(game_name))
        {
            if (!strcmp(game_name, CANCEL_OPTION))
            {
                return false;
            }
            strcpy(game->name, game_name);
            name_accepted = true;
        }
    }
    return true;
}

// Checks that 'game_name' is not empty, fits within the maximum length and does not contain
// ';'. Returns true if valid, false if not, printing a descriptive error message.
bool is_valid_game_name(const char *game_name)
{
    if (strlen(game_name) == 0)
    {
        printf("Game name cannot be empty.\n");
        return false;
    }
    if (strlen(game_name) > MAX_GAME_NAME_SIZE - EXTRA_BUFFER)
    {
        printf("Game name cannot be over %d characters.\n", MAX_GAME_NAME_SIZE - EXTRA_BUFFER);
        return false;
    }
    if (char_in_string(game_name, ';'))
    {
        printf("Game name cannot contain the character ';'.\n");
        return false;
    }
    return true;
}

// Asks the user for up to MAX_GENRE_AMOUNT genres one at a time, and stores them into 'game'.
// Returns true if the user ended or the maximum was reached, false if the user cancelled or
// input failed.
bool set_genres(game *game)
{
    char genre_name[MAX_GENRE_NAME_SIZE] = "";
    int genres_added = 0;

    while (genres_added < MAX_GENRE_AMOUNT)
    {
        printf("Enter a genre one at a time (%d/%d, max %d char), '%s' to end, or '%s' to cancel: ",
               genres_added, MAX_GENRE_AMOUNT, MAX_GENRE_NAME_SIZE - EXTRA_BUFFER, END_OPTION,
               CANCEL_OPTION);
        if (!get_string(genre_name, MAX_GENRE_NAME_SIZE))
        {
            return false;
        }

        if (is_valid_genre_name(genre_name))
        {
            if (!strcmp(genre_name, CANCEL_OPTION))
            {
                return false;
            }
            else if (!strcmp(genre_name, END_OPTION))
            {
                game->genre_amount = genres_added;
                return true;
            }
            strcpy(game->genres[genres_added], genre_name);
            genres_added++;
        }
    }
    game->genre_amount = genres_added;
    return true;
}

// Checks that 'genre_name' is not empty, fits within the maximum length and does not contain ';'
// or ','. Returns true if valid, false if not, printing a descriptive error message.
bool is_valid_genre_name(const char *genre_name)
{
    if (strlen(genre_name) == 0)
    {
        printf("Genre name cannot be empty.\n");
        return false;
    }
    if (strlen(genre_name) > MAX_GENRE_NAME_SIZE - EXTRA_BUFFER)
    {
        printf("Genre name cannot be over %d characters.\n", MAX_GENRE_NAME_SIZE - EXTRA_BUFFER);
        return false;
    }
    if (char_in_string(genre_name, ';') || char_in_string(genre_name, ','))
    {
        printf("Genre name cannot contain the characters ';' or ','.\n");
        return false;
    }
    return true;
}

// Asks the user for a game name to search for, or 'all' for every game, until matching games
// are found. Displays the found games into stdout. Returns early if the user cancels or input
// fails.
void search_game(void)
{
    char game_name[MAX_GAME_NAME_SIZE] = "";
    bool game_found = false;

    game *game;
    int games_found;

    while (!game_found)
    {
        printf("Enter the name of the game (max %d char), '%s' for all, or '%s' to cancel: ",
               MAX_GAME_NAME_SIZE - EXTRA_BUFFER, ALL_OPTION, CANCEL_OPTION);
        if (!get_string(game_name, MAX_GAME_NAME_SIZE))
        {
            return;
        }

        if (is_valid_game_name(game_name))
        {
            if (!strcmp(game_name, CANCEL_OPTION))
            {
                return;
            }

            game = find_games(game_name, &games_found);
            if (game == NULL)
            {
                printf("Could not find game by the name of '%s'.\n", game_name);
            }
            else
            {
                game_found = true;
            }
        }
    }

    display_games(game, games_found);
}

// Searches metadata.txt for games with a name containing 'game_name', or every game if
// 'game_name' is 'all'. Returns an allocated array of the found games and stores their amount
// into 'games_found', or NULL if none were found. The caller must free the array.
game *find_games(char *game_name, int *games_found) {}

// Displays the first 'games_found' games of the 'game' array into stdout.
void display_games(game *game, int games_found) {}
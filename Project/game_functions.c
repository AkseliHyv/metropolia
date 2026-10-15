#include "headers.h"
#include <stdlib.h>
#include <string.h>

static const char *GENRES[GENRE_AMOUNT] = {"action",     "adventure", "rpg",        "strategy",
                                           "simulation", "puzzle",    "platformer", "shooter",
                                           "racing",     "sports",    "horror",     "survival",
                                           "sandbox",    "roguelike", "fighting",   "multiplayer"};

// Creates a game with a name and genres, and stores it into METADATA_FILE. Cancelling
// midway doesn't save the game.
void add_game(void)
{
    game new_game;
    new_game.genres = 0;
    new_game.playtime = 0.0;

    if (!set_name(&new_game) || !set_genres(&new_game))
    {
        return;
    }
    else
    {
        FILE *metadata_file = fopen(METADATA_FILE, "a");
        if (metadata_file == NULL)
        {
            fprintf(stderr,
                    "Could not open file '%s'. Ensure that read & write permissions "
                    "are enabled for the file.\n",
                    METADATA_FILE);
            return;
        }
        fprintf(metadata_file, "%s;%u;%lf\n", new_game.name, new_game.genres, new_game.playtime);
        fclose(metadata_file);
    }
}

// Asks user for a valid game name, and stores it into 'game'. Returns false if cancelled or reading
// failed.
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

// Asks user for genres one at a time, and stores them into 'game'. Returns false if the user
// cancelled or reading failed.
bool set_genres(game *game)
{
    char genre_name[MAX_GENRE_NAME_SIZE] = "";

    while (strcmp(genre_name, END_OPTION))
    {
        printf("Valid genres:\n");
        for (int g = 0; g < GENRE_AMOUNT; g++)
        {
            if ((g + 1) % 4 == 0)
            {
                printf("%12s\n", GENRES[g]);
            }
            else
            {
                printf("%12s ", GENRES[g]);
            }
        }

        printf("Enter a genre one at a time (lowercase), '%s' to end, or '%s' to cancel: ",
               END_OPTION, CANCEL_OPTION);
        if (!get_string(genre_name, MAX_GENRE_NAME_SIZE) || !strcmp(genre_name, CANCEL_OPTION))
        {
            return false;
        }

        if (strcmp(genre_name, END_OPTION))
        {
            unsigned int genre_bit = get_genre_bitwise(genre_name);

            if (genre_bit != 0)
            {
                game->genres = game->genres | genre_bit;
            }
            else
            {
                fprintf(stderr, "Invalid genre.\n");
            }
        }
    }

    return true;
}

// Gets the bit associated with the genre, or 0 if not associated with any genre.
unsigned int get_genre_bitwise(const char *genre_name)
{
    for (int i = 0; i < GENRE_AMOUNT; i++)
    {
        if (!strcmp(GENRES[i], genre_name))
        {
            return 1 << i;
        }
    }
    return 0;
}

// Searches for game by name, or 'all' for every game. Displays found games into stdout.
void search_game(void)
{
    char game_name[MAX_GAME_NAME_SIZE] = "";
    game *games = NULL;
    int games_found = 0;

    while (games == NULL)
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

            games = find_games(game_name, &games_found);

            if (games == NULL)
            {
                printf("Could not find any games.\n");
            }
        }
    }

    display_games(games, games_found);
    free(games);
}

// Searches METADATA_FILE for games named 'game_name', or every game if 'game_name' is all. Returns
// mallocd array of found games, and stores amount found into 'games_found'. Returns NULL if none
// were found.
game *find_games(char *game_name, int *games_found)
{
    char line[MAX_LINE_LENGTH];
    game *games = NULL;

    FILE *metadata_file = fopen(METADATA_FILE, "r");

    if (metadata_file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", METADATA_FILE);
        return NULL;
    }

    int index = 1;
    while (fgets(line, MAX_LINE_LENGTH, metadata_file) != NULL)
    {
        if (line[strlen(line) - 1] != '\n')
        {
            fprintf(stderr, "Line %d: Line is too long\n", index);
            skip_line(metadata_file);
        }
        else
        {
            game current_game;

            if (valid_search_result(line, game_name, &current_game, index))
            {
                if (!store_game(&games, games_found, &current_game))
                {
                    fclose(metadata_file);
                    return games;
                }
            }
        }
        index++;
    }

    fclose(metadata_file);
    return games;
}

// Empties the rest of the line in 'file'.
void skip_line(FILE *file)
{
    int c = 'a';
    while (c != '\n' && c != EOF)
    {
        c = fgetc(file);
    }
}

// Returns true if 'line' contains proper game data and matches the search query. Stores line data
// into 'game_'.
bool valid_search_result(const char *line, const char *game_name, game *game_, const int line_index)
{
    if (strspn(line, " \t\r\n") == strlen(line))
    {
        return false;
    }
    if (!get_game_from_line(line, game_, line_index))
    {
        return false;
    }
    if (strcmp(game_->name, game_name) && strcmp(game_name, ALL_OPTION))
    {
        return false;
    }
    return true;
}

// Sets the values in 'line' into 'game_name', 'genres', and 'playtime'. Returns false if line is
// incorrectly formatted.
bool get_game_from_line(const char *line, game *game_, const int line_index)
{
    char extra = '\0';
    if (sscanf(line, "%51[^;];%u;%lf %c", game_->name, &game_->genres, &game_->playtime, &extra) <
        3)
    {
        if (strlen(game_->name) > MAX_GAME_NAME_SIZE - EXTRA_BUFFER)
        {
            fprintf(stderr, "Line %d: Bad name\n", line_index);
        }
        else
        {
            fprintf(stderr, "Line %d: Missing fields\n", line_index);
        }
        return false;
    }
    else if (extra != '\0')
    {
        fprintf(stderr, "Line %d: Too many fields\n", line_index);
        return false;
    }

    if (game_->genres >= 1u << GENRE_AMOUNT)
    {
        fprintf(stderr, "Line %d: Bad genres\n", line_index);
        return false;
    }
    else if (game_->playtime < 0)
    {
        fprintf(stderr, "Line %d: Bad playtime\n", line_index);
        return false;
    }

    return true;
}

// Stores 'game_' into game struct array 'games'. Mallocs space for the array if it does not exist
// yet, or adds space for another game if it does.
bool store_game(game **games, int *games_found, game *game_)
{
    game *tmp = NULL;
    const size_t game_size = sizeof(game);

    if (*games_found == 0)
    {
        tmp = malloc(game_size);
    }
    else
    {
        tmp = realloc(*games, game_size * (*games_found + 1));
    }

    if (tmp == NULL)
    {
        fprintf(stderr, "Not enough memory to allocate to games.\n");
        return false;
    }
    *games = tmp;

    (*games)[*games_found] = *game_;

    (*games_found)++;
    return true;
}

// Displays games in 'games' array.
void display_games(game *games, int games_found)
{
    printf("\n----------------------------------------------------------------------------\n");
    for (int ga = 0; ga < games_found; ga++)
    {
        game game = games[ga];
        printf("Name: %-52sPlaytime: %.2lfh\n", game.name, game.playtime);
        printf("Genres: ");
        if (game.genres == 0)
        {
            printf("none");
        }
        else
        {
            bool first = true;
            for (int ge = 0; ge < GENRE_AMOUNT; ge++)
            {
                if (game.genres & (1u << ge))
                {
                    if (!first)
                    {
                        printf(", ");
                    }
                    printf("%s", GENRES[ge]);
                    first = false;
                }
            }
        }
        printf("\n----------------------------------------------------------------------------\n");
    }
    printf("\n");
}

// Checks if 'game_name' is not empty, is within MAX_GAME_NAME_SIZE and does not contain ';'.
bool is_valid_game_name(const char *game_name)
{
    if (strlen(game_name) == 0)
    {
        fprintf(stderr, "Game name cannot be empty.\n");
        return false;
    }
    if (strlen(game_name) > MAX_GAME_NAME_SIZE - EXTRA_BUFFER)
    {
        fprintf(stderr, "Game name cannot be over %d characters.\n",
                MAX_GAME_NAME_SIZE - EXTRA_BUFFER);
        return false;
    }
    if (char_in_string(game_name, ';'))
    {
        fprintf(stderr, "Game name cannot contain the character ';'.\n");
        return false;
    }
    return true;
}

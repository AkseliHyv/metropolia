#include "headers.h"
#include <ctype.h>
#include <stdio.h>
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

        printf("Enter a genre one at a time (lowercase), '%s' to end, or '%s' to cancel: ", END_OPTION,
               CANCEL_OPTION);
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
    const size_t game_size = sizeof(game);
    char line[MAX_LINE_LENGTH];
    game *games = NULL;
    game *tmp = NULL;

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
            printf("Line %d: Line is too long\n", index);

            int c = 'a';
            while (c != '\n' && c != EOF)
            {
                c = fgetc(metadata_file);
            }
        }
        else
        {
            char current_game_name[MAX_GAME_NAME_SIZE] = "";
            unsigned int genres;
            double playtime = 0.0;
            if (strspn(line, " \t\r\n") != strlen(line) &&
                get_game_from_line(line, current_game_name, &genres, &playtime, index) &&
                (!strcmp(current_game_name, game_name) || !strcmp(game_name, ALL_OPTION)))
            {
                if (*games_found == 0)
                {
                    tmp = malloc(game_size);
                }
                else
                {
                    tmp = realloc(games, game_size * (*games_found + 1));
                }

                if (tmp == NULL)
                {
                    fprintf(stderr, "Not enough memory to allocate to games.\n");
                    fclose(metadata_file);
                    return games;
                }
                games = tmp;

                strcpy(games[*games_found].name, current_game_name);
                games[*games_found].genres = genres;
                games[*games_found].playtime = playtime;

                (*games_found)++;
            }
        }
        index++;
    }

    fclose(metadata_file);
    return games;
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
            printf("none,");
        }
        else
        {
            for (int ge = 0; ge < GENRE_AMOUNT; ge++)
            {
                if (game.genres & (1u << ge))
                {
                    printf("%s, ", GENRES[ge]);
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

// Sets the values in 'line' into 'game_name', 'genres', and 'playtime'. Returns false if line is
// incorrectly formatted.
bool get_game_from_line(char *line, char *game_name, unsigned int *genres, double *playtime,
                        const int line_index)
{
    char extra = '\0';
    if (sscanf(line, "%51[^;];%u;%lf %c", game_name, genres, playtime, &extra) < 3)
    {
        if (strlen(game_name) > MAX_GAME_NAME_SIZE - EXTRA_BUFFER)
        {
            printf("Line %d: Bad name\n", line_index);
        }
        else {
            printf("Line %d: Missing fields\n", line_index);
        }
        return false;
    }
    else if (extra != '\0')
    {
        printf("Line %d: Too many fields\n", line_index);
        return false;
    }

    if (*genres >= 1u << GENRE_AMOUNT)
    {
        printf("Line %d: Bad genres\n", line_index);
        return false;
    }
    else if (*playtime < 0)
    {
        printf("Line %d: Bad playtime\n", line_index);
        return false;
    }

    return true;
}
#include "headers.h"
#include "game.c"
#include <stdio.h>
#include <string.h>

void add_game() {
    game new_game;

    if (!set_name(&new_game) || !set_genres(&new_game) || !set_image_path(&new_game)) {
        return;
    }
    else {
        // save game
    }
}

bool set_name(game *game) {
    bool finished = false;
    bool canceled = false;
    char game_name[MAX_GAME_NAME_SIZE];
    char prompt[MAX_PROMPT_SIZE];

    while (!finished) {
        snprintf(prompt, sizeof(prompt),
            "Enter the name of the game (max %d char) or '%s' to cancel: ",
            MAX_GAME_NAME_SIZE - EXTRA_BUFFER, CANCEL_OPTION);
        get_string(prompt, game_name, MAX_GAME_NAME_SIZE);

        if (strlen(game_name) == 0) {
            printf("Game name cannot be empty.\n");
        }
        else if (strlen(game_name) > MAX_GAME_NAME_SIZE - EXTRA_BUFFER) {
            printf("Game name cannot be over %d characters.\n", MAX_GAME_NAME_SIZE - EXTRA_BUFFER);
        }
        else {
            canceled = strcmp(game_name, CANCEL_OPTION) == 0;
            strcpy(game->name, game_name);
            finished = true;
        }
    }
    return canceled;
}

bool set_genres(game *game) {
    bool canceled = false;
    char genre_name[MAX_GENRE_NAME_SIZE];
    char prompt[MAX_PROMPT_SIZE];
    int genres_added = 0;

    while (genres_added < MAX_GENRE_AMOUNT) {
        snprintf(prompt, sizeof(prompt),
            "Enter a genre one at a time (%d/%d, max %d char), '%s' to end, or '%s' to cancel: ",
            genres_added, MAX_GENRE_AMOUNT, MAX_GENRE_NAME_SIZE - EXTRA_BUFFER, END_OPTION, CANCEL_OPTION);
        get_string(prompt, genre_name, MAX_GENRE_NAME_SIZE);

        if (strlen(genre_name) == 0) {
            printf("Genre name cannot be empty.\n");
        }
        else if (strlen(genre_name) > MAX_GENRE_NAME_SIZE - EXTRA_BUFFER) {
            printf("Genre name cannot be over %d characters.\n", MAX_GENRE_NAME_SIZE - EXTRA_BUFFER);
        } else {
            strcpy(game->genres[genres_added], genre_name);
            genres_added++;

            canceled = strcmp(genre_name, CANCEL_OPTION) == 0;
            if (strcmp(genre_name, END_OPTION) || canceled) {
                genres_added = MAX_GENRE_AMOUNT;
            }
        }
    }
    return canceled;
}

bool set_image_path(game *game) {

}

void search_game() {
    // Search by name or genre
}
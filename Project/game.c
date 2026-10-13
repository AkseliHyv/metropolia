#include "headers.h"

typedef struct game_metadata {
    char name[MAX_GAME_NAME_SIZE];
    char genres[MAX_GENRE_AMOUNT][MAX_GENRE_NAME_SIZE];
    char thumbnail_location[MAX_THUMBNAIL_PATH_LENGTH];
    int last_played[3];
    double playtime;
    int id;
} game;
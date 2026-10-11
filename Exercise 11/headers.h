#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

#define MAX_STRING_LENGTH 100
#define REPLACE_PAIR_LENGTH 2
#define REPLACE_PAIR_BUFLENGTH (REPLACE_PAIR_LENGTH + 2) // Extra char for detecting too big strings + '\0'

bool read_string(char *string, const int size, const char *prompt);
void clear_input(void);
int replace_char(char *string, const char *replace_pair);

#endif // HEADERS_H

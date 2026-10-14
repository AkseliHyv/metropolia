#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

#define MAX_WORD_LENGTH 32
#define MAX_PASSWORD_LENGTH (MAX_WORD_LENGTH * 2)

bool read_string(char *string, const int size);
bool encrypt_word(char *password, int max_pass_length, char *word);

#endif // HEADERS_H

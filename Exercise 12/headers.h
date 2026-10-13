#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

#define MAX_STRING_LENGTH 100
#define MAX_WORD_LENGTH 25
#define STOP_WORD "stop"

bool read_string(char *string, const int size);
int count_words(const char* string, const char *word);

#endif // HEADERS_H

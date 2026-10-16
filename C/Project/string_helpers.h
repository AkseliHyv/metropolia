#ifndef STRING_HELPERS_H
#define STRING_HELPERS_H
#include <stdbool.h>

bool get_string(char *string, const int size);
void clear_buffer(char *string);
void trim_whitespace(char *string);
bool char_in_string(const char *string, char character);

#endif // STRING_HELPERS_H

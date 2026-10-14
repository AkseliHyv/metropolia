#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

#define HIGHEST_NUM 15
#define MAX_INPUT_SIZE                                                                             \
    13 // smallest int '-2147483648' is 11, so 11 + \0 + space for detecting extra
#define BIT_MASK 63

bool read_string(char *string, const int size);
bool get_integer(const char *string, int *number);
void print_hex(const int num);

#endif // HEADERS_H

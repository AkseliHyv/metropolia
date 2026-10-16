#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

#define MAX_FILE_NAME_SIZE 20
#define MAX_LINE_LENGTH 256

bool read_string(char *string, const int size);
bool check_file(const char *file_name, const int line_length);
unsigned int calculate_checksum(const char *data);

#endif // HEADERS_H

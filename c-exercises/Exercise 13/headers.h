#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>
#include <stdio.h>

#define MAX_FILE_NAME_SIZE 20

bool read_string(char *string, const int size);
void read_file(FILE *file, const char *file_name);

#endif // HEADERS_H

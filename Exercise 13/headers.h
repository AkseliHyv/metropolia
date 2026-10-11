#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>
#include <stdio.h>

#define MAX_FILE_NAME_SIZE 15

bool read_string(char *string, const int size, const char *prompt);
void read_file(FILE *file, const char *file_name);
void print_results(const char *file_name, const int numbers_found, const int highest_number, const int smallest_number);

#endif // HEADERS_H

#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

#define MAX_FILE_NAME_SIZE 20
#define MAX_LINE_LENGTH 82
#define MAX_LINE_AMOUNT 100

bool read_string(char *string, const int size);
bool read_file_lines(const char *file_name, const int line_length, const int max_line_amount,
                     char lines[][line_length], int *line_count);
void to_upper(const int line_length, char lines[][line_length], const int line_count);
bool update_file(const char *file_name, const int line_length, char lines[][line_length],
                 const int line_count);

#endif // HEADERS_H

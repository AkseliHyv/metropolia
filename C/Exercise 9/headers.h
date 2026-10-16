#ifndef HEADERS_H
#define HEADERS_H

#define ARRAY_SIZE 20
void fill_array(unsigned int *array, int size);
void print_array(const unsigned int *array);
int get_input(void);
void handle_input(const unsigned int *array, int input);
int find_first(const unsigned int *array, unsigned int what);

#endif // HEADERS_H

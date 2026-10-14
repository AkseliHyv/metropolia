#ifndef HEADERS_H
#define HEADERS_H
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *next;
} nnode;

#define MAX_INPUT_SIZE                                                                             \
    13 // smallest int '-2147483648' is 11, so 11 + \0 + space for detecting extra

bool read_string(char *string, const int size);
bool get_integer(const char *string, int *number);
bool make_node(nnode **head, nnode **tail, const int number);
void print_nodes(nnode *head);
void free_nodes(nnode **head);

#endif // HEADERS_H

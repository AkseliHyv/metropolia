#include "headers.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char user_input[MAX_INPUT_SIZE] = "";
    int number = 0;
    nnode *head = NULL;
    nnode *tail = NULL;

    while (strcmp(user_input, "end"))
    {
        printf("Enter a number, or 'end' to end: ");
        if (!read_string(user_input, MAX_INPUT_SIZE))
        {
            fprintf(stderr, "Could not read user input.\n");
            return EXIT_FAILURE;
        }

        if (get_integer(user_input, &number))
        {
            if (!make_node(&head, &tail, number))
            {
                fprintf(stderr, "Could not make new allocation.\n");
                print_nodes(head);
                free_nodes(&head);
            }
        }
    }

    print_nodes(head);
    free_nodes(&head);

    return EXIT_SUCCESS;
}

// Reads input from stdin into 'string', which can hold 'size' characters including the '\0'.
// Removes newline, and clears extra characters from the buffer. Returns false if nothing could be
// read.
bool read_string(char *string, const int size)
{
    if (fgets(string, size, stdin) == NULL)
    {
        return false;
    }

    const size_t string_length = strlen(string);
    if (string[string_length - 1] == '\n')
    {
        string[string_length - 1] = '\0';
    }
    else
    {
        while ((getchar()) != '\n')
        {
        }
    }
    return true;
}

// Checks if 'string' contains an integer number, and assigns it to 'number' if it does.
// Returns false if number is not a valid integer, or the string contains text.
bool get_integer(const char *string, int *number)
{
    long int temp_num;
    char extra;
    if (sscanf(string, "%ld%c", &temp_num, &extra) != 1)
    {
        if (strcmp(string, "end"))
        {
            printf("Invalid input.\n");
        }
        return false;
    }

    if (temp_num > INT_MAX || temp_num < INT_MIN)
    {
        printf("Number is not a valid integer.\n");
        return false;
    }
    *number = temp_num;
    return true;
}

// Creates a new node with 'number' and adds it to the end of the linked list using 'head' and
// 'tail'. Returns false if memory could not be allocated for the node.
bool make_node(nnode **head, nnode **tail, const int number)
{
    nnode *new = malloc(sizeof(nnode));
    if (new == NULL)
    {
        return false;
    }
    new->number = number;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = *head;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
    return true;
}

// Prints the numbers of all nodes in the linked list into stdout, starting from 'head'.
void print_nodes(nnode *head)
{
    nnode *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->number);
        current = current->next;
    }
}

// Frees all nodes in the linked list starting from 'head', and sets 'head' to NULL.
void free_nodes(nnode **head)
{
    while (*head != NULL)
    {
        nnode *next = (*head)->next;
        free(*head);
        *head = next;
    }
}

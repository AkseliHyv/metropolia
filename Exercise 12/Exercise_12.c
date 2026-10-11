#include "headers.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[MAX_STRING_LENGTH];
    char word[MAX_WORD_LENGTH];
    bool done = false;

    while (!done)
    {
        if (!read_string(string, MAX_STRING_LENGTH, "Enter a sentence: "))
        {
            done = true;
        }
        else if (!read_string(word, MAX_WORD_LENGTH, "Enter a word: "))
        {
            done = true;
        }
        else if (strcmp(word, STOP_WORD) == 0)
        {
            done = true;
        }
        else 
        {
            const int occurences = count_words(string, word);
            printf("The word '%s' was found %d times in the sentence '%s'.\n", word, occurences, string);
        }
    }
    
    return 0;
}

bool read_string(char *string, const int size, const char *prompt)
{
    printf("%s", prompt);
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
        clear_input();
    }
    return true;
}

void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int count_words(const char* string, const char *word)
{
    const size_t word_size = strlen(word);
    bool nul_reached = false;
    int occurences = 0;
    while (!nul_reached)
    {
        const char *occurence = strstr(string, word);
        if (occurence != NULL && word_size != 0)
        {
            string = occurence + word_size;
            occurences++;
        }
        else
        {
            nul_reached = true;
        }
    }
    return occurences;
}

/*
Write a function count_words that takes two strings as a parameter and returns an integer. The
function counts the number of times the second string occurs in the first string and returns the
count. Use strstr() from standard library to find the strings. Note that if the string is found you need
to advance past the current occurrence before searching again. Hint: use a pointer to the string and
use pointer arithmetic to advance it past the current match.
Prototype of the function:
int count_words(const char* str, const char *word);
Write a program that asks user to enter a string and a word. Then program calls count_words and
prints the return value. If the word was “stop” the program stops otherwise it asks user to enter a
string and a word again.
*/
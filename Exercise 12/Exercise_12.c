#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char string[MAX_STRING_LENGTH];
    char word[MAX_WORD_LENGTH];
    bool done = false;

    while (!done)
    {
        printf("Enter a sentence: ");
        if (!read_string(string, MAX_STRING_LENGTH))
        {
            done = true;
        }
        else
        {
            printf("Enter a word (or 'stop' to end): ");
            if (!read_string(word, MAX_WORD_LENGTH))
            {
                done = true;
            }
            else if (strcmp(word, STOP_WORD) == 0)
            {
                done = true;
            }
            else
            {
                const int occurrences = count_words(string, word);
                printf("The word '%s' was found %d times in the sentence '%s'.\n", word,
                       occurrences, string);
            }
        }
    }

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

// Counts how many times 'word' occurs in 'string', skipping past each found occurrence.
// Returns 0 if 'word' is empty.
int count_words(const char *string, const char *word)
{
    const size_t word_size = strlen(word);
    bool matches_remaining = true;
    int occurrences = 0;
    while (matches_remaining)
    {
        const char *occurrence = strstr(string, word);
        if (occurrence != NULL && word_size != 0)
        {
            string = occurrence + word_size;
            occurrences++;
        }
        else
        {
            matches_remaining = false;
        }
    }
    return occurrences;
}

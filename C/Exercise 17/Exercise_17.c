#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    char word[MAX_WORD_LENGTH] = "";
    char password[MAX_PASSWORD_LENGTH];

    while (strcmp(word, "stop"))
    {
        printf("Enter a word to encrypt into a password, or 'stop' to stop: ");
        if (!read_string(word, MAX_WORD_LENGTH))
        {
            fprintf(stderr, "Could not read user input.\n");
            return EXIT_FAILURE;
        }

        if (strcmp(word, "stop"))
        {
            if (!encrypt_word(password, MAX_PASSWORD_LENGTH, word))
            {
                fprintf(stderr, "Could not encrypt password.\n");
            }
            else
            {
                printf("Your encrypted password is: %s\n", password);
            }
        }
    }

    return EXIT_SUCCESS;
}

// Reads input from stdin into 'string', which holds 'size' amount of characters. 
// Removes newline and empties buffer. Returns false if reading failed.
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

// Encrypts 'word' into 'password' by adding a random character between each letter and to both
// ends. Returns false if the password does not fit in 'max_pass_length'.
bool encrypt_word(char *password, int max_pass_length, char *word)
{
    char encrypted_pass[max_pass_length];

    size_t c;
    for (c = 0; c < strlen(word) * 2 + 1; c++)
    {
        if (c == max_pass_length - 1)
        {
            return false;
        }

        if (c % 2)
        {
            encrypted_pass[c] = word[c / 2];
        }
        else
        {
            encrypted_pass[c] = 33 + rand() % 94;
        }
    }
    encrypted_pass[c] = '\0';

    strcpy(password, encrypted_pass);
    return true;
}

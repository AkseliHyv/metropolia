#include "headers.h"
#include <string.h>
#include <stdio.h>

bool get_string(const char *prompt, char *string, const int size) {
    printf("%s", prompt);
    if (fgets(string, size, stdin)) {
        parse_string(string);
        return true;
    }
    return false;
}

void parse_string(char *string) {
    const size_t str_len = strlen(string);
    if (string[str_len - 1] == '\n') {
        string[str_len - 1] = '\0';
    }
    else {
        while (getchar() != '\n') {}
    }
}

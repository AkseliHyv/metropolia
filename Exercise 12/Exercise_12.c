#include "headers.h"

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
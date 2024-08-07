#include "lib.h"

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is an alphabetic letter
int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Function to check if a character is alphanumeric
int is_alnum(char c) {
    return is_alpha(c) || is_digit(c);
}
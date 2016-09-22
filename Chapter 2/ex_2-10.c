/*
**  Exercise 2-6 - The C Programming Language
**  Created 22.09.2016
*/

#include <stdio.h>

// prototypes
int lower(int c);

int main (void) {
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
}

/*
    lower: convert upper-case characters to lower-case characters
    
    The exercise asks explicitly to use a conditional expression instead of
    using an if-else statement.
*/
int lower(int c) {
    return ('A' <= c && c <= 'Z') ? c + 'a' - 'A': c;
}
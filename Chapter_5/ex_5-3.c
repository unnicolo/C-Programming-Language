/*
** Exercise 5-3 - The C Programming Language
** Created 01.07.17
*/

#include <stdio.h>

#define MAXSIZE 1024

void mystrcat(char *, char *);

int main(void) {
    char s[MAXSIZE] = "Hello, ";
    char t[] = "world.";
    printf("s before: %s\n", s);
    printf("t: %s\n", t);
    mystrcat(s, t);
    printf("s after concatenating s and t: %s\n", s);
    return 0;
}

// strcat: concatenate t to the end of s; s must be big enough
void mystrcat(char *s, char *t) {
    // find the end of s
    while (*s != '\0') {
        s++;
    }
    while ((*s++ = *t++) != '\0') {
        ;
    }
}

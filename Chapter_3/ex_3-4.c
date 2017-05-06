/**
 ** Exercise 3-4 - The C Programming Language
 ** Created 06.05.2017
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100

// prototypes
void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
    int n = INT_MIN;
    printf("%i\n", n);
    
    char string[MAXSIZE];
    itoa(n, string);
    printf("%s\n", string);
}

// itoa: convert integer 'n' to characters in 's'
void itoa(int n, char s[]) {
    int i, sign;
    
    if ((sign = n) < 0) {
        if (n << 1 == 0) {
            printf("got INT_MIN = %d\n", n);
        }
        n = -n;
    }
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

// reverse: reverse string 's' in place
void reverse(char s[]) {
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
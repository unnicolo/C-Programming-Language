/**
 ** Exercise 3-5 - The C Programming Language
 ** Created 18.05.2017
 */

#include <stdio.h>
#include <string.h>     // strlen

#define MAXSIZE 1000

void itoa(int n, char s[], int m);
void reverse(char s[]);

int main(void) {
    int n1 = 123;
    int m1 = 2;
    char s[MAXSIZE];
    
    itoa(n1, s, m1);
    printf("%s\n", s);
    
    int n2 = 14569;
    int m2 = 23;
    
    itoa(n2, s, m2);
    printf("%s\n", s);
    return 0;
}

// itoa (modified): convert n to characters in a with a minimum of m characters
// if necessary, the resulting number will be padded with blanks to make a wide enough
void itoa(int n, char s[], int m) {
    int i, sign;
    
    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    // fill up remaining space if necessary...
    while (i < m) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

// reverse: reverse string s
void reverse(char s[]) {
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
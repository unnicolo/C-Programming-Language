/*
** Exercise 5-1 - The C Programming Language
** Created 28.07.17
*/

#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 8 
#define BUFSIZE 128

int mygetch(void);
void myungetch(int);
int getint(int *pn);

static int buf[BUFSIZE];
static int bufp = 0;

int main(void) {
    int numbers[MAXSIZE];
    int n;
    for (n = 0; n < MAXSIZE && getint(&numbers[n]) != EOF; ++n) {
        ;
    }
    for (int i = 0; i < n; i++) {
        printf("pos %i has number %i\n", i, numbers[i]);
    }
    return 0;
}

// getint: get next integer from input into *pn
// return codes: EOF for EOF, 0 for non-numerical, otherwise a positive value
//   for a valid number.
int getint(int *pn) {
    int c, sign;

    while(isspace(c = mygetch())) {
        // skip white space
        ;
    }
    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        if (isalpha(c)) {
            while (isalpha(c = mygetch())) {
                ;
            }
        }
        if (c == '\n') {
            myungetch(c);
        }
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = mygetch();
        // character following +/- is not a digit
        // return 0 since its not a valid number
        if (!isdigit(c)) {
            myungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = mygetch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        myungetch(c);
    }
    return c;
}

// mygetch: get a (possibly) pushed backed character from the buffer
int mygetch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
} 

// ungetch: push a character onto the buffer
void myungetch(int c) {
    buf[bufp++] = c;    
}

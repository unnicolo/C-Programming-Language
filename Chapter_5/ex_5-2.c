/*
** Exercise 5-2 - The C Programming Language
** Created 29.07.17
*/

#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 8
#define BUFSIZE 128

int mygetch(void);
void myungetch(int);
int mygetfloat(float *);

int main(void) {
    int n; 
    float numbers[MAXSIZE];

    for (n = 0; n < MAXSIZE && mygetfloat(&numbers[n]) != EOF; ++n) {
        ;
    }
    for (int i = 0; i < n; i++) {
        printf("number at pos %i: %2f\n", i, numbers[i]);
    }
    return 0;
}

// mygetfloat: get next float from the input into *pn
int mygetfloat(float *pn) {
    int c, sign;
    float val, pow;

    // skip white space
    while (isspace(c = mygetch())) {
        ;
    }
    // not a number
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        // skip all alphabetic characters since this token can't be
        // a number anymore
        if (isalpha(c)) {
            while (isalpha(c = mygetch())) {
                ;
            }
        }
        // newlines will need to be pushed back for the program to
        // work correctly
        if (c == '\n') {
            myungetch(c);
        }
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = mygetch();
    }
    // collect the integer part
    for (*pn = 0; isdigit(c); c = mygetch()) {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.') {
        // collect fractional part
        c = mygetch();
        for (pow = 1.0f, val = 0.0f; isdigit(c); c = mygetch(), pow *= 10) {
            val = 10.0f * val + (c - '0'); 
        }
        val /= pow;
        *pn += val;
    }
    *pn *= sign;
    if (c != EOF) {
        myungetch(c);
    }
    return c;
}

static int buf[BUFSIZE];
static int bufp = 0;

// mygetch: get a (possibly) pushed back character from the buffer
int mygetch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// myungetch: push a character onto the buffer
void myungetch(int c) {
    buf[bufp++] = c;
}

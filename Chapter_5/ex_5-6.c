/*
** Exercise 5-6 - The C Programming Language
** Created 12.07.17
*/

// This exercise asks the reader to rewrite several of the functions
// used in the book throughout now by such that they use pointers.

#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 1024

// strindex
// getop

int mygetline(char *, int);
int myatoi1(const char *);
int myatoi2(const char *);
double myatof(const char *);
void myitoa(int, char *);
void myreverse(char *);
void swap(char *, char *);
int mystrindex(const char *, const char *);

int main(void) {
    // -- getline --
    char s1[MAXSIZE];
    int length;
    length = mygetline(s1, MAXSIZE);
    printf("-- getline --\n");
    printf("%s (%d characters)\n", s1, length);

    // -- atoi --
    printf("-- atoi --\n");
   char *s2 = "123456789";
    int n = myatoi1(s2);
    printf("input string: %s\nnumber: %10d\n", s2, n);

    s2 = "-123456789";
    n = myatoi2(s2);
    printf("input string: %s\nnumber: %10d\n", s2, n);

    s2 = "   -123459";
    n = myatoi2(s2);
    printf("input string: %s\nnumber: %10d\n", s2, n);

    // -- atof --
    printf("-- atof --\n");
    char *s3 = "-123.456";
    double d = myatof(s3);
    printf("input string %s\nnumber: %10f\n", s3, d);

    // -- itoa --
    printf("-- itoa --\n");
    char s4[MAXSIZE];
    int n2 = 123456789;
    myitoa(n2, s4);
    printf("number: %10d\noutput string: %10s\n", n2, s4);

    // -- strindex --
    printf("-- strindex --\n");
    char *s5 = "Hello, world.";
    char *s6 = "world.";
    int pos = mystrindex(s5, s6);
    if (pos >= 0) {
        printf("string \"%s\" at index %2d in string \"%s\"\n", s6,pos,s5);
    } else {
        printf("string \"%s\" not in string \"%s\"\n", s6, s5);
    }
    return 0;
}

// mygetline: get line with maximum length lim into s, return length
int mygetline(char *s, int lim) {
    int c;
    char *temp;

    temp = s;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = '\n';
    }
    *s = '\0';
    return s - temp;
}

// myatoi1: convert a string to integer 
int myatoi1(const char *s) {
    int n;

    n = 0;
    for (; *s >= '0' && *s <= '9'; s++) {
        n = 10 * n + (*s - '0');
    }
    return n;
}

// myatoi2: convert a string to integer; version 2
int myatoi2(const char *s) {
    int n, sign;
    
    // skip whitespace
    for (; isspace(*s); s++) {
        ;
    }
    sign = (*s == '-') ? -1 : 1;
    // skip the sign if present
    if (*s == '+' || *s == '-') {
        s++;
    }
    for (n = 0; isdigit(*s); s++) {
        n = 10 * n + (*s - '0');
    }
    return n * sign;
}

// myatof: convert a string to double
double myatof(const char *s) {
    double val, power;
    int sign;

    // skip whitespace
    for (; isspace(*s); s++) {
        ;
    }
    sign = (*s == '-') ? -1 : 1;
    // skip the sign if present
    if (*s == '+' || *s == '-') {
        s++;
    }
    for (val = 0.0f; isdigit(*s); s++) {
        val = 10.0f * val + (*s - '0');
    }
    if (*s == '.') {
        s++;
    }
    for (power = 1.0f; isdigit(*s); s++) {
        val = 10.0f * val + (*s - '0');
        power *= 10.0f;
    }
    return sign * val / power;
}

// myitoa: convert n to characters in s
void myitoa(int n, char *s) {
    int sign;
    char *t;
    
    // record the sign
    if ((sign = n) < 0) {
        n = -n;
    }
    t = s;
    // generate digits in reverse order
    do {
        *t++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        *t++ = '-';
    }
    *t = '\0';
    myreverse(s);
}

// myreverse: reverse string s in place
void myreverse(char *s) {
    char *temp, *t;

    // advance to the end of string s and store it in t
    t = s;
    while (*(t+1) != '\0') {
        t++;
    }
    for (; s < t; s++, t--) {
        swap(s, t);
    } 
}

// swap: interchange *a and *b
void swap(char *a, char *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

// mystrindex: return index of t in s, -1 if none
int mystrindex(const char *s, const char *t) {
    int i;
    const char *start = s;
    while (*s) {
        // reset the offset variable
        i = 0;
        while (*(t+i) && *(s+i) == *(t+i)) {
            i++;
        }
        if (i > 0 && !*(t+i)) {
            return (s - start);
        }
        s++;
    }
    return -1;
}

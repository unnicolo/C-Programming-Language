/*
** Exercise 5-5 - The C Programming Language
** Created 05.07.17
*/

#include <stdio.h>

#define MAXSIZE 32 

char *mystrncpy(char *, const char *, int n);
char *mystrncat(char *, const char *, int n);
int mystrncmp(const char *, const char *, int n);
void eval_cmp_result(const char *, const char *, int n, int cmp);

int main(void) {
    // -- strncpy --
    char *s;
    char *t = "hello, world.";
    int n = 5;
    s = mystrncpy(s, t, n);
    printf("%s\n", s);

    // -- strncmp --
    s = "Hello, world.";
    char s2[] = "Hello, WORLD.";
    t = "Hello, world.";
    int cmp;
    n = 5;
    // should output that s and t are equal up to the first 5 characters
    cmp = mystrncmp(s, t, n);
    eval_cmp_result(s, t, n, cmp);
    char s3[MAXSIZE] = "Hello, ";
    char *t2 = "world.";
    printf("%s", mystrncat(s3, t2, n));
    return 0;
}

// mystrncpy: copy the first n characters from string into string s
// pad the remaining space with \0 if t has fewer than n characters
char *mystrncpy(char *s, const char *ct, int n) {
    char *s_start = s;
    while (n > 0 && (*s++ = *ct++) != '\0') {
        n--;
    }
    while (n > 0) {
        *s++ = '\0';
        n--;
    }
    return s_start;
}

// mystrncmp: compare the two input strings up to the first n characters
// return codes are the same as for strncmp
int mystrncmp(const char *cs, const char *ct, int n) {
    while (n > 0 && *cs && *ct && !(*cs - *ct)) {
        cs++, ct++;
        n--;
    }
    return *cs - *ct;
}

// mystrncat: concatenate at most n characters of string ct to string s
// and terminate s with '\0’. s is assumed to be big enough; return s
char *mystrncat(char *s, const char *ct, int n) {
    char *temp = s;
    // advance to the end of s
    while (*temp++) {
        ;
    }
    mystrncpy(temp, ct, n);
    return s;
}
// eval_cmp_result: prints the result of the string comparison to the console
void eval_cmp_result(const char *s, const char *t, int n, int cmp) {
    if (cmp) {
        printf("The two strings %s and %s are equal up to the first %d \
                characters.\n", s, t, n);
    } else {
        printf("The two strings %s and %s are not equal up to the first %d \
                characters.\n", s, t, n);
    } 
}

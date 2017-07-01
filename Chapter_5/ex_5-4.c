/*
 ** Exercise 5-4 - The C Programming Language
 ** Created 01.07.17
 */

#include <stdio.h>

#define MAXSIZE 1024

int mystrend(char *, char *);
int mystrlen(char *);
void printresult(int);

int main(void) {
    char s[MAXSIZE] = "Hello, everyone";
    char t[] = "everyone.";
    printresult(mystrend(s,t));
    char u[] = "every0ne.";
    printresult(mystrend(s, u));
    return 0;
}

// mystrend: return 1 if the string t occurs at the end of the string s
//   and 0 otherwise.
int mystrend(char *s, char *t) {
    int n;
    // go to the end of s
    while (*s != '\0') {
        s++;
    }
    // now go back as many characters as string t has
    n = mystrlen(t);
    s -= n;
    // if there is any character up to the end that doesnt match then the ends
    // of the two strings cant be equal
    for (int i = 0; i < n; i++) {
        if (*s+i != *t+i) {
            // there's a mismatch and the two strings can't be equal at the end
            return 0;
        }
    }
    return 1;
}

// mystrlen: return the length of string s
int mystrlen(char *s) {
    char *p = s;
    
    while (*p != '\0') {
        p++;
    }
    return p - s;
}

void printresult(int result) {
    if (result) {
        printf("t at the end of s!\n");
    } else {
        printf("t is not at the end of s.\n");
    }
}

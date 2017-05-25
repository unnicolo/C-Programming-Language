/**
 ** Exercise 4-1 - The C Programming Language
 ** Created 25.05.2017
 */

#include <stdio.h>
#define MAXLINE 1000    // maximum input line length

int getline1(char line[], int max);
int strrindex(char source[], char searchfor[]);

int main(void) {
    char pattern[] = "ould";    // pattern to search for
    char line[MAXLINE];
    int found = 0;
    
    char text[] = "Ah Love! could you and I with Fate conspire\n";
    printf("Right most index found is %2d\n", strrindex(text, pattern));
    
    while (getline1(line, MAXLINE) > 0) {
        if (strrindex(line, pattern) >= 0) {
            printf("Rightmost index is %3d\n", strrindex(line, pattern));
        }
    }
}

// getline1: get line into s, return length
// renamed due to conflicts with system library
int getline1(char s[], int lim) {
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// strrindex: return rightmost index of t in s, -1 if none
int strrindex(char s[], char t[]) {
    int i, j, k, index;
    
    index = -1; // nothing found initially
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            index = i;
        }
    }
    return index;
}

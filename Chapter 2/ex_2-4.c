/*
**  Exercise 2-4 - The C Programming Language
**  Created 04.05.2016
**  Testing strings are hard-coded for now.
*/

#include <stdio.h>

void squeeze(char string1[], char string2[]);

int main(void) {
    int i;
    char s1[] = "Hello";
    char s2[] = "lo";
    
    squeeze(s1, s2);
    i = 0;
    while (s1[i] != '\0') {
        printf("%c", s1[i]);
        ++i;
    }
    printf("\n");
}

/* squeeze: deletes each char in string s1 that matches any char in string s2 */
void squeeze(char s1[], char s2[]) {
    int i, j, k;    // looping variables
    int match;      // indicates a char match
    int c1, c2;     // keep characters of string1 and string2, respectively
    
    i = j = match = 0;
    while ((c1 = s1[j]) != '\0') {
        k = 0;      // always start at the beginning of string2
        while ((c2 = s2[k]) != '\0') {
            if (c1 == c2)
                match = 1;
            ++k;
        }
        if (!match)
            s1[i++] = s1[j];
        ++j;        // increment j regardless of the outcome
    }
    s1[i] = '\0';
}
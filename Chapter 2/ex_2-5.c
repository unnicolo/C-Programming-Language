/*
**  Exercise 2-5 - The C Programming Language
**  Created 05.05.2016
**  Test strings are hard-coded.
*/

#include <stdio.h>

#define NO_OCCURRENCE -1

int any(char string1[], char string2[]);

int main(void) {
    char s1[] = "Hello, there!";
    char s2[] = "The C Programming Language";
    int any_res;
    
    any_res = any(s1, s2);
    if (any_res == NO_OCCURRENCE)
        printf("No character of string2 occurs in string1\n");
    else
        printf("The first occurrence is at index %i of string1\n", any_res);
}

/*  
**  any: takes as input two strings and gives the following return codes:
**      a positive integer i, indicating the first location in string1 that matches
**      any character of string2.
**
**      -1 if no character in string1 matches a character in string2
*/
int any(char s1[], char s2[]) {
    int i, j;      // index variables
    int c1, c2; // store characters of string1 and string2, respectively
    
    i = j = 0;
    while ((c1 = s1[i]) != '\0') {
        j = 0;
        while ((c2 = s2[j]) != '\0') {
            if (c1 == c2)
                return i;
            ++j;
        }
        ++i;
    }
    return NO_OCCURRENCE;
}
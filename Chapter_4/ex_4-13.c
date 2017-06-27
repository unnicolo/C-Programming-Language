/*
** Exercise 4-13 - The C Programming Language
** Created 26.05.17
*/

#include <stdio.h>
#include <string.h>

#define MAXSIZE 1024

void recursive_reverse(char[], int, int);
void swap(char[], int, int);

int main(void) {
    char s[] = "This is rock 'n' roll, baby! :)";
    int len_s = strlen(s);
    recursive_reverse(s, 0, len_s - 1);
    printf("%s\n", s);
    return 0;
}

// recursive_reverse: reverse a string in place using a recursive approach
void recursive_reverse(char s[], int start, int end) {
    if (start < end) {
        swap(s, start, end);
        recursive_reverse(s, start + 1, end - 1);
    }
}

// swap: swap characters at positions i and j in string s
void swap(char s[], int i, int j) {
    int temp;
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
}

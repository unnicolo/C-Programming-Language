/*
**  Exercise 2.2 - The C Programming Language
**  Write a loop equivalent to the following loop without using && or ||
**  for (int i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
**      s[i] = c;
*/

#include <stdio.h>

#define MAXSIZE 1000    // max size of the line

void loop_test(char line[], int size);

int main(void)
{
    int i, c;
    char s[MAXSIZE];
    
    for (i = 0; i<MAXSIZE-1; ++i) {
        if ((c=getchar()) != '\n') {
            if (c != EOF)
                s[i] = c;
        } else
            break;
    }
    loop_test(s, i);
}

void loop_test(char line[], int length)
{
    for (int i = 0; i<length; ++i) {
        printf("%c", line[i]);
    }
    printf("\n");
}
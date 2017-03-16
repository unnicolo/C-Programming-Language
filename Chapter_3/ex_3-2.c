/**
 ** Exercise 3-2 - The C Programming Language
 ** Created 12.03.2017
 */

#include <stdio.h>

#define MAXSIZE 1000

// prototypes
void escape(char t[], char s[]);
void unescape(char t[], char s[]);
void getinput(char input[]);

int main(void) {
    char inputString[MAXSIZE];
    char resultString[MAXSIZE];
    getinput(inputString);
    printf("\nThe original string was:\n%s\n", inputString);
    escape(resultString, inputString);
    printf("The escaped string looks like this:\n%s\n", resultString);
    unescape(resultString, inputString);
    printf("The unescaped string again looks like this:\n%s\n", resultString);
    return 0;
}


/*
 ** escape: Looks for newline and tab characters in a given string
 **  and converts them into ascii characters as it copies the string to the target.
 **
 ** @param target: where the destination string will be put.
 ** @param source: the string to escape
 **
 ** @return: nothing
 */
void escape(char target[], char source[]) {
    int c;
    int i,j = 0;
    while ((c = source[i++]) != '\0') {
        switch (c) {
            case '\n':
                // advance one step and put a \ to escape the next char
                target[j++] = '\\';
                target[j++] = 'n';
                break;
            case '\t':
                target[j++] = '\\';
                target[j++] = 't';
                break;
            default:
                // just put the character in the target string
                target[j++] = c;
                break;
        }
    }
    target[j] = '\0';   // Terminate the string
}

/*
** unescape: Copies a source string to a target string. During this process all
**  newline and tab characters are unescaped.
**
** @param source: source string
*/

void unescape(char target[], char source[]) {
    int c;
    int i,j = 0;
    while ((c = source[i++]) != '\0') {
        switch (c) {
            case '\\':
                if (source[i] == 'n') {
                    target[j++] = '\n';
                } else if (source[i] == 't') {
                    target[j++] = '\t';
                }
                break;
            default:
                target[j++] = c;
                break;
        }
    }
    target[j] = '\0';
}

/*
** getinput: Get an input string from the user via stdin.
** 
** @param inputString: Array that stores the users input.
 
** @return: nothing
*/
void getinput(char input[]) {
    int c;
    int i = 0;
    
    while ((c = getchar()) != EOF) {
        input[i++] = c;
    }
}
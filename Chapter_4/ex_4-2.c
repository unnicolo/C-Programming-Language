/**
 * Exercise 4-2 - The C Programming Language
 * Created 31.05.2017
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

// prototypes
double atof1(char string[]);
int getline1(char string[], int line_limit);

int main(void) {
    char line[MAXLINE];
    double result;
    while (getline1(line, MAXLINE) > 0) {
        result = atof1(line);
        printf("The number entered is: %10f\n", result);
    }
    return 0;
}

// atof: convert string s to double
double atof1(char s[]) {
    double value, power, exp_value;
    int i, sign, exp_sign;
    
    // skip white space
    for (i = 0; isspace(s[i]); i++) {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (value = 0.0; isdigit(s[i]); i++) {
        value = 10.0 * value + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        value = 10.0 * value + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-' ? -1 : 1);
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        for (exp_value = 0.0; isdigit(s[i]); i++) {
            exp_value = 10.0 * exp_value + (s[i] - '0');
        }
        for ( ; exp_value > 0; exp_value--) {
            if (exp_sign > 0) {
                value *= 10;
            } else {
                value /= 10;
            }
        }
    }
    return sign * value / power;
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


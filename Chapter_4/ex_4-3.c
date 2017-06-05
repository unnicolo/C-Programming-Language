/*
 * Reverse Polish Calculator
 * Section 4.3 - The C Programming Language
 */

#include <stdio.h>
#include<stdlib.h>      // for atof()

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found

int getop(char []);
void push(double);
double pop(void);

// reverse polish calculator
int main(void) {
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: division by zero\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push((int)pop() % (int)op2);
                } else {
                    printf("error: modulo by zero\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100      // maximum depth of val stack

int sp = 0;
double val[MAXVAL];      // value stack
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

// pop: pop and return top value from stack
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch1(int);

// getop: get next operator or numeric operand
int getop(char s[]) {
    int i, c, next;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        // not a number but maybe a unary minus character
        return c;
    }
    i = 0;
    if (c == '-') {
        next = getch();
        if (!isdigit(next) && next != '.') {
            return c;
        }
        c = next;
    } else {
        c = getch();
    }
    // collect integer part
    while (isdigit(s[++i] = c)) {
        c = getch();
    }
    // collect fraction part
    if (c == '.') {
        while (isdigit(s[++i] = c)) {
            c = getch();
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch1(c);
    }
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

// getch: get a (possibly pushed back) character
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch1(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

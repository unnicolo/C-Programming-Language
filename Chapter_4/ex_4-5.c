/*
 * Reverse Polish Calculator
 * Section 4.3 - The C Programming Language
 */

#include <stdio.h>
#include <stdlib.h>      // for atof()
#include <string.h>
#include <math.h>

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define FUNCTION '1'

#define PEEK '#'
#define SWAP ';'
#define DUPL ':'
#define CLEAR '!'

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void clear1(void);
void swap(void);
void duplicateTop(void);
void handleFunction(char []);

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
            case FUNCTION:
                handleFunction(s);
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
            case PEEK:
                // peek top value of the stack
                printf("\t%.8g peek value\n", peek());
                break;
            case DUPL:
                // duplicate the top value of the stack
                duplicateTop();
                break;
            case SWAP:
                swap();
                break;
            case CLEAR:
                clear1();
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

// handleFunction: check if the token is a supported function
//  if the function name is supported, take the appropriate action
//  otherwise inform the user that we don't support this function (yet)
void handleFunction(char s[]) {
    if (strcmp("sin", s) == 0) {
        double op = pop();
        push(sin(op));
    } else if (strcmp("cos", s) == 0) {
        double op = pop();
        push(cos(op));
    } else if (strcmp("pow", s) == 0) {
        double y = pop();
        double x = pop();
        push(pow(x, y));
    } else if (strcmp("exp", s) == 0) {
        double x = pop();
        push(exp(x));
    }
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

// clear: clear the entire stack
void clear1(void) {
    while(sp > 0) {
        pop();
    }
}

// peek: look at the top value of the stack
double peek(void) {
    // since sp is the next *free* position, we return the element before it
    return val[sp-1];
}

void swap(void) {
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
}

// duplicateTop: duplicate the topmost element
void duplicateTop(void) {
    push(peek());
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
    
    i = 0;
    if (isalpha(c)) {
        s[i] = c;
        while (isalpha(c = getch())) {
            s[++i] = c;
        }
        s[++i] = '\0';
        if (c != EOF) {
            ungetch1(c);
        }
        return FUNCTION;
    }
    if (!isdigit(c) && c != '.' && c != '-') {
        // not a number but maybe a unary minus character
        return c;
    }
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

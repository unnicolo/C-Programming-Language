/*
**  Exercise 2-7 - The C Programming Language
**  Created 15.05.2016
*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);  // prototype

int main(void) {
    unsigned x, p, n;    // example variables - hard-coded!
    x = 421;
    p = 6;
    n = 5;
    unsigned res;           // result variable
    res = invert(x, p, n);
    printf("inverted bits are now %u\n", res);
    printf("expected result is: 473\n");
    
    unsigned x2, p2, n2;
    x2 = 255;
    p2 = 7;
    n2 = 1;
    unsigned res2;
    res2 = invert(x2, p2, n2);
    printf("inverted bits are now %u\n", res2);
    printf("expected result is: 127\n");
}

/*  
**  invert: return x with the n bits starting at position p inverted
**      leaving the other bits unchanged
*/
unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0U << n) << (p+1-n));
}
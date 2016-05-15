/*
**  Exercise 2-6 - The C Programming Language
**  Created 13.05.2016
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y); // prototype
unsigned getbits(unsigned x, int p, int n); // prototype

int main(void) {
    unsigned x, p, n, y;    // example variables - hard-coded!
    x = 50;
    p = 3;
    n = 2;
    y = 3;
    unsigned res;           // result variable
    res = setbits(x, p, n, y);
    printf("the bits of x are now %u\n", res);
}

/*  getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

/*  setbits: returns an integer x with the n bits that begin at position p
**  set to the rightmost n bits of y, leaving the other bits unchanged
*/
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned tmp;   // temporary placeholder
    tmp = getbits(y, n-1, n);     // isolate the bits from y
    return x | (tmp << n);      // shift the bits into place and combine
}
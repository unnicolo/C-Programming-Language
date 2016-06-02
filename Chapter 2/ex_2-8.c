/*
**  Exercise 2-6 - The C Programming Language
**  Created 13.05.2016
*/

#include <stdio.h>

unsigned rightrot(unsigned x, int n);   // prototype

int main(void) {
    unsigned x, res;
    int n;
    x = 1024;
    n = 2;
    res = rightrot(x, n);
    printf("%u rotated by %i yields %u\n", x, n, res);    // should yield 256
    printf("expected value is 256\n");
}

/*  rightrot: returns the value of x rotated to the right by n bit positions
**      n is assumed to be a valid number
*/
unsigned rightrot(unsigned x, int n) {
    return x >> n;
}
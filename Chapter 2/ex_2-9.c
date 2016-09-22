/*
**  Exercise 2-6 - The C Programming Language
**  Created 13.05.2016
*/

#include <stdio.h>

int bitcount(int x);

int main(void) {
    unsigned x = 7; // expect 3 1-bits here
    unsigned result;
    result = bitcount(x);
    printf("The number of 1-bits in %i are %i\n", x, result);
    
    return 0;
}

/*  bitcount: count 1 bits in x
        This version is faster than shifting by 1 bit to the right at a time
        and checking if it matches with 1 in binary because
        
        if the rightmost bit is a 1 -> it becomes 0 and thus it can be 1
        with a bitwise comparison.
        
        otherwise, by decrementing by 1, all the 0 bits become 1 bits again
        until we reach the rightmost 1 bit, which changes to 0.
        All the bits that have changed now cannot be equal in an AND comparison
        and therefore are set to 0.

*/
int bitcount(int x) {
    unsigned counter = 0;
    while (x != 0) {
        x &= (x-1);
        ++counter;
    }
    return counter;
}
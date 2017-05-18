/**
 ** Exercise 3-5 - The C Programming Language
 ** Created 18.05.2017
 */

#include <stdio.h>
#include <math.h>

#define MAXSIZE 1000

// prototypes
void itob1(int n, char s[], int b);
void itob2(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
    int n = -150;
    char s[MAXSIZE];
    int b = 22;
    
    itob1(n, s, b);
    printf("Integer %d in base %d is: %s\n", n, b, s);
    itob2(n, s, b);
    printf("Integer %d in base %d is: %s\n", n, b, s);
    
    n = 2017;
    b = 16;
    itob1(n, s, b);
    printf("Integer %d in base %d is: %s\n", n, b, s);
    itob2(n, s, b);
    printf("Integer %d in base %d is: %s\n", n, b, s);
    
    n = 2017;
    b = 10;
    itob1(n, s, b);
    printf("Integer %d in base %d is: %s\n", n, b, s);
    itob2(n, s, b);
    printf("Integer %d in base %d is: %s\n", n, b, s);
    
    n = 193;
    b = 8;
    itob1(n, s, b);
    printf("Integer %d in base %d is: %s\n", n, b, s);
    itob2(n, s, b);
    printf("Integer %d in base %d is: %s\n", n, b, s);
    
    return 0;
}

// itob1: Convert integer n to a base b character representation in s.
void itob1(int n, char s[], int b) {
    int i, x, wholes;
    
    char bases[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    if (b < 2 || b > 36) {
        printf("can't convert into this basis\n");
        return;
    }
    
    i = 0;
    
    // in case we have to convert a negative number, simply flip the sign and append a '-'
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    
    // find the largest x such that b^x <= n && b^(x+1) > n
    x = 0;
    while (pow(b, x+1) <= n) {
        x += 1;
    }
    
    while (x >= 0) {
        // This is the case where n < b but there a still powers left to evaluate
        if (x > 0 && n < b) {
            s[i++] = '0';
        } else if (n < b) {
            s[i++] = bases[n];
        } else {
            wholes = floor(n/pow(b, x));
            s[i++] = bases[wholes];
            n -= wholes * pow(b, x);
        }
        x -= 1;
    }
    s[i] = '\0';
}

// itob2: Same as itob1 but with a different approach
void itob2(int n, char s[], int b) {
    int i, sign, remainder;
    
    char bases[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    if (b < 2 || b > 36) {
        return;
    }
    
    i = 0;
    sign = n;
    
    do {
        remainder = n % b;
        s[i++] = (sign < 0) ? bases[-remainder] : bases[remainder];
    } while (n /= b);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    int tmp;
    
    for (j = 0; s[j] != '\0'; ++j)
        ;
    --j;
    
    for (i = 0; i < j; ++i, --j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
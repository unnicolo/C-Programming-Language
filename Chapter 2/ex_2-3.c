/*
**  Exercise 2.3 - The C Programming Language
**  Write the function htoi(s), which converts a string of
**  hexadecimal digits (including an optional 0x or 0X) into its
**  equivalent integer value.
**  !strings are assumed to be given in little endian!
*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXSIZE 50  // maximum of 50 characters

int htoi(char hex_string[]);
void string_lower(char string[]);

int main(void)
{
    char s[] = "0XFA327";           // as integer: 467887
    int i;  // counter variable
    int c;
    long n;
    
    n = htoi(s);
    printf("%li", n);
    printf("\n");
}

/* htoi: converts a string of hex-digits into its integer equivalent */
int htoi(char s[])
{
    int i, c;
    long n, debug_res;
    
    string_lower(s);
    if (s[0] == '0' && s[1] == 'x') {   // check if 0X or 0x is leading prefix
        i = 2;  // begin transforming at 3rd character
    } else
        i = 0;
        
    n = 0;
    for (int j = 0; i<MAXSIZE-1 && (c=s[i]) != '\0'; ++i, ++j) {
        if (!isxdigit(c))
            printf("Invalid hex character... Program termination\n");
        if (isdigit(c))
            n += (c - '0') * pow(16, j);
        else if (isalpha(c))
            n += (c - 'a' + 10) * pow(16, j);
    }
    return n;
}

/*  string_lower: converts a string to lower-case */
void string_lower(char s[])
{
    int i, c;
    for (i = 0; i<MAXSIZE-1 && (c=s[i]) != '\0'; ++i)
        s[i] = tolower(c);  // convert all letters to lower case
}
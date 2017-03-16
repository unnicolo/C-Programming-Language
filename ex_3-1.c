/**
** Exercise 3-1 - The C Programming Language
** Created 04.11.2016
*/

#include <stdio.h>

int binarysearch(int x, long long array[], long long n);
void constructHugeArray(long long array[], long long n);

int main(void) {
    long long MAX_NUM = 100000000000000000;
    long long int numbers[MAX_NUM];    // 1 million numbers from 0 to 999999
    int numberToFind = 3;
    short returnValue;
    
    constructHugeArray(numbers, MAX_NUM);
    returnValue = binarysearch(numberToFind, numbers, MAX_NUM);
    if (returnValue == -1) {
        printf("Value %i is not contained in the array\n", numberToFind);
    } else {
        printf("Value %i has been found at index %i\n", numberToFind, returnValue);
    }
}

/**
**  binarysearch: performs a binary search on the input array.
**  returns the index of the value or -1 if the value is not found.
*/
int binarysearch(int x, long long array[], long long n) {
    long long low, mid, high;
    
    low = 0;
    high = n - 1;
    mid = (low + mid) / 2;
    while ((low <= high) && (x != array[mid])) {
        if (x < array[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (x == array[mid]) {
        return mid;
    } else {
        return -1;
    }
}

void constructHugeArray(long long array[], long long n) {
    long long i = 0;
    for (; i < n; ++i) {
        array[i] = i;
    }
}
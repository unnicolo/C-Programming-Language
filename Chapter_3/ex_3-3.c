/**
 ** Exercise 3-1 - The C Programming Language
 ** Created 06.04.2017
 */

#include <stdio.h>

#define MAXSIZE 1000

// prototypes
int string_length(char string[]);
int is_digit(char c);
int is_alphabetic(char c);
void print_range(int start, int end);
void expand(char input[], char output[]);
void get_input(char input[]);

int main(void) {
    //	char string[] = "This is the final countdown.";
    //	int start = '2';
    //	int end = '8';
    //	int start2 = 'a';
    //	int end2 = 'z';
    //	printf("%i\n", string_length(string));
    //	print_range(start, end);
    //	print_range(start2, end2);
    char input[] = "--a-c-6-8-";
    expand(input, input);
    printf("\n");
}

/*
 * expand: given an input string specifiying ranges of digits and letters
 * 	expand it into the full string and store the result in output. leading and trailing '-' are treated
 * 	literally.
 * 	for example:
 * 	a-z will give abc...xyz
 * 	0-9 will give 012...789
 * 	-a-d- will give -abcd-
 * 	-a-d7-9 will give -abcd789
 * 	etc.
 */
void expand(char input[], char output[]) {
    int digit_range = 0, letter_range = 0;
    int start = 0, end = 0;
    int length;
    int index = 0;
    
    length = string_length(input);
    while (index < length) {
        int current_char = input[index];
        if (!digit_range && !letter_range) { // not in a range
            if (current_char == '-') {
                printf("-");
                ++index;
            } else if (is_alphabetic(current_char)) { // start of a letter range
                letter_range = 1;
                start = current_char;
                end = start;
            } else if (is_digit(current_char)) { // start of a digit range
                digit_range = 1;
                start = current_char;
                end = start;
            } else {
                printf("Error in input!");
                break;
            }
        } else if (letter_range && !digit_range) {
            // Depending on the input there are now several cases while being in a letter range
            // (a) the next char is a '-' and immediately following is a letter:
            //      this is just a vanilla range, so we update the end value of the range
            // (b) the next char is a '-' and immediately following is a digit:
            //      in this case we complete the existing range and signal that we are not
            //      in a letter_range anymore
            // (c) the next char is alphabetic
            //      just expand the range-so-far and set the start point to next char
            // (d) the next char is a digit
            //      end of the letter range-so-far -> expand range and indicate end of letter_range
            // (e) the last char is a '-'
            //      put the value in 'start' into output and indicate end of letter_range
            // (f) still in a letter range and at the end of the string
            //      just expand the current range
            if (index < (length - 2)) { // we still have at least 2 chars to examine
                // cases (a), (b), (c), (d)
                int next = input[index + 1];
                int next_next = input[index + 2];
                if (next == '-' && is_alphabetic(next_next)) {
                    // (a)
                    if (next_next > end) {
                    end = next_next;
                    }
                    index += 2;
                } else if (next == '-' && is_digit(next_next)) {
                    // (b)
                    print_range(start, end);
                    letter_range = 0;
                    ++index;
                } else if (is_alphabetic(next)) {
                    // (c)
                    print_range(start, end);
                    start = next;
                    end = start;
                    ++index;
                } else if (is_digit(next)) {
                    // (d)
                    print_range(start, end);
                    letter_range = 0;
                    ++index;
                }
            } else if (index < length - 1) {    // there is at least 1 char remaining
                // (e)
                int next = input[index + 1];
                if (next == '-') {
                    print_range(start, end);
                    letter_range = 0;
                    ++index;
                }
            } else {    // we are at the end of the string
                // (f)
                print_range(start, end);
                break;
            }
        } else if (digit_range) { // we are in a digit range now
            // Look above for the reasoning behind the cases - apply them analogously
            if (index < (length - 2)) {
                // cases (a), (b), (c), (d)
                int next = input[index + 1];
                int next_next = input[index + 2];
                if (next == '-' && is_digit(next_next)) {
                    // (a)
                    if (next_next > end) {
                    end = next_next;
                    }
                    index += 2;
                } else if (next == '-' && is_alphabetic(next_next)) {
                    // (b)
                    print_range(start, end);
                    digit_range = 0;
                    ++index;
                } else if (is_digit(next)) {
                    // (c)
                    print_range(start, end);
                    start = next;
                    end = start;
                    ++index;
                } else if (is_alphabetic(next)) {
                    // (d)
                    print_range(start, end);
                    digit_range = 0;
                    ++index;
                }
            } else if (index < length - 1) {    // there is at least 1 char remaining
                // (e)
                int next = input[index + 1];
                if (next == '-') {
                    print_range(start, end);
                    letter_range = 0;
                    ++index;
                }
            } else {    // we are at the end of the string
                // (f)
                print_range(start, end);
                break;
            }
        }
    }	
}

int string_length(char string[]) {
    int length = 0;
    int i = 0;
    while (string[i] != '\0') {
        ++length;
        ++i;
    }
    return length;
}

int is_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int is_alphabetic(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }
    return 0;
}

void print_range(int start, int end) {
    int i = start;
    while (i <= end) {
        printf("%c", i);
        ++i;
    }
}

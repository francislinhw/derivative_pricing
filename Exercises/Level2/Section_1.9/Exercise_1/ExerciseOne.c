// Tip: getchar() reads and putchar() writes the type int. The value of ^A is 1. Exercise 2
// Create a C-program that reads the characters from the keyboard and shows them on
// screen (the inputted characters should only be displayed when the user hits 'enter', line
// by line).
// When ^A is entered, the program must end properly. Then the following message will
// appear: “CTRL + A is a correct ending.
#include <stdio.h>

int main() {
    int ch;

    printf("Enter text (CTRL + A to end):\n");
    while ((ch = getchar()) != 1) {  // 1 is the value of CTRL+A
        if (ch == '\n') { // Display characters when 'enter' is hit
            putchar(ch);  // putchar() Writes the type int
        } else {
            putchar(ch);  // putchar() Writes the type int
        }
    }

    printf("\nCTRL + A is a correct ending.\n");
    return 0;
}

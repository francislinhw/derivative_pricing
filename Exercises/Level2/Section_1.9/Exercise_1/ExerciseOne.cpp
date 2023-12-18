#include <stdio.h>

int main() {
    int ch;

    printf("Enter text (CTRL+A to end):\n");
    while ((ch = getchar()) != 1) {  // 1 is the value of CTRL+A
        if (ch == '\n') { // Display characters when 'enter' is hit
            putchar(ch);
        } else {
            putchar(ch);
        }
    }

    printf("\nCTRL + A is a correct ending.\n");
    return 0;
}

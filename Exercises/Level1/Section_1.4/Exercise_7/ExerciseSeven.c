#include <stdio.h>
#include <ctype.h>

int main() {
    int count[5] = {0, 0, 0, 0, 0}; // Counters for numbers 0-4
    int otherCount = 0; // Counter for other characters
    int ch;

    printf("Enter numbers (press CTRL+D to submit):\n");

    while ((ch = getchar()) != EOF) {
        switch (ch) {
            case '0': count[0]++; break;
            case '1': count[1]++; break;
            case '2': count[2]++; break;
            case '3': count[3]++; break;
            case '4': count[4]++; break;
            default:
                if (!isspace(ch)) {
                    otherCount++;
                };
                break;
        }
    }

    // Handling the special case for the number 3
    for (int i = 0; i < 5; i++) {
        if (i != 3) {
            printf("Number %d: %d\n", i, count[i]);
        } else {
            if (count[3] < 3) {
                switch (count[3]) {
                    case 0: printf("Number three appears zero times.\n"); break;
                    case 1: printf("Number three appears one time.\n"); break;
                    case 2: printf("Number three appears two times.\n"); break;
                }
            } else {
                printf("The number three appears more than two times.\n");
            }
        }
    }
    printf("Other characters: %d\n", otherCount);

    return 0;
}

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

    printf("\nNumber of times each number was typed:\n");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: %d\n", i, count[i]);
    }
    printf("Other characters: %d\n", otherCount);

    return 0;
}

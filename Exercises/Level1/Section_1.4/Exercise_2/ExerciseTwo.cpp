#include <stdio.h>
#include <ctype.h> // For isspace()

int main() {
    int characters = 0, words = 0, lines = 0;
    int ch, lastChar = ' ';

    printf("Enter text (press CTRL+D to submit):\n");

    do {
        ch = getchar();

        // Check for EOF
        if (ch == EOF) {
            break;
        }

        // Count characters excluding spaces and EOF
        if (!isspace(ch)) {
            characters++;
        }

        // Count lines on newline characters
        if (ch == '\n') {
            lines++;
        }

        // Check for transitions from space to non-space to count words
        if (isspace(lastChar) && !isspace(ch)) {
            words++;
        }

        lastChar = ch; // Update last character
    } while (1);

    // Output results
    printf("\nCharacters (excluding spaces and EOF): %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}

#include <stdio.h>
#include <ctype.h> // For isspace()

int main() {
    int characters = 0, words = 0, lines = 0;
    int ch, lastChar = ' ';

    printf("Enter text (press CTRL+D to submit):\n");

    while ((ch = getchar()) != EOF) {
        // Using switch-case to handle different character types
        switch (ch) {
            case '\n': // Newline character
                lines++;
                // Fall through to also count it as a space for word counting
            case ' ':  // Space
            case '\t': // Tab
                if (!isspace(lastChar)) {
                    words++;
                }
                break;
            default:   // Regular character
                if (!isspace(ch)) {
                    characters++;
                }
                break;
        }
        lastChar = ch; // Update last character
    }

    // Output results
    printf("\nCharacters (excluding spaces and EOF): %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}

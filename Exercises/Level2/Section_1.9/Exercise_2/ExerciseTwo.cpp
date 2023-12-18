#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int ch;
    char filename[100];
    FILE *file;

    printf("Enter the filename to write to: ");
    fgets(filename, sizeof(filename), stdin); // Read the filename including empty space 'The exercise.txt'

    // Remove trailing newline character if present
    if (filename[0] != '\n' && filename[strlen(filename) - 1] == '\n') {
        filename[strlen(filename) - 1] = '\0';
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Enter text (CTRL+A to end):\n");
    while ((ch = getchar()) != 1) {  // 1 is the value of CTRL+A
        fputc(ch, file);
    }

    printf("CTRL + A is a correct ending.\n");

    fclose(file);
    return 0;
}

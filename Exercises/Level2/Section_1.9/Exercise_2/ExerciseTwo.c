// Alter the last program of exercise 1 in such a way that the output doesn’t go to the screen
// but is written to a file. The file to write to must be specified by the user.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int ch;
    char filename[100]; // To store the filename (up to 99 characters plus null terminator)
    FILE *file; // FILE pointer for file operations

    printf("Enter the filename to write to: ");
    // Read the filename including empty space 'The Exercise Two.txt' from stdin (Standard Input)
    fgets(filename, sizeof(filename), stdin);

    // Remove trailing newline character if present
    if (filename[0] != '\n' && filename[strlen(filename) - 1] == '\n') {
        filename[strlen(filename) - 1] = '\0';
    }

    // Open the file for writing
    file = fopen(filename, "w");
    if (file == NULL) { // Check if the file was successfully opened
        perror("Error opening file");
        return 1; // Exit the program with a non-zero value indicating an error
    }

    printf("Enter text (CTRL+A to end):\n");
    while ((ch = getchar()) != 1) {  // 1 is the value of CTRL+A
        fputc(ch, file); // Write each character to the file
    }

    printf("CTRL + A is a correct ending.\n");
    // Close the file
    fclose(file);
    return 0;
}

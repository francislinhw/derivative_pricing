// The following program reads a string with a 30 character maximum. Implement
// the Length() function. The function Length() must determine the length of the string.
// Give Length() the address of the array as argument.

#include <stdio.h>
#define MAXLINE 30

int Length(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        // Count every char
        length++;
    }
    return length;
}

int main() {
    char string[MAXLINE + 1];
    int c, i = 0;
    printf("Type up to %d chars. Exit with CTRL+D\n", MAXLINE);
    while ((c = getchar()) != EOF && i < MAXLINE) {
        string[i++] = (char)c;
    }
    string[i] = '\0'; // String must be closed with \0
    printf("String length is %d\n", Length(string)); // My Length function
    return 0;
}

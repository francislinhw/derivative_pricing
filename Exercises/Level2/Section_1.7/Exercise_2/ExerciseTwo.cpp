#include <stdio.h>
#define MAXLINE 30

int Length(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char string[MAXLINE + 1];
    int c, i = 0;
    printf("Type up to %d chars. Exit with ^D\n", MAXLINE);
    while ((c = getchar()) != EOF && i < MAXLINE) {
        string[i++] = (char)c;
    }
    string[i] = '\0';
    printf("String length is %d\n", Length(string));
    return 0;
}

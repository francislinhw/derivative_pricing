#include <stdio.h>

void printnumber(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10 != 0) {
        printnumber(n / 10); // Recursive call for the next digit
    }
    putchar(n % 10 + '0'); // Print the last digit
}

int main() {
    int num = -123450;
    printnumber(num);
    putchar('\n');
    return 0;
}

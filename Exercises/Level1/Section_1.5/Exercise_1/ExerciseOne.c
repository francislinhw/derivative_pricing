#include <stdio.h>

int minus(int a, int b) {
    return a - b;
}

int main() {
    int x = 15, y = 10;
    int result = minus(x, y);
    printf("Difference: %d\n", result);
    return 0;
}

#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i = 123, j = 456;
    printf("Before swap: i = %d, j = %d\n", i, j);
    Swap(&i, &j);
    printf("After swap: i = %d, j = %d\n", i, j);
    return 0;
}

#include <stdio.h>

int main() {
    int i = 5;
    int pre, post;

    // Demonstrating pre-decrement (--i)
    printf("Initial value of i: %d\n", i);
    pre = --i; // i is decremented first, then the new value is assigned to pre
    printf("After pre-decrement (--i), i: %d, pre: %d\n", i, pre);

    // Resetting i to 5
    i = 5;

    // Demonstrating post-decrement (i--)
    printf("Reset value of i: %d\n", i);
    post = i--; // the original value of i is assigned to post, then i is decremented
    printf("After post-decrement (i--), i: %d, post: %d\n", i, post);

    return 0;
}

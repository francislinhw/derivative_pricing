/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a) printf("%d", (a) )
#define NL          printf("\n");
// Create and initialse array
int a[]={0, 1, 2, 3, 4};
int main() {
    int i;
    int* p;
    // Iterate through the array using an index and print each element.
    for (i=0; i<=4; i++) PRD(a[i]); // Prints: 01234
    NL;
    // Iterate through the array using a pointer and print each element.
    for (p=&a[0]; p<=&a[4]; p++) PRD(*p); // Prints: 01234
    NL;
    // Extra new line
    NL;
    // Iterate using a pointer and index. The pointer points to the start, the index accesses each element.
    for (p=&a[0], i=0; i<=4; i++) PRD(p[i]); // Prints: 01234
    NL;
    // Iterate using a combination of pointer arithmetic and index. 
    // In this case, the condition `p+i<=a+4` is only valid for i = 0, 1 and 2, where p+i is 0, 2, and 4
    for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); // Prints: 024
    NL;
    // Extra new line
    NL;
    // Iterate backwards from the end of the array using a pointer.
    for (p=a+4; p>=a; p--) PRD(*p); // Prints: 43210
    NL;
    // Iterate backwards using negative indexing on the pointer.
    for (p=a+4, i=0; i<=4; i++) PRD(p[-i]); // Prints: 43210
    NL;
    // Iterate backwards using the pointer difference to calculate the index.
    for (p=a+4; p>=a; p--) PRD(a[p-a]); // Prints: 43210
    NL;
    return 0;
    /**
     * 01234
     * 01234
     * 
     * 01234
     * 024
     * 
     * 43210
     * 43210
     * 43210
    */
}
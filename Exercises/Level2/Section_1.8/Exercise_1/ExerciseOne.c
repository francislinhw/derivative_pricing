// Write a C-program that prints the contents of a struct called Article. An Article has the following characteristics:
// • Article number
// • Quantity
// • Description (20 characters)
// The test program must create an Article of which the contents are assigned at initialization level.
// Printing the Article is done with a Print() function. This function gets the address of the structure as a parameter.
// Tip: Suppose that p is the pointer to the structure. It will allow the fields to be printed by (*p).fieldname or p->fieldname.
#include <stdio.h>
#define DESCRIPTION_LENGTH 20

typedef struct {
    int articleNumber;
    int quantity;
    char description[DESCRIPTION_LENGTH];
} Article;

// Call by reference
void Print(const Article *p) {
    printf("Article Number: %d\n", p->articleNumber);
    printf("Quantity: %d\n", p->quantity);
    printf("Description: %s\n", p->description);
}

int main() {
    // Initialize an Article
    Article myArticle = {123, 50, "Exercise One"};

    // Print the Article
    Print(&myArticle);

    return 0;
}

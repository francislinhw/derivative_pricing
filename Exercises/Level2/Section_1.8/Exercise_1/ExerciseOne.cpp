#include <stdio.h>

#define DESCRIPTION_LENGTH 20

typedef struct {
    int articleNumber;
    int quantity;
    char description[DESCRIPTION_LENGTH];
} Article;

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

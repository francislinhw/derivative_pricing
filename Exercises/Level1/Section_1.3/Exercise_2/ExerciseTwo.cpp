#include <stdio.h>

double calculateSurface(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    double base, height;

    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);

    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);

    double surface = calculateSurface(base, height);

    printf("The surface of the triangle is: %lf\n", surface);

    return 0;
}

#include "Point.hpp"
#include <iostream>

int main() {
    Point p;
    double x, y;

    std::cout << "Enter the x-coordinate: ";
    std::cin >> x;
    std::cout << "Enter the y-coordinate: ";
    std::cin >> y;

    p.SetX(x);
    p.SetY(y);

    std::cout << p.ToString() << std::endl;
    std::cout << "X: " << p.GetX() << ", Y: " << p.GetY() << std::endl;

    return 0;
}

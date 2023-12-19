#include <iostream>
#include <cmath>
#include "Point.hpp"

int main() {
    Point p1;
    Point p2(3.0, 4.0);
    p1.X(3.0); // Set X by default inline function.
    p1.Y(4.0); // Set Y by default inline function.

    std::cout << "Point 1 X:" << p1.X() << ", Y: " << p1.Y() << std::endl; // Get X and Y by Normal inline function.
    std::cout << "Distance between Points: " << p1.Distance(p2) << std::endl;

    return 0;
}
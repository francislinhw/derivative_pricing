#include "Circle.hpp"
#include "Point.hpp"
#include <iostream>

int main() {
    Point center(1.0, 2.0);
    double radius = 5.0;
    
    Circle circle(center, radius);

    std::cout << circle.ToString() << std::endl;
    std::cout << "Diameter: " << circle.Diameter() << std::endl;
    std::cout << "Area: " << circle.Area() << std::endl;
    std::cout << "Circumference: " << circle.Circumference() << std::endl;

    return 0;
}

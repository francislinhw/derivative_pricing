#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    Point p1(1, 2);
    Line l1(Point(), Point(1, 1));
    Circle c1(p1, 5);

    std::cout << "Point: " << p1 << std::endl;
    std::cout << "Line: " << l1 << std::endl;
    std::cout << "Circle: " << c1 << std::endl;

    return 0;
}

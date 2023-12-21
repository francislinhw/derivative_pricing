#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    // Create Point objects
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);

    // Use the friend ostream << operator to output Point details
    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p2: " << p2 << std::endl;

    // Create a Line object using two Points
    Line line(p1, p2);

    // Use the friend ostream << operator to output Line details
    std::cout << "Line: " << line << std::endl;

    // Create a Circle object using Point and double
    Circle circle(p1, 2);

    // Use the friend ostream << operator to output circle details
    std::cout << "Circle: " << circle << std::endl;

    return 0;
}

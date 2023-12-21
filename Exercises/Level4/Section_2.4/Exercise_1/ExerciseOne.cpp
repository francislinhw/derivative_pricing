#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

int main() {
    std::cout << "\nTesting Point\n" << std::endl;
    Point p0; // Default constructor
    std::cout << "Point p0: " << p0.ToString() << std::endl;
    Point p1(1, 2), p2(3, 4);
    std::cout << "Point p1: " << p1.ToString() << std::endl;
    Point p3 = p1 + p2; // Add coordinates
    Point p4 = p2 - p1; // Subtract coordinates
    Point p5 = -p2;     // Negate coordinates
    Point p6 = p1 * 2;  // Scale coordinates
    bool p1Eqlp2 = (p1 == p2); // Compare points for equality
    bool p1Eqlp1 = (p1 == p1); // Compare points for equality
    p0 = p1; // Assign p1 to p0
    p1 *= 2; // Scale p1 coordinates and assign
    std::cout << "Point p2: " << p2.ToString() << std::endl;
    std::cout << "Point p3 (p1 + p2): " << p3.ToString() << std::endl;
    std::cout << "Point p4 (p2 - p1): " << p4.ToString() << std::endl;
    std::cout << "Point p5 (-p2): " << p5.ToString() << std::endl;
    std::cout << "Point p6 (p1 * 2): " << p6.ToString() << std::endl;
    std::cout << "Are p1 and p2 equal? " << (p1Eqlp2 ? "Yes" : "No") << std::endl;
    std::cout << "Are p1 and p1 equal? " << (p1Eqlp1 ? "Yes" : "No") << std::endl;
    std::cout << "Point p0 after (p0 = p1): " << p0.ToString() << std::endl;
    std::cout << "Scaled Point p1 after (p1 *= 2): " << p1.ToString() << std::endl;

    std::cout << "\nTesting Line\n" << std::endl;
    Line line1(p1, p2);
    std::cout << "Line 1: " << line1.ToString() << std::endl;
    Line line2 = line1 * 2; // Scale
    Line line3 = line1 + line2; // Add lines
    Line line4 = -line3; // Add lines
    Line line5 = line3 - line4; // Add lines
    bool areLinesEqual = (line1 == line2); // Equality check
    line1 = line2; // Assignment
    line1 *= 3; // Scale and assign
    std::cout << "Line 2: " << line2.ToString() << std::endl;
    std::cout << "Line 3: " << line3.ToString() << std::endl;
    std::cout << "Line 4: " << line4.ToString() << std::endl;
    std::cout << "Line 5: " << line5.ToString() << std::endl;
    std::cout << "Are lines 1 and 2 equal? " << (areLinesEqual ? "Yes" : "No") << std::endl;
    std::cout << "Line 1 after (line1 = line2): " << line1.ToString() << std::endl;

    std::cout << "\nTesting Circle\n" << std::endl;
    Circle circle1(p1, 5);
    Circle circle2 = circle1 * 2; // Scale
    Circle circle3 = circle1 + Circle(p3, 7); // Add circles
    bool areCirclesEqual = (circle1 == circle2); // Equality check
    circle1 = circle2; // Assignment
    circle1 *= 3; // Scale and assign
    std::cout << "Circle 1: " << circle1.ToString() << std::endl;
    std::cout << "Circle 2: " << circle2.ToString() << std::endl;
    std::cout << "Circle 3: " << circle3.ToString() << std::endl;
    std::cout << "Are circles 1 and 2 equal? " << (areCirclesEqual ? "Yes" : "No") << std::endl;

    return 0;
}

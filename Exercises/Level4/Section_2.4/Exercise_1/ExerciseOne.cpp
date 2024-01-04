// Exercise 1: Adding Operators to the Point class
// By supporting operators, you can make your classes easier and more natural to use. 
// However you must not “overuse” operators. 
// Only use operators if the functionality of the operator is clear without reading documentation.
// Thus adding mathematical operators to a complex number class is good
// but using a + operator with a double as an argument on a point to increase the x-coordinate is questionable.
// So use operators with care.
// In this exercise we add a few operators to the Point class.
// Most operators do not change the original objects but return the result as a new object.
// Normally only the = operator and += and variants change the original object. Add the following operators:
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
    Point p7;
    p7 = p6 *= 2; // To make it possible to chain the = and *= operators
    std::cout << "Point p2: " << p2.ToString() << std::endl;
    std::cout << "Point p3 (p1 + p2): " << p3.ToString() << std::endl;
    std::cout << "Point p4 (p2 - p1): " << p4.ToString() << std::endl;
    std::cout << "Point p5 (-p2): " << p5.ToString() << std::endl;
    std::cout << "Point p6 (p1 * 2): " << p6.ToString() << std::endl;
    std::cout << "Are p1 and p2 equal? " << (p1Eqlp2 ? "Yes" : "No") << std::endl;
    std::cout << "Are p1 and p1 equal? " << (p1Eqlp1 ? "Yes" : "No") << std::endl;
    std::cout << "Point p0 after (p0 = p1): " << p0.ToString() << std::endl;
    std::cout << "Scaled Point p1 after (p1 *= 2): " << p1.ToString() << std::endl;
    std::cout << "Scaled Point p7 after (p7 = p6 *= 2): " << p7.ToString() << std::endl;

    std::cout << "\nTesting Line\n" << std::endl;
    Line line1(p1, p2);
    std::cout << "Line 1: " << line1.ToString() << std::endl;
    Line line2 = line1 * 2; // Scale
    std::cout << "Line 2 (L1 * 2): " << line2.ToString() << std::endl;
    Line line3 = line1 + line2; // Add lines
    Line line4 = -line3; // Add lines
    Line line5 = line3 - line4; // Add lines
    bool areLinesEqual = (line1 == line2); // Equality check
    line1 = line2 *= 3; // Assign and Scale
    std::cout << "Line 3 (L1 + L2): " << line3.ToString() << std::endl;
    std::cout << "Line 4 (-L3): " << line4.ToString() << std::endl;
    std::cout << "Line 5 (L3 - L4): " << line5.ToString() << std::endl;
    std::cout << "Are lines 1 and 2 equal? " << (areLinesEqual ? "Yes" : "No") << std::endl;
    std::cout << "Line 1 after (line1 = line2 *= 3): " << line1.ToString() << std::endl;

    std::cout << "\nTesting Circle\n" << std::endl;
    Circle circle1(p1, 5);
    std::cout << "Circle 1: " << circle1.ToString() << std::endl;
    Circle circle2 = circle1 * 2; // Scale
    Circle circle3 = circle1 + Circle(p3, 7); // Add circles
    bool areCirclesEqual = (circle1 == circle2); // Equality check
    circle1 = circle2; // Assignment
    circle1 *= 3; // Scale and assign
    std::cout << "Circle 2 (circle2 = circle1 * 2): " << circle2.ToString() << std::endl;
    std::cout << "Circle 3 (circle3 = circle1 + Circle(p3, 7)): " << circle3.ToString() << std::endl;
    std::cout << "Are circles 1 and 2 equal? " << (areCirclesEqual ? "Yes" : "No") << std::endl;

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Testing Point
     * 
     * Point p0: Point(0, 0)
     * Point p1: Point(1, 2)
     * Point p2: Point(3, 4)
     * Point p3 (p1 + p2): Point(4, 6)
     * Point p4 (p2 - p1): Point(2, 2)
     * Point p5 (-p2): Point(-3, -4)
     * Point p6 (p1 * 2): Point(4, 8)
     * Are p1 and p2 equal? No
     * Are p1 and p1 equal? Yes
     * Point p0 after (p0 = p1): Point(1, 2)
     * Scaled Point p1 after (p1 *= 2): Point(2, 4)
     * Scaled Point p7 after (p7 = p6 *= 2): Point(4, 8)
     * 
     * Testing Line
     * 
     * Line 1: Line from Point(2, 4) to Point(3, 4)
     * Line 2 (L1 * 2): Line from Point(4, 8) to Point(6, 8)
     * Line 3 (L1 + L2): Line from Point(6, 12) to Point(9, 12)
     * Line 4 (-L3): Line from Point(-6, -12) to Point(-9, -12)
     * Line 5 (L3 - L4): Line from Point(12, 24) to Point(18, 24)
     * Are lines 1 and 2 equal? No
     * Line 1 after (line1 = line2 *= 3): Line from Point(12, 24) to Point(18, 24)
     * 
     * Testing Circle
     * 
     * Circle 1: Circle: Centre at Point(2, 4), Radius 5
     * Circle 2 (circle2 = circle1 * 2): Circle: Centre at Point(2, 4), Radius 10 // Only alter the radius.
     * Circle 3 (circle3 = circle1 + Circle(p3, 7)): Circle: Centre at Point(2, 4), Radius 12 // Only alter the radius.
     * Are circles 1 and 2 equal? No
     * 
     */
}

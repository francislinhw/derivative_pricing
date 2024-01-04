// Exercise 2: Ostream << Operator
// It would be nice if you could send a point or a line directly to the cout object without calling the ToString() method,
// just as with the primitive types.

// This is possible by adding a << operator function that has on the left an std::ostream and on the right the point or line object.
// Since you can’t add a member function to the std::ostream class,

// The implementation uses the << operator to send data to the os input argument.
// Since it is a global function, you can’t access the private members of Point.
// To simplify things, you can use the ToString() method of Point to get the string to send to the os argument.
// Also create a similar << operator for printing lines (and circles if you made a circle class).
// Adapt the test program to test the << operator for points and lines.

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
    /*
     * Answer: I printed objects by '<<' as primative type.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Point: Point(1, 2)
     * Line: Line from Point(0, 0) to Point(1, 1)
     * Circle: Circle: Centre at Point(1, 2), Radius 5
    */
}

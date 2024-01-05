// Exercise 1: Polymorphic ToString() Function
// The ToString() functions of Point and Line override the ToString() from the Shape base class.
// We saw that we could put a Point in a Shape* variable. But when calling
// the ToString() method on the Shape* variable, the function in Shape was called instead the one in Point.
// To make the compiler generate the required code to find out what type of object the 
// Shape*variable is actually pointing to so it can call the right version; we need to declare the function as virtual.
// Thus declare the ToString() function in the Shape class as virtual and test the program again.
// Is the ToString() function of Point called when you use a Shape* that contains a Point now?
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"

using namespace std;
using francis::CAD::Shape;
using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    francis::CAD::Shape* shapes[3];
    shapes[0] = new francis::CAD::Shape();
    shapes[1] = new francis::CAD::Point(10, 20);
    // Assume Line is another derived class of Shape
    shapes[2] = new francis::CAD::Line(Point(1,2), Point(3, 4));

    for (int i = 0; i < 3; ++i) {
        std::cout << shapes[i]->ToString() << std::endl;  // Will call the appropriate ToString
    }

    // Clean up
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
    /*
     * Answer: The ToString functions in inheritences (Line, Point, and Circle) are used correctly.
     *
     * ===================== *
     * PROGRAM OUTPUT (RAND) *
     * ===================== *
     * 
     * ID: 16807
     * Point(10, 20)ID: 282475249
     * Line from Point(1, 2) to Point(3, 4)
     * 
     * Notes: Using UUIDs in your C++ program for object identification aligns more with industry standards,
     * provides a robust method for ensuring uniqueness, and integrates well with scalable distributed systems.
     * 
     * ===================== *
     * PROGRAM OUTPUT (UUID) *
     * ===================== *
     * 
     * ID: 30110d1f-3e13-434d-a3e3-3b87b6cac744
     * Point(10, 20)ID: f3b37469-ebb8-4723-a3fa-9b52d89797bf
     * Line from Point(1, 2) to Point(3, 4)
     * 
    */
}

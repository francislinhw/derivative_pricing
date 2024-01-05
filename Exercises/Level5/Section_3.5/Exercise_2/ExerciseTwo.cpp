// Exercise 2: Calling Base Class Functionality
// The ToString() function of the Shape class is overridden in the derived classes.
// But for the derived class it is still possible to use the base class functionality.
// In the ToString() function of Point and Line we also want to incorporate the ID from theShape base class.
// • In the ToString() method of Point, call the ToString() method of the Shape base class: std::string s=Shape::ToString();
// • Append the shape description string to the point description string before returning.
// • Do this also for the ToString() function in the Line class (and Circle class).
// • Test the application again. Is now the ID printed when printing a point or line?
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
    Point p(10, 20);
    Circle c(Point(1, 2), 5);
    Line l(p, p);

    cout << p.ToString() << endl; // Should include the ID from Shape
    cout << c.ToString() << endl; // Should include the ID from Shape
    cout << l.ToString() << endl; // Should include the ID from Shape

    return 0;
    /*
     * Answer: Now the ID is printed when printing a point, line, and circle.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Point(10, 20)
     * Point ID: 16807
     * Circle: Centre at Point(1, 2), Radius 5
     * Circle ID: 1622650073
     * Line from Point(10, 20) to Point(10, 20)
     * Line ID: 1144108930
    */
}


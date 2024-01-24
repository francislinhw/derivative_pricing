// Exercise 3: Variant
// In contrast to tuple, a boost::variant stores one value that can be of one of the specified types.
// It is thus similar to a C union but it is type-safe.
// In this exercise we want to create a function that ask the user what kind of shape to create and returns that.
// In this case we can return the created shape as Shape* because all shapes have a common base class but that involves creating the shapes with new.
// Instead we can return the created shape a boost::variant which would also be needed if the shapes did not have a common base class.
// Thus create a typedef for a ShapeType variant that can contain a Point, Line or Circle.
// Next create a function that returns the variant. Within this function ask the user for the shape type to create.
// Then create the requested shape and assign it to the variant and return it.
// In the main program, call the function and print the result by sending it to cout.
// Next try to assign the variant to a Line variable by using the global boost:get<T>() function.
// This will throw a boost::bad_get exception when the variant didn’t contain a line.
// Test the application.
// Checking what kind a type is stored in the variant is cumbersome. Therefore the boost::variant supports visitors.
// A visitor is a class derived from boost::static_visitor<T> that has for each type that can be stored an operator () with the type as argument.
// The template argument is the return type of the operators ().
// Now create a variant visitor that moves the shapes.
// The visitor is derived from boost::static_visitor<void> and must have members for the x- and y-offset that are set in the constructor.
// For each shape, create an operator () that changes the coordinates of the shape. For example the function for Point is defined as:

/* 
 * // Visit a point.
 * void operator () (Point& p) const
 * { p.X(p.X()+m_dx);
 * } p.Y(p.Y()+m_dy);
 */

// In the main program, create an instance of the visitor and use the boost::apply_visitor(visitor, variant) global function to move the shape.
// Print the shape afterwards to check if the visitor indeed changed the coordinates.
#include <boost/variant.hpp>
#include <iostream>
#include <string>
#include "Point.hpp" // Assuming Point, Line, Circle classes are defined
#include "Line.hpp"
#include "Circle.hpp"
#include "MoveShapeVisitor.hpp"

using francis::CAD::Point;
using francis::CAD::Shape;
using francis::CAD::Circle;

using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType CreateShape() {
    int choice;
    std::cout << "Select shape type (1: Point, 2: Line, 3: Circle): ";
    std::cin >> choice;

    switch (choice) {
        case 1: return Point(0, 0);
        case 2: return Line(Point(0, 0), Point(1, 1));
        case 3: return Circle(Point(0, 0), 1.0);
        default: return Point(0, 0); // Default case
    }
}

int main() {
    try {
        ShapeType myShape = CreateShape();
        std::cout << myShape << std::endl;

        // Try to assign the variant to a Line variable
        Line myLine = boost::get<Line>(myShape);

        // Move the shape
        MoveShapeVisitor visitor(1.0, 1.0);
        boost::apply_visitor(visitor, myShape);
        std::cout << "After moving: " << myShape << std::endl;
    }
    catch (boost::bad_get& e) {
        std::cerr << "Error: Not a Line object." << std::endl;
    }

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Select shape type (1: Point, 2: Line, 3: Circle): 1
     * Point(0, 0)
     * Error: Not a Line object.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Select shape type (1: Point, 2: Line, 3: Circle): 2
     * Line from Point(0, 0) to Point(1, 1)
     * After moving: Line from Point(1, 1) to Point(2, 2)
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Select shape type (1: Point, 2: Line, 3: Circle): 3
     * Circle: Centre at Point(0, 0), Radius 1
     * Error: Not a Line object.
    */
}



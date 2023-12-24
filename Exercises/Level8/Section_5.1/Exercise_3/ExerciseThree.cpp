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
}



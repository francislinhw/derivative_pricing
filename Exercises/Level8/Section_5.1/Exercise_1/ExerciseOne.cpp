#include <boost/shared_ptr.hpp>
#include "Array.hpp"
#include "Shape.hpp"  // Include your Shape class header
#include "Point.hpp"  // Include other derived Shape classes if needed
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

using francis::CAD::Point;
using francis::CAD::Shape;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

void CreateShapes(ShapeArray& shapes) {
    shapes[0] = ShapePtr(new Point(1, 2));
    shapes[1] = ShapePtr(new Line(Point(1, 2), Point(3, 4)));
    shapes[2] = ShapePtr(new Circle(Point(0, 0), 5));
    // Add more shapes as needed
}

void PrintShapes(const ShapeArray& shapes) {
    for (int i = 0; i < shapes.Size(); ++i) {
        std::cout << shapes[i]->ToString() << std::endl;
    }
}

int main() {
    try {
        ShapeArray shapes(3); // Assuming you have a constructor that sets the size
        CreateShapes(shapes);
        PrintShapes(shapes);
    } catch (std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    // Shapes will be automatically deleted due to shared_ptr
    return 0;
}

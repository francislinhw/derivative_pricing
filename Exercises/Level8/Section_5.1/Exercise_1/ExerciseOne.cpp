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
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * bye my point.. (Destructor called).             // Delete Point for Start Point of Line after copy
     * bye my point.. (Destructor called).             // Delete Point for End Point of Line after copy
     * bye my point.. (Destructor called).             // Delete Point for Center of Circle after copy
     * Point(1, 2)                                     // Print Point in shape[0]
     * Point ID: e6bf32e1-a717-4017-bbe7-4843c78ea011
     * Line from Point(1, 2)                           // Print Line in shape[1]
     * Point ID: 7af096c1-75e0-43df-8939-2c3af2cbdcfb to Point(3, 4)
     * Point ID: b7ac41d4-8ee2-48c6-a1a5-650522f9f4f2
     * Line ID: 9f547dea-36ec-4083-b9f6-a6353d987409
     * Circle: Centre at Point(0, 0), Radius 5         // Print Circle in shape[2]
     * Circle ID: 54f2b5b7-aef1-43ce-91dc-14cdd807289b
     * bye my circle.. (Destructor called).            // Delete circle in shape[2]
     * bye my point.. (Destructor called).             // Delete the point in circle
     * bye my line.. (Destructor called).              // Delete the line in shape[1]
     * bye my point.. (Destructor called).             // Delete the start point in line
     * bye my point.. (Destructor called).             // Delete the end point in line
     * bye my point.. (Destructor called).             // Delete the point in shape[0]
    */
}

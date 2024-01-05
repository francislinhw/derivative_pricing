// Exercise 4: Abstract Functions
// Sometimes functions in the base class are only there to be overridden in the derived class.
// Assume that you want to draw all the shapes using the following code:
// Shape* shapes[10];
// shapes[0]=new Line;
// shapes[1]=new Point;
// ...
// shapes[9]=new Line(Point(1.0, 2.5), Point(3.4, 5.2));
// for (int i=0; i!=10; i++) shapes[i]->Draw(); for (int i=0; i!=10; i++) delete shapes[i];
// Create the Draw() function in the Shape base class and override it in the derived classes
// (point, line and if present the circle class).
// Simulate drawing by just printing some text.
// What implementation did you give the Draw() function in Shape?
// Shape is just an abstraction to work with various kinds of shapes like lines and circles.
// Shapes don’t have a physical appearance. Therefore its Draw() function will have an empty implementation.
// But better is to give it no implementation at all by making it a pure virtual member function:
// virtual void Draw()=0;
// Do this in your code. Try to create an instance of the Shape class. Is this possible?
// Now the Shape class is really an abstraction.
// You don’t make shape instances but you can still create shape pointers that point to concrete shapes like point and line.
// The Shape class is now an abstract base class.
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
    using namespace francis::CAD;

    // Shape s; // This will cause a compilation error because Shape is abstract
    Shape* shapes[10];
    shapes[0] = new Line;   // Assuming Line has a default constructor
    shapes[1] = new Point;  // Assuming Point has a default constructor
    shapes[2] = new Circle;
    shapes[3] = new Circle(Point(1.0), 1.0);
    shapes[4] = new Point;
    shapes[5] = new Point;
    shapes[6] = new Point;
    shapes[7] = new Point(1.0);
    shapes[8] = new Point(1.0, 2.5);
    shapes[9] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));

    for (int i = 0; i != 10; i++) {
        shapes[i]->Draw();
    }

    for (int i = 0; i != 10; i++) {
        delete shapes[i];
    }

    return 0;
    /*
     * Answer: This is not possible to create an instance for a pure abstract object.
     * error log: allocating an object of abstract class type 'francis::CAD::Shape'
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Draw Line.
     * Draw Point.
     * Draw Circle.
     * Draw Circle.
     * Draw Point.
     * Draw Point.
     * Draw Point.
     * Draw Point.
     * Draw Point.
     * Draw Line.
    */
}


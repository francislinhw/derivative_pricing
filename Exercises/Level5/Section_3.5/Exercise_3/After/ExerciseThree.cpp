// Exercise 3: Virtual Destructors
// When objects are removed from memory, the destructor is called. When a derived class destructor is called, it will automatically call the base class destructor. But when you have pointers to a base class, deleting objects might not be done correctly.
// If not done already, print some text in the destructors of the Shape, Point and Line classes. Then test the following code:
// Shape* shapes[3];
// shapes[0]=new Shape;
// shapes[1]=new Point;
// shapes[2]=new Line;
// for (int i=0; i!=3; i++) delete shapes[i];
// Will the proper destructors (including the destructor of the Shape base class) be called?
// In this case, the derived class destructor will only be called when the destructor is
// declared virtual in the base class. Do this in the Shape class and run the code again. Are the proper destructors called now?

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
    Shape* shapes[3];
    shapes[0] = new Shape;
    shapes[1] = new Point;
    shapes[2] = new Line;

    for (int i = 0; i != 3; i++) delete shapes[i];

    return 0;    
    /*
     * Answer: The derived objects are now deleted correctly.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * bye my shape.. (Destructor called). // Correctly delete Shape
     * bye my point.. (Destructor called). // Correctly delete Point
     * bye my shape.. (Destructor called). // Correctly delete Base from Point
     * bye my line.. (Destructor called).  // Correctly delete Line
     * bye my point.. (Destructor called). // Correctly delete start Point in Line
     * bye my shape.. (Destructor called). // Correctly delete Base from Point
     * bye my point.. (Destructor called). // Correctly delete end Point in Line
     * bye my shape.. (Destructor called). // Correctly delete Base from Point
     * bye my shape.. (Destructor called). // Correctly delete Base from Line
    */
}


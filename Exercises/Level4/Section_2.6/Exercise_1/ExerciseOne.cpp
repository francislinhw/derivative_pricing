// To avoid name conflicts, programmers can place their classes in a namespace.
// For example the standard library is placed in a namespace called std.
// You should put your classes in your own namespace.
// Thus place the CAD classes (Shape,Point, Line, etc) in the namespace: YourName::CAD
// Place the container classes (Array) in the namespace: YourName::Containers Now access the classes in your own namespace using:
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"

using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // • In the main program, using declaration for a complete namespace (Containers).
using francis::CAD::Line; // • In the main program, using declaration for using a single class (Line).
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    // Using Point with full namespace
    francis::CAD::Point p(1, 2);
    std::cout << p << std::endl;

    // Using Line with using declaration
    Line l(p, Point(3, 4));
    std::cout << l << std::endl;

    // Using Array from Containers namespace
    Array myArray(1);
    myArray[0] = p;
    std::cout << "Print from Array: " << myArray[0] << std::endl;

    // Using Circle with alias
    FCAD::Circle c(p, 5);
    std::cout << c << std::endl;

    return 0;
    /*
     * Answer: Correctly access my classes by different ways to specified namespace.
     *
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Point(1, 2)
     * Line from Point(1, 2) to Point(3, 4)
     * Print from Array: Point(1, 2)
     * Circle: Centre at Point(1, 2), Radius 5
    */
}

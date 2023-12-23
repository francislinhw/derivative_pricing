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
    Line l(Point(1,2), Point(3, 4));
    
    // Print using the base class Print function
    p.Print(); // Should print point information
    l.Print(); // Should print line information
    
    // Even if the derived classes don't have Print(), the base class version will be called.

    return 0;
}


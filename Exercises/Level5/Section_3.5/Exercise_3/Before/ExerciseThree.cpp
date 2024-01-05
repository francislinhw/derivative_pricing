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

    for (int i = 0; i != 3; i++) delete shapes[i]; // It is not done correctly!

    return 0;
    /*
     * Answer: The derived objects are not deleted correctly.
     * Only the base destructor is called.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * bye my shape.. (Destructor called).
     * bye my shape.. (Destructor called).
     * bye my shape.. (Destructor called).
    */
}


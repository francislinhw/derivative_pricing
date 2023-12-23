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
    Shape* shapes[3];
    shapes[0] = new Line;   // Assuming Line has a default constructor
    shapes[1] = new Point;  // Assuming Point has a default constructor
    // ... initialize other shapes ...
    shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));

    for (int i = 0; i != 3; i++) {
        shapes[i]->Draw();
    }

    for (int i = 0; i != 3; i++) {
        delete shapes[i];
    }

    return 0;
}


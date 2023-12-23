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
    francis::CAD::Shape* shapes[3];
    shapes[0] = new francis::CAD::Shape();
    shapes[1] = new francis::CAD::Point(10, 20);
    // Assume Line is another derived class of Shape
    shapes[2] = new francis::CAD::Line(Point(1,2), Point(3, 4));

    for (int i = 0; i < 3; ++i) {
        std::cout << shapes[i]->ToString() << std::endl;  // Will call the appropriate ToString
    }

    // Clean up
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}


#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"

using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    // Using Point with full namespace
    francis::CAD::Point p1(1, 2);
    std::cout << p1 << std::endl;

    // Using Line with using declaration
    Line l1(p1, Point(3, 4));
    Point p2(3, 4);
    std::cout << l1 << std::endl;
    std::cout << p2 << std::endl;

    // Using Array from Containers namespace
    Array myArray;

    // Using Circle with alias
    FCAD::Circle c1(p1, 5);
    std::cout << c1 << std::endl;

    return 0;
}

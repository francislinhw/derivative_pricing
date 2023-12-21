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
}

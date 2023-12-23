#include "Array.hpp"
#include "NumericArray.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"
#include "PointArray.hpp"

using namespace std;
using francis::CAD::Shape;
using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    PointArray pa(3);
    pa.SetElement(0, Point(1, 2));
    pa.SetElement(1, Point(3, 4));
    pa.SetElement(2, Point(5, 6));

    std::cout << "Total length: " << pa.Length() << std::endl;

    return 0;
}
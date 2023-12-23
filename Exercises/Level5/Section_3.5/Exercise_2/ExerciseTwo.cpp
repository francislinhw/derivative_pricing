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
    Circle c(Point(1, 2), 5);
    Line l(p, p);

    cout << p.ToString() << endl; // Should include the ID from Shape
    cout << c.ToString() << endl; // Should include the ID from Shape
    cout << l.ToString() << endl; // Should include the ID from Shape

    return 0;
}


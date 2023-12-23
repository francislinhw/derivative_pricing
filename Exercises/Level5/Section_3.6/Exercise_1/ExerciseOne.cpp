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
    Array myArray;

    try {
        // Attempt to access an out-of-bounds element
        myArray.SetElement(11, Point(1, 1));  // This should throw an exception because the default constructor preserve only 10.
    } catch (int e) {
        if (e == -1) {
            std::cerr << "Error: Index out of bounds." << std::endl;
            return 0;
        }
    }

    // ... rest of the main function

    return 0;
}


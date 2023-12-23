#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"

using namespace std;
using francis::CAD::Shape;
using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    // Use fully qualified class name with template parameter
    Array<Shape*> arr(3);  // Assume Array has size 3

    try {
        arr[0] = new Point(1, 3); // Dynamically allocate a new Point
        arr[1] = new Line(*dynamic_cast<Point*>(arr[0]), Point(3, 4)); // Dynamically allocate a new Line
        arr[2] = new Circle(*dynamic_cast<Point*>(arr[0]), 5); // Dynamically allocate a new Circle

        for (int i = 0; i != 3; i++) {
            arr[i]->Print(); // Assuming Print() is a virtual function in Shape
        }

        // Cleanup dynamic memory
        for (int i = 0; i != 3; i++) {
            delete arr[i];
        }
    } catch (const ArrayException& e) {
        std::cerr << e.GetMessage() << std::endl;
    } catch (...) {
        std::cerr << "An unknown error has occurred." << std::endl;
    }

    return 0;
}
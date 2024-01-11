// Exercise 1: Templated Array Class
// In a previous exercise we created an Array class that stores Point objects.
// The disadvantage of this class was that it only stores Point objects.
// If we want to have an array class for Lines, we need to copy the code and replace references to Pointto Line.
// This is a lot of work and makes maintenance more difficult.
// A bug in one version has to be fixed in the other versions as well.
// Better is to use the same code for different data types.
// This is possible using templates as shown in Figure 1.

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
    Array<Point> points(3);

    try {
        arr[0] = new Point(1, 3); // Dynamically allocate a new Point
        arr[1] = new Line(*dynamic_cast<Point*>(arr[0]), Point(3, 4)); // Dynamically allocate a new Line
        arr[2] = new Circle(*dynamic_cast<Point*>(arr[0]), 5); // Dynamically allocate a new Circle

        for (int i = 0; i != 3; i++) {
            arr[i]->Print(); // Assuming Print() is a virtual function in Shape
            points[i].Print(); 
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
    /* 
     * Tip: by placing the following code at the end of the array header file, but before the header file’s #endif,
     * the client can keep including the header file for template classes instead of the source file.
     * Can you explain how this works?:
     * 
     * Answer: 
     * It's used to include the implementation of a template class directly within its header file.
     * That approach is necessary because C++ templates are not like regular functions or classes.
     * The templates are more like blueprints that the compiler uses to generate the actual code when a template is instantiated with specific types.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Point(1, 3)
     * Point ID: 984943658
     * Point(0, 0)
     * Point ID: 16807
     * Line from Point(1, 3) to Point(3, 4)
     * Line ID: 470211272
     * Point(0, 0)
     * Point ID: 282475249
     * Circle: Centre at Point(1, 3), Radius 5
     * Circle ID: 1458777923
     * Point(0, 0)
     * Point ID: 1622650073
    */
}
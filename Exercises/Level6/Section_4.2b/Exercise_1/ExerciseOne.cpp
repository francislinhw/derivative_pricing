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
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;

    std::cout << intArray1.DefaultSize() << std::endl;
    std::cout << intArray2.DefaultSize() << std::endl;
    std::cout << doubleArray.DefaultSize() << std::endl;

    Array<int>::DefaultSize(15);  // Change the default size for Array<int>

    std::cout << intArray1.DefaultSize() << std::endl;
    std::cout << intArray2.DefaultSize() << std::endl;
    std::cout << doubleArray.DefaultSize() << std::endl;
/*
 * 
 * My Explain for the result: 10, 10, 10, 15, 15, 10
 * 
 * This shows that changing the default size for Array<int> doesn't affect Array<double>, 
 * because each instantiation has its own separate copy of the static variable defaultSize. 
 * This is why templates can be used to create type-safe and efficient container classes, 
 * but it's important to remember that their static variables are not shared across different instantiated types.
 * 
*/
    return 0;
}
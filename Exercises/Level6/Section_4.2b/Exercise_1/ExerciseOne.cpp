// Exercise 1: Static Variable for Array Default Size
// Static variables, which are shared between all instances of a class, behave slightly different with templates.
// We are going to test this with a static variable in the Array class that indicates the default array size when using the default constructor.
// • Add a static data member to the Array class indicating the default size.
// • Initialise this static in the source file to a value.
// • Also add static functions to set and get the default size.
// • In the default constructor, use the static default size variable instead of a literal value
// to set the array size.
// Test the following code in the main program:
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

    return 0;
    /*
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 10
     * 10
     * 10
     * 15
     * 15
     * 10
     * 
     * My Explain for the result: 10, 10, 10, 15, 15, 10: 
     * 
     * This shows that changing the default size for Array<int> doesn't affect Array<double>, 
     * because each instantiation has its own separate copy of the static variable defaultSize. 
     * This is why templates can be used to create type-safe and efficient container classes, 
     * but it's important to remember that their static variables are not shared across different instantiated types.
     * 
     */
}
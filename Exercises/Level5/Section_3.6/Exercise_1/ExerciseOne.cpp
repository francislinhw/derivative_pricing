// Exercise 1: Bounds Checking Array
// In the array class we created previously, the bounds checking was very basic.
// There was no error generated,
// but setting an element was ignored or the first element was returned.
// Obviously you want to know if there was an out of bounds error. This is possible by exception handling.
// Change the Array class to throw exceptions:
// • In the GetElement(), SetElement() and index operator throw -1 if the index was too small or too big.
// • In the main program, create an Array object and access an element that does not exist. Run the program. What happens?
// • The exception must be caught, so place the code inside a try ... catch block that catches an int.
// • In the catch handler, print an error message.
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

    return 0;
    /*
     * Answer: 
     * The program caught a error == -1 (as we expected).
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Index out of bounds, returning first element.
     * Error: Index out of bounds.
     * bye my Array.. (Destructor called).
    */
}


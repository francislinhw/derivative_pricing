// Throwing an int is an easy solution. But exception handling is also object oriented and allows us to throw an object.
// In this exercise we will create an exception hierarchy with an ArrayException base class and an OutOfBoundsExceptionderived class as shown in Figure 3:
// • You can implement both exception classes in the header file for simplicity.
// • Give the ArrayException an abstract GetMessage() function that returns a std::string.
// • Give the OutOfBoundsException class a constructor with an int as argument that
// indicates the erroneous array index and store it in a data member.
// • Override the GetMessage() function and let the implementation return a message
// string saying the given index is out of bounds.
// • In the Array class, throw now a OutOfBoundsException object instead of an integer.
// • Change the main program so that it catches the ArrayException base class and uses
// the GetMessage() function to display an error message.
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
    
    Array<int> arr;  // Assume Array has size 10

    try {
        std::cout << arr[10] << std::endl;  // This will cause an exception
    } catch (const ArrayException& e) {
        std::cerr << e.GetMessage() << std::endl;
    }

    return 0;
    /*
     * Answer: 
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Error: Index 10 is out of bounds.
    */
}


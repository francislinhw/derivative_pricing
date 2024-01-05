// Exercise 1: Colon Syntax
// The colon syntax can improve the performance of constructors.
// To test this, make sure that you print some text in the point’s constructors, destructor and also the assignment operator.
// Now, execute the following code in the test program and count the number of point constructor, destructor and assignment calls:
// Line l;
// Now, change the constructors in the Line class to use the colon syntax to set the start- and end-point data members and run the test program again.
// Is the number of point constructor, destructor and assignment calls less than before?
// Apply the colon syntax also for the Point class constructors and if applicable also for the Circle class.

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
    
    Line l;
    std::cout << l << std::endl;

    return 0;
    /*
     * Answer: 
     * Yes, the number of point constructor, destructor and assignment calls less than before.
     * It was 4 times and now it is 2.
     * Without colon syntax, the default constructor of Point is called twice for the Line object (once for each Point member),
     * followed by the assignment operator = (for each Point member in the Line constructor).
     * 
     * With colon syntax, the default constructor of Point is still called twice for the Line object,
     * but there are no assignment operator calls.
     * This is because the members are directly initialized.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Point Custom constructor called.     \\ -> 1
     * Point Custom constructor called.     \\ -> 2
     * Line from Point(0, 0) to Point(0, 0) \\
     * bye my point.. (Destructor called).  \\      -> 1
     * bye my point.. (Destructor called).  \\      -> 2
    */
}

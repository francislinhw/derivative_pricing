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
     * Notes: 
     *
     * Without colon syntax, the default constructor of Point is called twice for the Line object (once for each Point member),
     * followed by the assignment operator = (for each Point member in the Line constructor), so the total is four times.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Point Default constructor called.     \\ -> 1
     * Point Default constructor called.     \\ -> 2
     * Point Custom constructor called.      \\ -> 3
     * bye my point.. (Destructor called).   \\      -> 1
     * Point Custom constructor called.      \\ -> 4
     * bye my point.. (Destructor called).   \\      -> 2
     * Line Default Constructor Called       \\
     * Line from Point(0, 0) to Point(0, 0)  \\
     * bye my point.. (Destructor called).   \\      -> 3
     * bye my point.. (Destructor called).   \\      -> 4
    */
}

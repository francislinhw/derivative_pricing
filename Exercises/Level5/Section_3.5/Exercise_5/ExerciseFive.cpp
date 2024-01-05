// Exercise 5: Template Method Pattern
// In this exercise we are going to create a Print() function that is printing the shape information to the cout object.
// The Print() function can use the ToString() to obtain the string to print.
// You see that the implementation of Print() is in each derived class largely the same;
// calling ToString() and sending the result to cout. Since the ToString() function is polymorphic, 
// we can use the polymorphic behavior in the Print() function of Shape.
// Thus:
// • Add a Print() function to the Shape class.
// • In this function, call the ToString() function and send the result to the cout object.
// • In the test program, create a point and line object and call the Print() function.
// Does it print the right information even when point and line do not have the Print() function?
// You have now created a function for the base class (Print()) that does all the functionality common to all derived classes.
// Only the part of that function that is different for each derived class is delegated to a polymorphic function (ToString()).
// This mechanism is an often used design pattern called the “Template Method Pattern”.
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
    Line l(Point(1,2), Point(3, 4));
    
    // Print using the base class Print function
    p.Print(); // Should print point information
    l.Print(); // Should print line information
    
    // Even if the derived classes don't have Print(), the base class version will be called.

    return 0;
    /*
     * Answer: Yes, the program prints the right information even when point and line do not have the Print() function.
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * bye my point.. (Destructor called).
     * bye my shape.. (Destructor called).
     * bye my point.. (Destructor called).
     * bye my shape.. (Destructor called).
     * Point(10, 20)
     * Point ID: 16807
     * Line from Point(1, 2) to Point(3, 4)
     * Line ID: 984943658
     * bye my line.. (Destructor called).
     * bye my point.. (Destructor called).
     * bye my shape.. (Destructor called).
     * bye my point.. (Destructor called).
     * bye my shape.. (Destructor called).
     * bye my shape.. (Destructor called).
     * bye my point.. (Destructor called).
     * bye my shape.. (Destructor called).
    */
}


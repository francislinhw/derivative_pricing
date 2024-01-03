// In the final exercise for this chapter we are going to create a Line class. The Line class has a start- and an end-point.
// So the Line class should have two Point objects as data members. This mechanism is called “composition”.
// See also Figure 3.
// Give the Line class the following functionality:
// • Default constructor (set the points to 0, 0).
// • Constructor with a start- and end-point.
// • Copy constructor.
// • Destructor.
// • Overloaded getters for the start- and end-point.
// • Overloaded setters for the start- and end-point.
// • A ToString() function that returns a description of the line.
// • A Length() function that returns the length of the line. Note that you can use the
// distance function on the embeddedPoint objects to calculate the length. This
// mechanism is called “delegation”.
// Use const arguments, const functions and pass objects by reference where applicable.
#include "Line.hpp"
#include "Point.hpp"
#include <iostream>

int main() {
    Point start(3.0, 3.0);
    Point end(6.0, 7.0);
    Line defaultLine; // Default constructor (set the points to 0, 0).
    Line line(start, end); // Constructor with a start- and end-point.
    Line copyLine(defaultLine); // Copy Constructor.

    // Overloaded getters for the start- and end-point.
    std::cout << defaultLine.P1().ToString() << defaultLine.P2().ToString() << std::endl;

    // Overloaded setters for the start- and end-point.
    defaultLine.P1(start);
    defaultLine.P1(end);

    std::cout << line.ToString() << std::endl;
    std::cout << copyLine.ToString() << std::endl;
    std::cout << "Line length: " << line.Length() << std::endl;

    return 0;// Line Destructor.
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Point Custom constructor called. // For start point             -> 1
     * Point Custom constructor called. // For end point               -> 2
     * Point Custom constructor called. // For defaultLine start point -> 3
     * Point Custom constructor called. // For defaultLine end point   -> 4
     * Line Default constructor called. // For defaultLine line        -> 5
     * Point Copy constructor called.   // For line start point        -> 6
     * Point Copy constructor called.   // For line end point          -> 7
     * Line Custom constructor called.  // For line line               -> 8
     * Point Copy constructor called.   // For copyLine start point    -> 9
     * Point Copy constructor called.   // For copyLine end point      -> 10
     * Line Copy constructor called.    // For copyLine line           -> 11
     * Point(0, 0)Point(0, 0)
     * Line from Point(3, 3) to Point(6, 7)
     * Line from Point(0, 0) to Point(0, 0)
     * Line length: 5
     * bye my line... (destructor called).  // -> 1
     * bye my point.. (Destructor called).  // -> 2
     * bye my point.. (Destructor called).  // -> 3
     * bye my line... (destructor called).  // -> 4
     * bye my point.. (Destructor called).  // -> 5
     * bye my point.. (Destructor called).  // -> 6
     * bye my line... (destructor called).  // -> 7
     * bye my point.. (Destructor called).  // -> 8
     * bye my point.. (Destructor called).  // -> 9
     * bye my point.. (Destructor called).  // -> 10
     * bye my point.. (Destructor called).  // -> 11
     * 
    */
}

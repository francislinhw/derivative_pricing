// Inline functions can speed up the execution of short functions because the code of such function will be copied in place instead of calling that function.
// Make the setters and getters of the Point class inline functions. Use normal inline (outside the class declaration) for the getters and default inline (inside the class declaration) for the setters. Note that the implementation of the normal inline functions must be in the header file; else they will not be inlined.
#include <iostream>
#include <cmath>
#include "Point.hpp"

int main() {
    Point p1;
    Point p2(3.0, 4.0);
    p1.X(3.0); // Set X by default inline function.
    p1.Y(4.0); // Set Y by default inline function.

    std::cout << "Point 1 X:" << p1.X() << ", Y: " << p1.Y() << std::endl; // Get X and Y by Normal inline function.
    std::cout << "Distance between Points: " << p1.Distance(p2) << std::endl;

    return 0;
    /*
     * The inline functions are working correctly as expected.
     *
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Default constructor called.
     * Custom constructor called.
     * Set X by default inline function.
     * Set Y by default inline function.
     * Point 1 X:Get X by Normal inline function.
     * 3, Y: Get X by Normal inline function.
     * 4
     * Distance between Points: 0
     * bye my point.. (Destructor called).
     * bye my point.. (Destructor called).
    */
}
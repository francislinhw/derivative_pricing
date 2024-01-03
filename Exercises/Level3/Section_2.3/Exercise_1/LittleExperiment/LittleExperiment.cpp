// First we do a little experiment. 
// In the Point class constructor and destructor, add some code that displays some text.
// In the main program, make sure you use the Distance() function to calculate the distance between two points. 
// Run the program and count how many times the constructor and destructor are called. Are they the same?
#include "Point.hpp"
#include <iostream>
#include <cmath>

int main() {
    Point p1; // Default constructor 1
    Point p2; // Default constructor 2

    p2.SetX(3);
    p2.SetY(4);

    std::cout << "Distance: " << p1.Distance(p2) << std::endl; // Copy constructor is called for p2 to Distance()

    return 0; // Destructor called for p1 and p2 and copy of p2 (3)
    /*
     * Answer: 
     * No, in this program example, the numbers of times calling the constructor and destructor are not the same.
     * Because the Distance is not called by reference, the copy constructor is automatically bulit 'for free', 
     * so the Destructor is called one more than the constructor. 
     * However, if the Distance is called by reference, the number of calls for constructor and destructor will be the same.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Default constructor called. // -> 1
     * Default constructor called. // -> 2
     * Distance: 5
     * bye my point.. (Destructor called). // -> 1
     * bye my point.. (Destructor called). // -> 2
     * bye my point.. (Destructor called). // -> 3
    */

}

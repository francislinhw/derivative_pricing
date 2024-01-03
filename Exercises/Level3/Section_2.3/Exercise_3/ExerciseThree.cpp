// Previously you saw that there could be more than one constructor as long as the input arguments are different.
// You can do the same for normal member functions. Thus you can rename the DistanceOrigin() function to Distance(). Also you can rename
// the SetX() andGetX() functions to just X(). 
// The same is true for the setter and getter of the y- coordinate.
#include "Point.hpp"
#include <iostream>
#include <cmath>

int main() {
    Point p1;
    Point p2(10.0, 24.0);

    p1.X(5.0); // Set x using overloaded setter
    p1.Y(12.0); // Set y using overloaded setter

    std::cout << "p1: " << p1.X() << ", " << p1.Y() << std::endl; // Use overloaded getters
    std::cout << "Distance from p1 to origin: " << p1.Distance() << std::endl;
    std::cout << "Distance from p1 to p2: " << p1.Distance(p2) << std::endl;

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Default constructor called.
     * Custom constructor called.
     * p1: 5, 12
     * Distance from p1 to origin: 13
     * Distance from p1 to p2: 13
     * bye my point.. (Destructor called).
     * bye my point.. (Destructor called).
     * 
     * 
    */
}

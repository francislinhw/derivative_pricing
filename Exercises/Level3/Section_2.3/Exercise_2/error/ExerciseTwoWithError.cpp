// Also test if you can change the input point in the Distance() function. This should result in a compiler error.
#include <iostream>
#include "Point.hpp"

int main() {
    Point p1; // Default constructor
    Point p2(3.0, 4.0); // Custom constructor

    std::cout << "Distance: " << p1.Distance(p2) << std::endl; // Called by reference without Copy Constructor

    return 0; // Destructor called for p1 and p2
    /**
     * This example will result in a compiler error due to the change in const value.
    */
}

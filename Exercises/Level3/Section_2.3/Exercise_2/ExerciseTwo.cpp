// In the previous exercise, you saw that the point passed to the Distance() method was copied.
// Since creating a copy is unnecessary in this case, change this function so that it passes the input point “by reference”
// so that no copy is made. Pass it as “const reference” to make it impossible to change the input point from within the Distance() function.
// Run the program again. It should call the copy constructor fewer times than before.
// Also test if you can change the input point in the Distance() function. This should result in a compiler error.
#include "Point.hpp"
#include <iostream>
#include <cmath>

int main() {
    Point p1; // Default constructor
    double x, y;

    std::cout << "Enter the x-coordinate: ";
    std::cin >> x;
    std::cout << "Enter the y-coordinate: ";
    std::cin >> y;

    Point p2(x, y); // Custom constructor

    std::cout << "Distance: " << p1.Distance(p2) << std::endl; // Called by reference without Copy Constructor
    std::cout << "Distance with Change: " << p1.DistanceWithChange(p2) << std::endl; // Called by reference without Copy Constructor

    return 0; // Destructor called for p1 and p2
    /*
     * 
     * The numbers of times of constructors and destructors called are less than the previous one.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * // User input x = 3, y = 4
     * 
     * Default constructor called.          // -> 1
     * Enter the x-coordinate: 3         
     * Enter the y-coordinate: 4         
     * Custom constructor called.           // -> 2
     * Distance: 5
     * Distance with Change: 5.65685
     * bye my point.. (Destructor called).  // -> 1
     * bye my point.. (Destructor called).  // -> 2
    */
}

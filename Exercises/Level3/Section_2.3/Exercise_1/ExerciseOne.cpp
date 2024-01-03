// Now add a copy constructor to the Point class that also displays some text.
// Also add a constructor that accepts x- and y-coordinates so you can create a point with the right values without using the set functions. 
// Use this constructor to create the point from the user input.
// Run the program again and count the number of times the constructors and destructor are called.
// Is the copy constructor called and is the number of constructor calls now the same as the number of destructor calls?
// We can derive two things from these results:
// 1. When calling the Distance() function, the input point is copied (call by value).
// 2. You will get the copy constructor 'for free' when you do not create one yourself.
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

    std::cout << "Distance: " << p1.Distance(p2) << std::endl; // Copy constructor is called for p2 to Distance()

    return 0; // Destructor called for p1 and p2
    /*
     * Answer: 
     * Yes, the copy constructor called and is the same as the number of other constructor calls and the total calls matchs the number of destructor calls.
     *      
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * // User input x = 3, y = 4
     * 
     * Default constructor called.         // -> 1 
     * Enter the x-coordinate: 3
     * Enter the y-coordinate: 4 
     * Custom constructor called.          // -> 2 
     * Distance: Copy constructor called.  // -> 3 
     * 5
     * bye my point.. (Destructor called). // -> 1 
     * bye my point.. (Destructor called). // -> 2 
     * bye my point.. (Destructor called). // -> 3 
    */

}

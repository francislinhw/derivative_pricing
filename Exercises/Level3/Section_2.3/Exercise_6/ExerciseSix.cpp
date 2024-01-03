// Create a Circle class. It has a center point and radius. 
// Create the proper constructors, destructor, selector and modifier functions.
// Also add functions for getting the diameter, area and circumference. Don’t forget a ToString() function.
// In further exercises, all optimizations requested for Line should also be implemented for Circle. See also Figure 4.
#include "Circle.hpp"
#include "Point.hpp"
#include <iostream>

int main() {
    Point center(1.0, 2.0);
    double radius = 5.0;
    
    Circle circle(center, radius);

    // Test circle ToString() function.
    std::cout << circle.ToString() << std::endl;

    // Test functions for getting the diameter, area and circumference.
    std::cout << "Diameter: " << circle.Diameter() << std::endl;
    std::cout << "Area: " << circle.Area() << std::endl;
    std::cout << "Circumference: " << circle.Circumference() << std::endl;

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Custom constructor called.
     * Copy constructor called.
     * Circle: Centre at Point(1, 2), Radius 5
     * Diameter: 10
     * Area: 78.5398
     * Circumference: 31.4159
     * bye my point.. (Destructor called).
     * bye my point.. (Destructor called).
    */
}

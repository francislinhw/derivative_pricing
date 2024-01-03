// Extend the main program to print the distance between the origin and another point and test it.
#include "Point.hpp"
#include <iostream>

int main() {
    Point p;
    double x, y;

    std::cout << "Enter the x-coordinate: ";
    std::cin >> x;
    std::cout << "Enter the y-coordinate: ";
    std::cin >> y;

    p.SetX(x);
    p.SetY(y);

    // Print the description of the point returned by the ToString() function.
    std::cout << p.ToString() << std::endl;
    // Calculate the distance to the origin (0, 0).
    std::cout << "Distance to origin: " << p.DistanceOrigin() << std::endl;

    // Testing distance between two points
    Point q(1.0, 1.0); // Another point
    std::cout << "Distance to another point (" << q.GetX() << ", " << q.GetY() << "): "
              // Calculate the distance between two points. 
              << p.Distance(q) << std::endl;

    return 0;

    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Enter the x-coordinate: 5
     * Enter the y-coordinate: 12
     * Point(5, 12)
     * Distance to origin: 13
     * Distance to another point (1, 1): 11.7047
     * 
    */
}

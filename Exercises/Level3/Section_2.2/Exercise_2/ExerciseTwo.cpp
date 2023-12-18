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

    std::cout << p.ToString() << std::endl;
    std::cout << "Distance to origin: " << p.DistanceOrigin() << std::endl;

    // Testing distance between two points
    Point q(1.0, 1.0); // Replace with user input or other coordinates if needed
    std::cout << "Distance to point (" << q.GetX() << ", " << q.GetY() << "): " 
              << p.Distance(q) << std::endl;

    return 0;
}

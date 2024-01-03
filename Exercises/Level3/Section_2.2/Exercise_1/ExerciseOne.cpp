// Finally create a test program (separate source file with a main() function) for the Point class. It should do the following things:
// • Include the point header file.
// • Ask the user for the x- and y-coordinates using the std::cin object (needs the “iostream” header file).
// • Then create a Point object using the default constructor.
// • Set the coordinates entered by the user using the setter functions.
// • Print the description of the point returned by the ToString() function.
// • Print the point coordinates using the get functions.
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
    std::cout << "X: " << p.GetX() << ", Y: " << p.GetY() << std::endl;

    return 0;
}

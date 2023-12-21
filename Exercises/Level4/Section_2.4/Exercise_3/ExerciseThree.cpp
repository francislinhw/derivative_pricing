#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    Point p(1.0, 1.0);

    if (p == (Point) 1.0) std::cout<<"Equal!"<<std::endl;
    // Implicitly calls Point(1.0), setting both x and y to 1.0
    else std::cout<<"Not equal"<<std::endl;

    return 0;
}

// Exercise 3: Constructors as conversion operator
// It turns out that the Point constructor with the single double argument is implicitly used to convert the number in the if statement to a Point object.
// Thus constructors are used as implicit conversion operators.
// Now try to compile the program again and you will see that now the if statement gives a compiler error.
// You can still use the constructor as conversion operator but then explicitly:
// if (p==(Point)1.0) cout<<"Equal!"<<endl;

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    Point p(1.0, 1.0); // Point p(1.0, 1.0);

    if (p == (Point) 1.0) std::cout<<"Equal!"<<std::endl;
    // Explicitly calls Point(1.0), setting both x and y to 1.0
    else std::cout<<"Not equal"<<std::endl;

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Equal!
    */
}

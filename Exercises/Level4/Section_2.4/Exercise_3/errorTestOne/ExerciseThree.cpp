// In this exercise we are going to do a little experiment.
// First add to the Point class a constructor that accepts one double as an argument.
// The implementation should set both the x- and y-coordinate to this value.
// Next try the following code in the test program:
// Point p(1.0, 1.0);
// if (p==1.0) cout<<"Equal!"<<endl;
// else cout<<"Not equal"<<endl;
// Will this code compile and can you explain why?
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    Point p(1.0, 1.0);

    if (p == 1.0) std::cout<<"Equal!"<<std::endl;
    else std::cout<<"Not equal"<<std::endl;

    return 0;
    /*
     * No, This code does not compile.
     * Point object is not comparible with double type.
     * error log: invalid operands to binary expression ('Point' and 'double')
     * 
    */
}

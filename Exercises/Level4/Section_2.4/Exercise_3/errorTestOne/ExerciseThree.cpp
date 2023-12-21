#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    Point p(1.0, 1.0);

    if (p == 1.0) std::cout<<"Equal!"<<std::endl;
    else std::cout<<"Not equal"<<std::endl;

    return 0;
}

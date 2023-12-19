#include "Line.hpp"
#include "Point.hpp"
#include <iostream>

int main() {
    Point start(3.0, 3.0);
    Point end(6.0, 7.0);
    Line line(start, end);

    std::cout << line.ToString() << std::endl;
    std::cout << "Line length: " << line.Length() << std::endl;

    return 0;
}

#include "Point.hpp"
#include <iostream>

int main() {
    const Point cp(1.5, 3.9);
    // cp.X(0.3); // This will cause a compiler error because cp is a const object.

    std::cout << cp.X() << std::endl; // This will now compile successfully.

    // Other tests...
    return 0;
}

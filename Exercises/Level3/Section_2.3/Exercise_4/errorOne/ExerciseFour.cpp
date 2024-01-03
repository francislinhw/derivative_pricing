// In the test program create a const point and try to set the x-coordinate:
// const Point cp(1.5, 3.9);
// cp.X(0.3);
// Compile the program. Did you get a compiler error? It should give a compiler error because you try to change a const object.
#include "Point.hpp"
#include <iostream>

int main() {
    const Point cp(1.5, 3.9);
    cp.X(0.3); // This will cause a compiler error because cp is a const object.

    // std::cout << cp.X() << std::endl; // This will fail to compile.
    return 0;
    /*
     * Answer: Yes, I got error.
     * error log: no matching member function for call to 'X'
    */
}

// Now replace the line that changes the x-coordinate to code that reads the x-coordinate:
// cout<<cp.X()<<endl;
// Compile the program again. 
// You will see that is still gives a compiler error even while retrieving the x-coordinate does not change the point object. 
// This is because the compiler does not know that the function does not change anything. 
#include "Point.hpp"
#include <iostream>

int main() {
    const Point cp(1.5, 3.9);
    // cp.X(0.3); // This will cause a compiler error because cp is a const object.
    std::cout << cp.X() << std::endl; // This will fail to compile.
    return 0;
}

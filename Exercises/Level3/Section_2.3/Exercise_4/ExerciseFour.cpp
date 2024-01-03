// So we need to mark the x- coordinate getter as const by making it a const function. 
// Do this also for the y-coordinate getter and the Distance() and ToString() functions because these don’t change the point object as well.
#include "Point.hpp"
#include <iostream>

int main() {
    const Point cp(1.5, 3.9);
    // cp.X(0.3); // This will cause a compiler error because cp is a const object.

    std::cout << cp.X() << std::endl; // This will now compile successfully.
    std::cout << cp.ToString() << std::endl; // This will now compile successfully.
    std::cout << cp.Distance() << std::endl; // This will now compile successfully.
    std::cout << cp.Distance(cp) << std::endl; // This will now compile successfully.

    // Recompile the application. It should now work.
    return 0;
}

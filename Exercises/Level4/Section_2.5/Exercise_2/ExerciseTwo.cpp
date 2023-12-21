#include <iostream>
#include "Point.hpp"

int main() {
    // Allocate memory for an array of Point pointers:
    Point** pointArray = new Point*[3];

    // Allocate a new Point for each element in the array using different constructors:
    pointArray[0] = new Point();
    pointArray[1] = new Point(1.0, 2.0);
    pointArray[2] = new Point(*pointArray[1]);

    // Iterate over the array to print each Point:
    for (int i = 0; i < 3; ++i) {
        std::cout << pointArray[i]->ToString() << std::endl;
    }

    // Iterate over the array again to delete each Point:
    for (int i = 0; i < 3; ++i) {
        delete pointArray[i];
    }

    // Delete the array of pointers itself:
    delete[] pointArray;

    return 0;

/** My Drawing Answer:

     Stack:            Heap:
.--------------.   .--------------.
| pointArray   |-->| [0]          |
| (Pointer)    |   | [1]          |
.--------------.   | [2]          |
                   .--------------.
                    | Point( )   | <-- pointArray[0]
                    .------------.
                    | Point(1,2) | <-- pointArray[1]
                    .------------.
                    | Point(1,2) | <-- pointArray[2] (Copy of pointArray[1])
                    .------------.
**/

}

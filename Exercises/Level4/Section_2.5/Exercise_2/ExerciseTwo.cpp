// In this exercise we make it a little more complex.
// With an array of Points, all points are created with the default constructor.
// When creating an array of pointers, each element in the array must be created separately but can be created with other constructors than the default constructor.
// Thus creating an array of pointers is a two step process:
// • Create an array of Point pointers with 3 elements on the heap.
// • Create for each element in the array a point on the heap.
// • Iterate the array and print each point in the array.
// • Iterate the array again and delete each point in the array.
// • Delete the array itself.
// Also make a drawing of the memory layout.
#include <iostream>
#include "Point.hpp"

int main() {
    // Allocate memory for an array of Point pointers:
    Point** pointArray = new Point*[3]; // Create an array of Point pointers with 3 elements on the heap.

    // Allocate a new Point for each element in the array using different constructors:
    pointArray[0] = new Point();                // Default constructor
    pointArray[1] = new Point(1.0, 2.0);        // Custom constructor
    pointArray[2] = new Point(*pointArray[1]);  // Copy constructor

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

    /* Answer: My drawing of the memory layout:
     *
     *      Stack:            Heap:
     * .--------------.   .--------------.
     * | pointArray   |-->| [0]          |
     * | (Pointer)    |   | [1]          |
     * .--------------.   | [2]          |
     *                    .--------------.
     *                     | Point( )   | <-- pointArray[0]
     *                     .------------.
     *                     | Point(1,2) | <-- pointArray[1]
     *                     .------------.
     *                     | Point(1,2) | <-- pointArray[2] (Copy of pointArray[1])
     *                     .------------.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Point(0, 0)
     * Point(1, 2)
     * Point(1, 2)
     */

}

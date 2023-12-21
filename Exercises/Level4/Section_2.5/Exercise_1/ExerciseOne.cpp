#include <iostream>
#include <new> // Required for placement new
#include "Point.hpp"

int main() {
    // Creating a single Point object on the heap
    Point* p1 = new Point(); // Default constructor
    Point* p2 = new Point(5.0, 7.0); // Constructor with coordinates
    Point* p3 = new Point(*p2); // Copy constructor

    // Using the Point objects
    std::cout << "Distance from p1 to origin: " << p1->Distance() << std::endl;
    std::cout << "Distance from p2 to origin: " << p2->Distance() << std::endl;
    std::cout << "Distance from p3 to origin: " << p3->Distance() << std::endl;

    // Deallocate memory
    delete p1;
    delete p2;
    delete p3;

    // Creating an array of Point objects on the heap
    int size;
    std::cout << "Enter the size of the points array: ";
    std::cin >> size;

    Point* pointsArray = new Point[size]; // Array of Points, default constructed

    // Use the array...
    // ...

    // Deallocate the array
    delete[] pointsArray;

// Allocate raw memory
char* buffer = new char[size * sizeof(Point)];

// Create Point objects in the allocated memory
for (int i = 0; i < size; ++i) {
    new (buffer + i * sizeof(Point)) Point(1.0, 2.0); // Call non-default constructor
}

// Cast buffer to Point pointer
Point* myPoints = reinterpret_cast<Point*>(buffer);

// Use myPoints as an array...

// Manually call destructor for each object
for (int i = 0; i < size; ++i) {
    myPoints[i].~Point();
}

// Delete buffer
delete[] buffer;

    return 0;
}

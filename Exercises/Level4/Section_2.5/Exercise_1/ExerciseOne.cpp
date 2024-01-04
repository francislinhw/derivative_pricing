// Until now, we created objects on the stack. The stack is limited in size thus when creating many objects, 
// the stack will overflow. Also arrays created on the stack can only have a fixed size determined at compile time.
// To overcome these problems we have to create objects on the heap using new.
// In the main program, create Point objects on the heap with new using the default constructor,
// constructor with coordinates and the copy constructor and assign it to pointer (Point*) variables.
// Note that you can’t directly pass a pointer variable as argument to the copy constructor.
// The pointer must first be dereferenced when passing it to the copy constructor. (Point* p2=new Point(*p1)).
// Next call the Distance() function on the pointers and try to send the Point pointers to cout.
// You need to dereference the pointer when passing it as argument.
// Don’t forget to delete the object created with new. Test the main program.
// Next, we will create an array of points.
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

    // Now create the array on the heap using new.
    Point* pointsArray = new Point[size]; // Array of Points, default constructed
    // Use the array...

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
    /*
     * 
     * Can you use other constructors than the default constructor for the objects created in the array?
     * Answer: No, The syntax using to create an array with new and initialize all its elements with non-default constructors is incorrect.
     * In C++, when you use new to create an array, only the default constructor is called for each element.
     * If necessary, we can use <vector> to achieve this:
     *  
     *      std::vector<Point> pointsVector(size, Point(1, 1));
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Distance from p1 to origin: 0
     * Distance from p2 to origin: 8.60233
     * Distance from p3 to origin: 8.60233
     * Enter the size of the points array: 5
    */
}

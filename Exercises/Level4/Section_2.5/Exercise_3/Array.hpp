// In this exercise we are going to create an array class for Point objects (see Figure 5):
// • Add a source- and header file for the Array class to your current project.
// • Add a data member for a dynamic C array of Point objects (Point* m_data).
// • Add a data member for the size of the array.
// • Add a default constructor that allocates for example 10 elements.
// • Add a constructor with a size argument. The implementation should allocate the
// number of elements specified by thesize input argument.

#ifndef ARRAY_H
#define ARRAY_H

#include "Point.hpp"

class Array {
private:
    Point* m_data;
    int m_size;

public:
    Array();  // Default Constructor
    Array(int size);  // Constructor with size
    Array(const Array& arr);  // Copy constructor
    ~Array();  // Destructor

    int Size() const;  // Size of the array
    void SetElement(int index, const Point& p);  // Set element at index
    Point& GetElement(int index) const;  // Get element at index
    Point& operator[](int index);  // Overloaded [] operator
    const Point& operator[](int index) const;  // Overloaded [] operator for const objects
    Array& operator=(const Array& source);  // Overloaded = operator for const objects
};

#endif

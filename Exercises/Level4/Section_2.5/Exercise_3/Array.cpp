// It is easy to forget to delete memory created with new.
// A good practice is to let a class manage memory.
// Then the client of that class does not have to manage memory and can’t forget to delete memory.
// So instead of creating a C array with new, you can use an array class that handle memory for you.
#include "Array.hpp"
#include <cassert>   // For assert in GetElement and operator[], but later I used a traditional if statement.
#include <algorithm> // For std::copy

// Default constructor with fixed allocation of 10 elements
Array::Array() : m_size(10), m_data(new Point[10]) {
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = Point(); // Initialize with default Point objects
    }
}

Array::Array(int size) : m_size(size), m_data(new Point[size]) {
    // Initialize each point to default
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = Point(); // Using default constructor of Point
    }
}

// • Add a copy constructor. 
// Keep in mind that just copying the C array pointer will create
// an Array object that shares the data with the original Array object.
// Thus you need to allocate a new C array with the same size and copy each element separately.
Array::Array(const Array& arr) : m_size(arr.m_size), m_data(new Point[arr.m_size]) {
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = arr.m_data[i]; // Copy each element
    }
}

// Array::Array(const Array& arr) : m_size(arr.m_size), m_data(new Point[arr.m_size]) {
//     // Copy each element
//     std::copy(arr.m_data, arr.m_data + m_size, m_data);
// }

// • Add a destructor. It should delete the internal C array. Don’t forget the square brackets.
Array::~Array() {
    delete[] m_data;
}

// • Add a Size() function that returns the size of the array.
int Array::Size() const {
    return m_size;
}

// • Add a SetElement() function that sets an element. When the index is out of bounds,
// ignore the “set”. We will add better error handling later.
void Array::SetElement(int index, const Point& p) {
    // Check for index bounds
    assert(index >= 0 && index < m_size);
    m_data[index] = p;
}

// Point& Array::GetElement(int index) const {
//     // Check for index bounds
//     assert(index >= 0 && index < m_size);
//     return m_data[index];
// }

// • Add a GetElement() function. You can return the element by reference since the
// returned element has a longer lifetime than the GetElement() function.
// When the index is out of bounds, return the first element.
// We will add better error handling later.
Point& Array::GetElement(int index) const {
    // If the index is out of bounds, return the first element
    if (index < 0 || index >= m_size) {
        std::cerr << "Index out of bounds, returning first element." << std::endl;
        return m_data[0];
    }
    // Otherwise, return the element at the index
    return m_data[index];
}

// Point& Array::operator[](int index) {
//     // Check for index bounds
//     assert(index >= 0 && index < m_size);
//     return m_data[index];
// }

// • You can also add a square bracket operator. Return a reference so the [] operator can
// be used for both reading and writing elements. When the index is out of bounds,
// return the first element. We will add better error handling later.
//       Point& operator [] (int index);
Point& Array::operator[](int index) {
    // If the index is out of bounds, return the first element
    if (index < 0 || index >= m_size) {
        std::cerr << "Index out of bounds, returning first element." << std::endl;
        return m_data[0];
    }
    // Otherwise, return the element at the index
    return m_data[index];
}

//const Point& Array::operator[](int index) const {
//    // Check for index bounds
//    assert(index >= 0 && index < m_size);
//    return m_data[index];
//}

const Point& Array::operator[](int index) const {
    if (index < 0 || index >= m_size) {
        // Out of bounds - for now, return the first element.
        std::cerr << "Index " << index << " out of bounds. Returning first element." << std::endl;
        return m_data[0];
    }
    return m_data[index];
}

// • Add an assignment operator. Keep in mind you can’t copy only the C array pointers
// just as in the case of the copy constructor.
// • Also don’t forget to delete the old C array and allocate new memory before copying
// the elements. This is because C arrays can’t grow.
// Further check if the source object is not the same as the this object. If you don’t check it, then a statement like arr1=arr1 will go wrong.
// The internal C array will then be deleted before it is copied.
Array& Array::operator=(const Array& source) {
    // Protect against self-assignment
    if (this == &source) {
        return *this;
    }

    // Delete the old array
    delete[] m_data;

    // Allocate new memory for the copy
    m_size = source.m_size;
    m_data = new Point[m_size];

    // Copy each element
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = source.m_data[i];
    }

    // Return a reference to the current object
    return *this;
}

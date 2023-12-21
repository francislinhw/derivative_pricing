#include "Array.hpp"
#include <cassert> // For assert in GetElement and operator[]
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

Array::Array(const Array& arr) : m_size(arr.m_size), m_data(new Point[arr.m_size]) {
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = arr.m_data[i]; // Copy each element
    }
}

// Array::Array(const Array& arr) : m_size(arr.m_size), m_data(new Point[arr.m_size]) {
//     // Copy each element
//     std::copy(arr.m_data, arr.m_data + m_size, m_data);
// }

Array::~Array() {
    delete[] m_data;
}

int Array::Size() const {
    return m_size;
}

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

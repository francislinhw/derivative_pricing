#ifndef NUMERIC_ARRAY_H
#define NUMERIC_ARRAY_H

#include "Array.hpp"

namespace francis{
    namespace Containers {
        template <typename T>
        class NumericArray : public Array<T> {


        public:
            // static int DefaultSize();
            // static void DefaultSize(int size);
            NumericArray();  // Default Constructor
            NumericArray(int size);  // Constructor with size
            NumericArray(const NumericArray& arr);  // Copy constructor
            ~NumericArray();  // Destructor
            // T& operator + (T index);
            // T& operator * (T index);
            NumericArray<T> operator + (const NumericArray<T>& other) const;
            NumericArray<T> operator * (const T& factor) const;
            T DotProduct(const NumericArray& arr) const;  // a.b = a1 * b1 + a2 * b2 + ... an * bn

            // int Size() const;  // Size of the array
            // void SetElement(int index, const T& p);  // Set element at index
            // T& GetElement(int index) const;  // Get element at index
            // T& operator[](int index);  // Overloaded [] operator
            // const T& operator[](int index) const;  // Overloaded [] operator for const objects
            // Array& operator=(const Array& source);  // Overloaded = operator for const objects
        };
    }
}
// Initialize the static member for each template instantiation

#ifndef NUMERICARRAY_CPP
#include "NumericArray.cpp"
#endif
#endif

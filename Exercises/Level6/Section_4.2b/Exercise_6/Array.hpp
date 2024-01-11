#ifndef ARRAY_H
#define ARRAY_H

#include "Point.hpp"

namespace francis{
    namespace Containers {
        template <typename T>
        class Array {
        private:
            T* m_data; // Pointer to the array of type T
            int m_size;
            static int defaultSize; // Static member for default size

        public:
            static int DefaultSize();
            static void DefaultSize(int size);
            Array();  // Default Constructor
            Array(int size);  // Constructor with size
            Array(const Array& arr);  // Copy constructor
            ~Array();  // Destructor

            int Size() const;  // Size of the array
            void SetElement(int index, const T& p);  // Set element at index
            T& GetElement(int index) const;  // Get element at index
            T& operator[](int index);  // Overloaded [] operator
            const T& operator[](int index) const;  // Overloaded [] operator for const objects
            Array& operator=(const Array& source);  // Overloaded = operator for const objects
        };
    }
}
// Initialize the static member for each template instantiation

#ifndef ARRAY_C
#include "Array.cpp"
#endif
#endif

// • Full class name including namespace for the Point used in the Array class.
// Note that you can use only the CAD part of the namespace without the YourName part
// because the Point is also in the YourName namespace.
#ifndef ARRAY_H
#define ARRAY_H

#include "Point.hpp"

namespace francis{
    namespace Containers {
        class Array {
        private:
            francis::CAD::Point* m_data;
            int m_size;

        public:
            Array();  // Default Constructor
            Array(int size);  // Constructor with size
            Array(const Array& arr);  // Copy constructor
            ~Array();  // Destructor

            int Size() const;  // Size of the array
            void SetElement(int index, const francis::CAD::Point& p);  // Set element at index
            CAD::Point& GetElement(int index) const;  // Get element at index
            francis::CAD::Point& operator[](int index);  // Overloaded [] operator
            const francis::CAD::Point& operator[](int index) const;  // Overloaded [] operator for const objects
            Array& operator=(const Array& source);  // Overloaded = operator for const objects
        };
    }
}
#endif

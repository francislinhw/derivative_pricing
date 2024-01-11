// Thus transform the Array class for points created earlier into a template class:
// • In the header file, declare the Array class as a template of type T.
// • Replace all references to Point with T.
// • Where an array is used as input or output, replace Array by Array<T>.
// • In the source file, every function must be declared as a template of type T.
// • The functions are now not a member of Array anymore but a member of Array<T>. 
// • Further replace all references to Point with T.
// • Finally where an array is used as input or output, replace Array by Array<T>.
// • Don’t forget that the test program should now include the source file instead of the
// header file. Therefore, the source file should now also include #ifndef/#define/#endif statements.
// In the test program create an array of points and test it:
// Array<Point> points(size);
// Tip: by placing the following code at the end of the array header file, but before the header file’s #endif, the client can keep including the header file for template classes instead of the source file. Can you explain how this works?:
// #ifndef Array_cpp // Must be the same name as in source file #define #include "Array.cpp"
// #endif
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

        public:
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
#ifndef ARRAY_C
#include "Array.cpp"
#endif
#endif
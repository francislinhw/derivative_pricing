// In this exercise we are going to create a NumericArray derived from Array.
// • Add a new source- and header file for a NumericArray class to your project.
// • Create a template class called NumericArray and derive it from the Array class using generic inheritance.
// • Since they are not inherited, create proper constructors, destructor and assignment
// operator and call the base class where appropriate. • Add the following numeric functionality:
//      o Anoperator*toscaletheelementsofthenumericarraybyafactor.
//      o An operator + to add the elements of two numeric arrays. Throw an
//        exception if the two arrays have not the same size.
//      o A function to calc𝑛ulate the dot product. The dot product is defined as:
//        𝑎.𝑏 = \sum {𝑎𝑖.𝑏𝑖 =𝑎1.𝑏1+𝑎2.𝑏2+...+𝑎𝑛.𝑏𝑛 𝑖=1}
// Change the main program to test the numeric array. What assumptions do you make about the type used as template argument? Can you create a numeric array with Point objects?

#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP 

#include "OutOfBoundsException.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"
#include <cassert>
#include <algorithm>

namespace francis {
    namespace Containers {
        //template <typename T>
        //int Array<T>::defaultSize = 10;
        //
        //template <typename T>
        //int Array<T>::DefaultSize() { return defaultSize; }

        //template <typename T>
        //void Array<T>::DefaultSize(int size) { defaultSize = size; }

        template <typename T>
        NumericArray<T>::NumericArray() : Array<T>(10) {}  // Use base class constructor

        template <typename T>
        NumericArray<T>::NumericArray(int size) : Array<T>(10) {}  // Use base class constructor

        template <typename T>
        NumericArray<T>::NumericArray(const NumericArray& arr) : Array<T>(arr) {} // The base class copy constructor will handle copying the elements

        template <typename T>
        NumericArray<T>::~NumericArray() {
            // The base class destructor will handle the deletion
        }

        // template <typename T>
        // int Array<T>::Size() const {
        //     return m_size;
        // }

        // template <typename T>
        // void Array<T>::SetElement(int index, const T& p) {
        //     if (index < 0 || index >= m_size) {
        //         throw OutOfBoundsException(index);
        //     }
        //     m_data[index] = p;
        // }

        // template <typename T>
        // T& Array<T>::GetElement(int index) const {
        //     if (index < 0 || index >= m_size) {
        //         throw OutOfBoundsException(index);
        //     }
        //     return m_data[index];
        // }

        // template <typename T>
        // T& Array<T>::operator[](int index) {
        //     if (index < 0 || index >= m_size) {
        //         throw OutOfBoundsException(index);
        //     }
        //     return m_data[index];
        // }
// 
        // template <typename T>
        // const T& Array<T>::operator[](int index) const {
        //     if (index < 0 || index >= m_size) {
        //         throw OutOfBoundsException(index);
        //     }
        //     return m_data[index];
        // }

        template <typename T>
        NumericArray<T> NumericArray<T>::operator*(const T& factor) const {
            NumericArray<T> result(this->Size());
            for (int i = 0; i < this->Size(); ++i) {
                result[i] = this->operator[](i) * factor;
            }
            return result;
        }

        template <typename T>
        NumericArray<T> NumericArray<T>::operator+(const NumericArray<T>& other) const {
            if (this->Size() != other.Size()) {
                throw OutOfBoundsException(other.Size()); // Define this exception as needed
            }
            NumericArray<T> result(this->Size());
            for (int i = 0; i < this->Size(); ++i) {
                result[i] = this->operator[](i) + other[i];
            }
            return result;
        }

        template <typename T>
        T NumericArray<T>::DotProduct(const NumericArray<T>& arr) const {
            if (this->Size() != arr.Size()) {
                throw OutOfBoundsException(arr.Size()); // Define this exception as needed
            }
            T dotProd = T(); // Assuming T can be default-constructed
            for (int i = 0; i < this->Size(); ++i) {
                dotProd += this->operator[](i) * arr[i];
            }
            return dotProd;
        }

        // template <typename T>
        // Array<T>& Array<T>::operator=(const Array& source) {
        //     if (this == &source) {
        //         return *this;
        //     }
// 
        //     delete[] m_data;
        //     m_size = source.m_size;
        //     m_data = new T[m_size];
        //     std::copy(source.m_data, source.m_data + m_size, m_data);
// 
        //     return *this;
        // }

        // template <typename T>
        // T NumericArray<T>::DotProduct(const NumericArray<T>& arr) {
        //     T dotProd = T(); // Assuming T can be default-constructed
        //     for (int i = 0; i < this->Size(); i++) {
        //         dotProd += this->operator[](i) * arr[i];
        //     }
        //     return dotProd; // Return by value, not by reference
        // }
    }
}

#endif
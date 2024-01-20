#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP 

#include "OutOfBoundsException.hpp"
#include "SizeMisMatchException.hpp"
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
        NumericArray<T>::NumericArray(int size) : Array<T>(size) {}  // Use base class constructor

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
                throw SizeMisMatchException(other.Size(), this->Size()); 
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
                throw SizeMisMatchException(arr.Size(), this->Size()); 
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
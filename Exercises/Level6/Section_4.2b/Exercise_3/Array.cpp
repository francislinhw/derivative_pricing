#ifndef ARRAY_C
#define ARRAY_C

#include "OutOfBoundsException.hpp"
#include "Array.hpp"
#include <cassert>
#include <algorithm>

namespace francis {
    namespace Containers {
        template <typename T>
        int Array<T>::defaultSize = 10;
        
        template <typename T>
        int Array<T>::DefaultSize() { return defaultSize; }

        template <typename T>
        void Array<T>::DefaultSize(int size) { defaultSize = size; }

        template <typename T>
        Array<T>::Array() : m_size(10), m_data(new T[10]) { // Allocate array for 10 Ts
            for (int i = 0; i < m_size; ++i) {
                // Initialize each element to a default-constructed T
                m_data[i] = T();
            }
        }

        template <typename T>
        Array<T>::Array(int size) : m_size(size), m_data(new T[size]) {}

        template <typename T>
        Array<T>::Array(const Array<T>& arr) : m_size(arr.m_size), m_data(new T[arr.m_size]) {
            std::copy(arr.m_data, arr.m_data + m_size, m_data);
        }

        template <typename T>
        Array<T>::~Array() {
            delete[] m_data;
        }

        template <typename T>
        int Array<T>::Size() const {
            return m_size;
        }

        template <typename T>
        void Array<T>::SetElement(int index, const T& p) {
            if (index < 0 || index >= m_size) {
                throw OutOfBoundsException(index);
            }
            m_data[index] = p;
        }

        template <typename T>
        T& Array<T>::GetElement(int index) const {
            if (index < 0 || index >= m_size) {
                throw OutOfBoundsException(index);
            }
            return m_data[index];
        }

        template <typename T>
        T& Array<T>::operator[](int index) {
            if (index < 0 || index >= m_size) {
                throw OutOfBoundsException(index);
            }
            return m_data[index];
        }

        template <typename T>
        const T& Array<T>::operator[](int index) const {
            if (index < 0 || index >= m_size) {
                throw OutOfBoundsException(index);
            }
            return m_data[index];
        }

        template <typename T>
        Array<T>& Array<T>::operator=(const Array<T>& source) {
            if (this == &source) {
                return *this;
            }

            delete[] m_data;
            m_size = source.m_size;
            m_data = new T[m_size];
            std::copy(source.m_data, source.m_data + m_size, m_data);

            return *this;
        }

    }
}

#endif
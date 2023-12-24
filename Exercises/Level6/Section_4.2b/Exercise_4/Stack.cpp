#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.hpp"

// Assume necessary includes and namespace using directives are here
namespace francis {
    namespace Containers {
        template <typename T>
        Stack<T>::Stack() : m_current(0), m_array(10) { // Default size 10 for simplicity
            // Constructor implementation
        }

        template <typename T>
        Stack<T>::Stack(int size) : m_current(0), m_array(size) {
            // Constructor implementation
        }

        template <typename T>
        Stack<T>::Stack(const Stack<T>& other) : m_current(other.m_current), m_array(other.m_array) {
            // Copy constructor implementation
        }

        template <typename T>
        Stack<T>::~Stack() {
            // Destructor implementation
        }

        template <typename T>
        Stack<T>& Stack<T>::operator=(const Stack<T>& source) {
            // Assignment operator implementation
            if (this != &source) {
                m_current = source.m_current;
                m_array = source.m_array;
            }
            return *this;
        }

        template <typename T>
        void Stack<T>::Push(const T& newElement) {
            // Push implementation
            m_array[m_current++] = newElement;
        }

        template <typename T>
        T Stack<T>::Pop() {
            if (m_current == 0) {
                throw "Stack is empty"; // Or a more appropriate exception
            }
        
            try {
                --m_current; // Decrement the current position
                return m_array[m_current]; // Return the element at the new current position
            } catch (...) {
                ++m_current; // If an exception is thrown, reset the current position
                throw; // Re-throw the exception to be handled by the calling function
            }
        }
    }
}
#endif // SHAPE_CPP
#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.hpp"
#include "StackEmptyException.hpp"
#include "StackFullException.hpp"
#include "StackException.hpp"

// Assume necessary includes and namespace using directives are here
namespace francis {
    namespace Containers {
        template <typename T, int size>
        Stack<T, size>::Stack() : m_current(0), m_array(size) { // No Default size.
            // Constructor implementation
        }

        // template <typename T, int size>
        // Stack<T, size>::Stack(int startSize) : m_current(0), m_array(startSize) {
        //     // Constructor implementation
        // }

        template <typename T, int size>
        Stack<T, size>::Stack(const Stack<T, size>& other) : m_current(other.m_current), m_array(other.m_array) {
            // Copy constructor implementation
        }

        template <typename T, int size>
        Stack<T, size>::~Stack() {
            // Destructor implementation
        }

        template <typename T, int size>
        Stack<T, size>& Stack<T, size>::operator=(const Stack<T, size>& source) {
            // Assignment operator implementation
            if (this != &source) {
                m_current = source.m_current;
                m_array = source.m_array;
            }
            return *this;
        }

        template <typename T, int size>
        void Stack<T, size>::Push(const T& newElement) {
            if (m_array.Size() < (1 + m_current)) {
                throw StackFullException(m_current);
            }
            try {
                m_array[m_current] = newElement;
                m_current++;
            } catch (...) {
                --m_current; // If an exception is thrown, reset the current position
                throw; // Re-throw the exception to be handled by the calling function
            }
        }

        template <typename T, int size>
        T Stack<T, size>::Pop() {
            if (m_current == 0) {
                throw StackEmptyException();                
            }
            try {
                --m_current; // Decrement the current position
                return m_array[m_current]; // Return the element at the new current position
            } catch (const OutOfBoundsException& e) {
                m_current = 0; // Reset the current index if an exception occurs
                throw OutOfBoundsException(m_current);
            } catch (...) {
                ++m_current; // If an exception is thrown, reset the current position
                throw; // Re-throw the exception to be handled by the calling function
            }
        }

        template <typename T, int size>
        int Stack<T, size>::GetCurrentIndex() {
            return m_current;
        }

    }
}
#endif // SHAPE_CPP
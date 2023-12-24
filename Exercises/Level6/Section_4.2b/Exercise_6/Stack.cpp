#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.hpp"
#include "StackEmptyException.hpp"
#include "StackFullException.hpp"
#include "StackException.hpp"

// Assume necessary includes and namespace using directives are here
namespace francis {
    namespace Containers {
        template <typename T, int N>
        Stack<T, N>::Stack() : m_current(0), m_array(N) { // No Default size.
            // Constructor implementation
        }

        template <typename T, int N>
        Stack<T, N>::Stack(int size) : m_current(0), m_array(size) {
            // Constructor implementation
        }

        template <typename T, int N>
        Stack<T, N>::Stack(const Stack<T, N>& other) : m_current(other.m_current), m_array(other.m_array) {
            // Copy constructor implementation
        }

        template <typename T, int N>
        Stack<T, N>::~Stack() {
            // Destructor implementation
        }

        template <typename T, int N>
        Stack<T, N>& Stack<T, N>::operator=(const Stack<T, N>& source) {
            // Assignment operator implementation
            if (this != &source) {
                m_current = source.m_current;
                m_array = source.m_array;
            }
            return *this;
        }

        template <typename T, int N>
        void Stack<T, N>::Push(const T& newElement) {
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

        template <typename T, int N>
        T Stack<T, N>::Pop() {
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

        template <typename T, int N>
        int Stack<T, N>::GetCurrentIndex() {
            return m_current;
        }

    }
}
#endif // SHAPE_CPP
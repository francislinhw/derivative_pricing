// Exercise 1: Smart Pointers
// When we want to store different kind of shapes in the Array<T> class we created earlier, we need to store Shape* in the array. But when we are finished, we need to delete all shapes in the array explicitly which is easy to forget.
// The boost::shared_ptr<T> class stores a pointer and will delete the object automatically when nobody is referencing the object anymore. Thus instead of creating an array
// of Shape* we can create an array with boost::shared_ptr<Shape> and the deletion of the shapes will be done automatically.
// Thus create a program that creates an array with shared pointers for shapes (The template array class and shape hierarchy was created in earlier exercises). Fill it with various shapes and print them. Check if the shapes are automatically deleted.
// Tip:
// Use the following typedefs to simplify the code:
// // Typedef for a shared pointer to shape and
// // a typedef for an array with shapes stored as shared pointers. typedef boost::shared_ptr<Shape> ShapePtr;
// typedef Array<ShapePtr> ShapeArray;
#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.hpp"
#include "StackEmptyException.hpp"
#include "StackFullException.hpp"
#include "StackException.hpp"

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

        template <typename T>
        T Stack<T>::Pop() {
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

        template <typename T>
        int Stack<T>::GetCurrentIndex() {
            return m_current;
        }

    }
}
#endif // SHAPE_CPP
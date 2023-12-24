#ifndef STACK_H
#define STACK_H

#include "Array.hpp"

namespace francis {
    namespace Containers {

        template <typename T, int N>
        class Stack {
        private:
            int m_current; // Index for the current top of the stack
            Array<T> m_array; // Array to store stack elements

        public:
            Stack(); // Default constructor
            Stack(int size); // Constructor with a parameter to set size of the stack
            Stack(const Stack<T, N>& other); // Copy constructor
            ~Stack(); // Destructor

            Stack<T, N>& operator=(const Stack<T, N>& source); // Assignment operator

            void Push(const T& newElement); // Push a new element onto the stack
            T Pop(); // Pop an element from the stack
            int GetCurrentIndex();
        };

        // You would include the implementation of the template class here or in a separate implementation file (Stack.cpp)
    }
}
#include "Stack.cpp"
#endif // STACK_H

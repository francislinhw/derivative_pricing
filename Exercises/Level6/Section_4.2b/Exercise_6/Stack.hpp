#ifndef STACK_H
#define STACK_H

#include "Array.hpp"

namespace francis {
    namespace Containers {

        template <typename T, int size>
        class Stack {
        private:
            int m_current; // Index for the current top of the stack
            Array<T> m_array; // Array to store stack elements

        public:
            Stack(); // Default constructor
            // Stack(int startSize); // Constructor with a parameter to set size of the stack (Removed)
            Stack(const Stack<T, size>& other); // Copy constructor
            ~Stack(); // Destructor

            Stack<T, size>& operator=(const Stack<T, size>& source); // Assignment operator

            void Push(const T& newElement); // Push a new element onto the stack
            T Pop(); // Pop an element from the stack
            int GetCurrentIndex();
        };

        // You would include the implementation of the template class here or in a separate implementation file (Stack.cpp)
    }
}
#ifndef STACK_CPP
#include "Stack.cpp"
#endif
#endif // STACK_H

#ifndef STACK_H
#define STACK_H

#include "Array.hpp"

namespace francis {
    namespace Containers {

        template <typename T>
        class Stack {
        private:
            int m_current; // Index for the current top of the stack
            Array<T> m_array; // Array to store stack elements

        public:
            Stack(); // Default constructor
            Stack(int size); // Constructor with a parameter to set size of the stack
            Stack(const Stack<T>& other); // Copy constructor
            ~Stack(); // Destructor

            Stack<T>& operator=(const Stack<T>& source); // Assignment operator

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

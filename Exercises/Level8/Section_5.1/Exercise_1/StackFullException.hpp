#ifndef STACK_FULL_EXCEPTION_H
#define STACK_FULL_EXCEPTION_H

#include "StackException.hpp"
#include <string>

namespace francis {
    namespace Containers {

        class StackFullException : public StackException {
        private:
            int m_index;  // The erroneous array index
        public:
            StackFullException(int index) : m_index(index) {}

            std::string GetMessage() const override {
                return "Stack full exception at index " + std::to_string(m_index);
            }

            virtual ~StackFullException() {}  // Virtual destructor for proper cleanup
        };

    }
}

#endif

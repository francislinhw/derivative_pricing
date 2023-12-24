#ifndef STACK_EMPTY_EXCEPTION_H
#define STACK_EMPTY_EXCEPTION_H

#include "StackException.hpp"
#include <string>

namespace francis {
    namespace Containers {

        class StackEmptyException : public StackException {
        public:

            std::string GetMessage() const override {
                return "Stack empty exception.";
            }
            virtual ~StackEmptyException() {}  // Virtual destructor for proper cleanup
        };

    }
}

#endif

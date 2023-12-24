#ifndef STACK_EXCEPTION_H
#define STACK_EXCEPTION_H

#include <string>

namespace francis {
    namespace Containers {

        class StackException {
        public:
            virtual std::string GetMessage() const = 0;
            virtual ~StackException() {}  // Virtual destructor for proper cleanup
        };
    }
}

#endif

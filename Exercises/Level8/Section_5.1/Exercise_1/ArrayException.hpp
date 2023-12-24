#ifndef ARRAY_EXCEPTION_H
#define ARRAY_EXCEPTION_H

#include <string>

namespace francis {
namespace Containers {

        // Base class for array exceptions
        class ArrayException {
        public:
            // Abstract GetMessage function to be overridden by derived classes
            virtual std::string GetMessage() const = 0;
            virtual ~ArrayException() {}  // Virtual destructor for proper cleanup
        };
    }
} 

#endif // ARRAY_EXCEPTION_HPP

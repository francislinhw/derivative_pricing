#ifndef OUT_OF_BOUNDS_EXCEPTION_H
#define OUT_OF_BOUNDS_EXCEPTION_H
#include "ArrayException.hpp"

// Derived class for out of bounds exceptions
namespace francis{
    namespace Containers {
        class OutOfBoundsException : public ArrayException {
        private:
            int m_index;  // The erroneous array index
        public:
            // Constructor to initialize the erroneous index
            OutOfBoundsException(int index);

            // Override GetMessage to return a message about the out of bounds error
            virtual std::string GetMessage() const override;
        };
    }
}

#endif // POINT_H
#ifndef SIZE_MISMATCH_EXCEPTION_H
#define SIZE_MISMATCH_EXCEPTION_H
#include "ArrayException.hpp"

// Derived class for out of bounds exceptions
namespace francis{
    namespace Containers {
        class SizeMisMatchException : public ArrayException {
        private:
            int m_index_one;  // The erroneous array index
            int m_index_two;  // The erroneous array index
        public:
            // Constructor to initialize the erroneous index
            SizeMisMatchException(int indexOne, int indexTwo);

            // Override GetMessage to return a message about the out of bounds error
            virtual std::string GetMessage() const override;
        };
    }
}

#endif // POINT_H
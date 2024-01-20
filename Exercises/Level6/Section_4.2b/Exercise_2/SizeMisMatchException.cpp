#include "ArrayException.hpp"
#include "SizeMisMatchException.hpp"

// Derived class for out of bounds exceptions
namespace francis{
    namespace Containers {

        // Constructor to initialize the erroneous index
        SizeMisMatchException::SizeMisMatchException(int indexOne, int indexTwo)
         : m_index_one(indexOne), m_index_two(indexTwo) {}

        // Override GetMessage to return a message about the out of bounds error
        std::string SizeMisMatchException::GetMessage() const {
            return "Error: Array Sizes of " + std::to_string(m_index_one) +
            " and " + std::to_string(m_index_two) + " are mismatched.";
        }
    }
}

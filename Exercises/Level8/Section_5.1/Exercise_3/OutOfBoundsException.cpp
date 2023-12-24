#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"

// Derived class for out of bounds exceptions
namespace francis{
    namespace Containers {

        // Constructor to initialize the erroneous index
        OutOfBoundsException::OutOfBoundsException(int index) : m_index(index) {}

        // Override GetMessage to return a message about the out of bounds error
        std::string OutOfBoundsException::GetMessage() const {
            return "Error: Index " + std::to_string(m_index) + " is out of bounds.";
        }
    }
}

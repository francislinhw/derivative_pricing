#include "Shape.hpp"
#include <iostream>
#include <sstream>

namespace francis {
        namespace CAD {

            int m_id;

            Shape::Shape() : m_id(rand()) {} // Default constructor

            Shape::Shape(const Shape& source) : m_id(source.m_id) {} // Copy constructor

            Shape& Shape::operator=(const Shape& source) { // Assignment operator
                if (this != &source) {
                    m_id = source.m_id;
                }
                return *this;
            }

            Shape::~Shape() {} // Destructor

            int Shape::ID() const { // Getter for ID
                return m_id;
            }

            std::string Shape::ToString() const { // Virtual ToString function
                return "ID: " + std::to_string(m_id);
            }

    }
}
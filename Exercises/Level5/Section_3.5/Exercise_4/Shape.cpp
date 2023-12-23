#include "Shape.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <sstream>

namespace francis {
        namespace CAD {

            boost::uuids::uuid m_id;

            Shape::Shape() : m_id(boost::uuids::random_generator()()) {} // Default constructor

            Shape::Shape(const Shape& source) : m_id(source.m_id) {} // Copy constructor

            Shape& Shape::operator=(const Shape& source) { // Assignment operator
                if (this != &source) {
                    m_id = source.m_id;
                }
                return *this;
            }

            Shape::~Shape() {
                std::cout << "bye my shape.. (Destructor called)." << std::endl;
            } // Destructor

            boost::uuids::uuid Shape::ID() const { // Getter for ID
                return m_id;
            }

            std::string Shape::ToString() const { // Virtual ToString function
                return "ID: " + to_string(m_id);
            }

    }
}
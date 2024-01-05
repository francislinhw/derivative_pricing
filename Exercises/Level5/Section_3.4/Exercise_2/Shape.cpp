// First create a Shape base class.
// • Add a source- and header file for a Shape class.
// • Add a data member for an id number of type int.
// • Add a default constructor that initializes the id using a random number. You can use
// the rand() function from the “stdlib.h” header file.
// • Add a copy constructor that copies the id member.
// • Add an assignment operator that copies the id member.
// • Add a ToString() function that returns the id as string e.g. “ID: 123”.
// • Add an ID() function the retrieve the id of the shape.
#include "Shape.hpp"
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/uuid_generators.hpp>
// #include <boost/uuid/uuid_io.hpp> I used uuid as the the id, but I followed the instruction of int for 3.4.2, but I will keep using uuid in the later exercises.
#include <iostream>
#include <sstream>

namespace francis {
        namespace CAD {

            // boost::uuids::uuid m_id;
            int m_id;

            // Shape::Shape() : m_id(boost::uuids::random_generator()()) {} // Default constructor
            Shape::Shape() : m_id(rand()) {} // Default constructor

            Shape::Shape(const Shape& source) : m_id(source.m_id) {} // Copy constructor

            Shape& Shape::operator=(const Shape& source) { // Assignment operator
                if (this != &source) {
                    m_id = source.m_id;
                }
                return *this;
            }

            Shape::~Shape() {} // Destructor

            // boost::uuids::uuid Shape::ID() const { // Getter for ID
            //     return m_id;
            // }
            
            int Shape::ID() const { // Getter for ID
                return m_id;
            }

            std::string Shape::ToString() const { // Virtual ToString function
                return "ID: " + std::to_string(m_id); //to_string(m_id);
            }

    }
}
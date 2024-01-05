#ifndef SHAPE_HPP
#define SHAPE_HPP
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/uuid_generators.hpp>
// #include <boost/uuid/uuid_io.hpp>
#include <string>
// #include <cstdlib> This is consistent with the C++ standard library's conventions. 
#include <ctime>
#include <stdlib.h> // This is more typical of C-style inclusion

namespace francis{
    namespace CAD {

        class Shape {
        private:
            // boost::uuids::uuid m_id;
            int m_id;

        public:
            Shape(); // Default constructor

            Shape(const Shape& source);

            Shape& operator=(const Shape& source);

            virtual ~Shape(); // Destructor

            // boost::uuids::uuid ID() const; // Getter for ID
            int ID() const; // Getter for ID

            virtual std::string ToString() const; 
        };

    }
}

#endif // SHAPE_HPP
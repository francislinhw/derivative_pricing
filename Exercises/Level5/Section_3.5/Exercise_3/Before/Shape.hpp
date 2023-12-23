#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>
#include <cstdlib>
#include <ctime>

namespace francis{
    namespace CAD {

        class Shape {
        private:
            boost::uuids::uuid m_id;

        public:
            Shape(); // Default constructor

            Shape(const Shape& source);

            Shape& operator=(const Shape& source);

            ~Shape(); // Destructor

            boost::uuids::uuid ID() const; // Getter for ID

            virtual std::string ToString() const; 
        };

    }
}

#endif // SHAPE_HPP
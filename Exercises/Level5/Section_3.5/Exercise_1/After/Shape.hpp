#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include <stdlib.h>
#include <ctime>

namespace francis{
    namespace CAD {

        class Shape {
        private:
            int m_id;

        public:
            Shape(); // Default constructor

            Shape(const Shape& source);

            Shape& operator=(const Shape& source);

            virtual ~Shape(); // Destructor

            int ID() const; // Getter for ID

            virtual std::string ToString() const; // It will enable functional override by its inheritence.
        };

    }
}

#endif // SHAPE_HPP
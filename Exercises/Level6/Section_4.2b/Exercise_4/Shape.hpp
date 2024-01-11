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

            friend std::ostream& operator<<(std::ostream& os, const Shape& source);

            virtual ~Shape(); // Destructor

            int ID() const; // Getter for ID

            virtual std::string ToString() const = 0;

            virtual void Draw() const = 0; // Pure virtual function makes Shape an abstract class

            void Print() const; // Template Method
        };
    }
}

#endif // SHAPE_HPP
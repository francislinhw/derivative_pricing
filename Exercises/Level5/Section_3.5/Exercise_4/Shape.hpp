#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include <cstdlib>
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

            virtual std::string ToString() const = 0;

            // What implementation did you give the Draw() function in Shape?
            virtual void Draw() const = 0; // Pure virtual function makes Shape an abstract class
        };
    }
}

#endif // SHAPE_HPP
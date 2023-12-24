#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
#include <string>

namespace francis{
    namespace CAD {
        class Line : public Shape {
        private:
            Point startPoint;
            Point endPoint;

        public:
            Line();  // Default constructor
            Line(const Point& start, const Point& end);  // Constructor with start- and end-point
            Line(const Line& line);  // Copy constructor
            ~Line();  // Destructor

            // Getters for the start- and end-points
            Point& P1();
            Point& P2();

            // Getters for the start- and end-points
            const Point& P1() const;
            const Point& P2() const;

            // Setters for the start- and end-points
            void P1(const Point& p);
            void P2(const Point& p);

            // Operator Overloading
            Line operator - () const;
            Line operator - (const Line& p) const;
            Line operator * (double factor) const;
            Line operator + (const Line& p) const;
            bool operator == (const Line& p) const;
            Line& operator = (const Line& source);
            Line& operator *= (double factor);

            std::string ToString() const override;  // Description of the line
            double Length() const;  // Calculate the length of the line
            friend std::ostream& operator<<(std::ostream& os, const Line& l);
            void Draw() const override;
        };
    }
}

#endif // LINE_HPP

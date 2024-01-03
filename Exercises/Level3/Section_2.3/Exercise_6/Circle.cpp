// Note that instead of using your own PI value, Microsoft’s version of the math library defines a constant for PI named M_PI. 
// But because it is not standard you need to enable that define by setting the _USE_MATH_DEFINES symbol in the project settings or add before including “cmath”:
#define _USE_MATH_DEFINES
#include "Circle.hpp"
#include <sstream>

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>

// Default constructor
Circle::Circle() : center(0, 0), radius(1) {}

// Constructor with a center and radius
Circle::Circle(const Point& c, double r) : center(c), radius(r) {}

// Copy constructor
Circle::Circle(const Circle& other) : center(other.center), radius(other.radius) {}

// Destructor
Circle::~Circle() {}

// Getter for the center point
Point Circle::CentrePoint() const { return center; }

// Setter for the center point
void Circle::CentrePoint(const Point& c) { center = c; }

// Getter for the radius
double Circle::Radius() const { return radius; }

// Setter for the radius
void Circle::Radius(double r) { radius = r; }

// Calculate the diameter
double Circle::Diameter() const { return 2 * radius; }

// Calculate the area
double Circle::Area() const { return M_PI * radius * radius; }

// Calculate the circumference
double Circle::Circumference() const { return 2 * M_PI * radius; }

// String representation of the circle
std::string Circle::ToString() const {
    std::stringstream stream;
    stream << "Circle: Centre at " << center.ToString() << ", Radius " << radius;
    return stream.str();
}

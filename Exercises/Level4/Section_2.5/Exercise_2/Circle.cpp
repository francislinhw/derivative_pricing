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
    stream << "Circle: Centre at " << center << ", Radius " << radius;
    return stream.str();
}

// Circle.cpp definitions for operator overloading

// Negate the radius of the circle but that is a bit not nature
Circle Circle::operator - () const {
    return Circle(CentrePoint(), -Radius());
}

// Scale the circle by a factor
Circle Circle::operator * (double factor) const {
    return Circle(CentrePoint(), Radius() * factor);
}

// Add two circles by adding their radii
Circle Circle::operator + (const Circle& c) const {
    return Circle(CentrePoint(), Radius() + c.Radius());
}

// Equality check based on the center point and radius
bool Circle::operator == (const Circle& c) const {
    return (CentrePoint() == c.CentrePoint()) && (Radius() == c.Radius());
}

// Assignment operator
Circle& Circle::operator = (const Circle& source) {
    if (this == &source) {
        return *this; // Handle self-assignment
    }
    CentrePoint(source.CentrePoint());
    Radius(source.Radius());
    return *this;
}

// Scale the circle's radius and assign the new value
Circle& Circle::operator *= (double factor) {
    Radius(Radius() * factor);
    return *this;
}

// Friend declaration for << operator
std::ostream& operator << (std::ostream& os, const Circle& circle) {
    os << "Circle: Centre at " << circle.center << ", Radius " << circle.radius;
    return os;
}

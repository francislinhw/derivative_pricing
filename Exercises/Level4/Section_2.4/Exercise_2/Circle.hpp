#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"
#include <string>

class Circle {
private:
    Point center;
    double radius;

public:
    Circle();  // Default constructor
    Circle(const Point& center, double r);  // Constructor with a center and radius
    Circle(const Circle& other);  // Copy constructor
    ~Circle();  // Destructor

    Point CentrePoint() const;  // Getter for the center point
    void CentrePoint(const Point& center);  // Setter for the center point

    double Radius() const;  // Getter for the radius
    void Radius(double r);  // Setter for the radius

    // Operator Overloading
    Circle operator - () const;
    Circle operator * (double factor) const;
    Circle operator + (const Circle& p) const;
    bool operator == (const Circle& p) const;
    Circle& operator = (const Circle& source);
    Circle& operator *= (double factor);

    double Diameter() const;  // Calculate the diameter
    double Area() const;  // Calculate the area
    double Circumference() const;  // Calculate the circumference

    std::string ToString() const;  // String representation of the circle
};

std::ostream& operator<<(std::ostream& os, const Circle& c);

#endif // CIRCLE_HPP

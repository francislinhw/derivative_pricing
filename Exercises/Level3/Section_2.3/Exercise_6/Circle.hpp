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

    double Diameter() const;  // Calculate the diameter
    double Area() const;  // Calculate the area
    double Circumference() const;  // Calculate the circumference

    std::string ToString() const;  // String representation of the circle
};

#endif // CIRCLE_HPP

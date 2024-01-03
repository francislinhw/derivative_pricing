#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>  // For std::sqrt

// Default constructor - Initialize to a default of (0,0)
Point::Point() : m_x(0), m_y(0){
    std::cout << "Default constructor called." << std::endl;
} 

// Constructor with parameters
Point::Point(double x, double y) : m_x(x), m_y(y) {
    std::cout << "Custom constructor called." << std::endl;
}

// Copy constructor
Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) {
    std::cout << "Copy constructor called." << std::endl;
}

// Destructor
Point::~Point() {
    std::cout << "bye my point.. (Destructor called)." << std::endl;
}

double Point::GetX() const { return m_x; }
double Point::GetY() const { return m_y; }

void Point::SetX(double x) { m_x = x; }
void Point::SetY(double y) { m_y = y; }

std::string Point::ToString() const {
    std::stringstream stream;
    stream << "Point(" << m_x << ", " << m_y << ")";
    return stream.str();
}

double Point::DistanceOrigin() const {
    return std::sqrt((m_x * m_x) + (m_y * m_y));
}

// Method to calculate distance to another point
double Point::DistanceWithChange(Point& p) {
    p.SetX(4); // It is okay to alter the input point.
    double dx = m_x - p.m_x; double dy = m_y - p.m_y;
    return std::sqrt(dx*dx + dy*dy);
}


double Point::Distance(const Point& p) const {
    return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}

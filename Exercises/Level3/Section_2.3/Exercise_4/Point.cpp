#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <cmath>  // For std::sqrt

Point::Point() : m_x(0), m_y(0) { // Initialize to a default of (0,0)
        std::cout << "Default constructor called." << std::endl;
    } 

Point::Point(double x, double y) : m_x(x), m_y(y) {
        std::cout << "Custom constructor called." << std::endl;
    }

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) {
        std::cout << "Copy constructor called." << std::endl;
    }

Point::~Point()  {
        std::cout << "bye my point.. (Destructor called)." << std::endl;
    } // Destructor

// We need to mark the x, y- coordinate getter as const by making it a const function for const points.
double Point::X() const { return m_x; }
double Point::Y() const { return m_y; }

void Point::X(double new_x) { m_x = new_x; }
void Point::Y(double new_y) { m_y = new_y; }

double Point::Distance() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(const Point& p) const {
        double dx = m_x - p.m_x;
        double dy = m_y - p.m_y;
        return std::sqrt(dx * dx + dy * dy);
    }

std::string Point::ToString() const {
    std::stringstream stream;
    stream << "Point(" << m_x << ", " << m_y << ")";
    return stream.str();
}

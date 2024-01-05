#include "Point.hpp"
#include <iostream>
#include <sstream>

Point::Point() : m_x(0), m_y(0) {
    // std::cout << "Default constructor called." << std::endl;
}

Point::Point(double x, double y) : m_x(x), m_y(y) {
    // std::cout << "Custom constructor called." << std::endl;
}

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) {
    // std::cout << "Copy constructor called." << std::endl;
}

Point::Point(double value): m_x(value), m_y(value) {}

Point::~Point() {
    // std::cout << "bye my point.. (Destructor called)." << std::endl;
}

double Point::Distance() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(const Point& p) const {
    double dx = m_x - p.m_x;
    double dy = m_y - p.m_y;
    return std::sqrt(dx * dx + dy * dy);
}

std::string Point::ToString() const {
    std::ostringstream oss;
    oss << "Point(" << m_x << ", " << m_y << ")";
    return oss.str();
}

// Operator Overloading
Point Point::operator - () const {
    return Point(-m_x, -m_y);
}

Point Point::operator - (const Point& p) const {
    return Point(m_x - p.m_x, m_y - p.m_y);
}

Point Point::operator * (double factor) const {
    return Point(m_x * factor, m_y * factor);
}

Point Point::operator + (const Point& p) const {
    return Point(m_x + p.m_x, m_y + p.m_y);
}

bool Point::operator == (const Point& p) const {
    return (m_x == p.m_x) && (m_y == p.m_y);
}

Point& Point::operator = (const Point& source) {
    // Protect against self-assignment
    if (this == &source) {
        return *this;
    }
    m_x = source.m_x;
    m_y = source.m_y;
    return *this;
}

Point& Point::operator *= (double factor) {
    m_x *= factor;
    m_y *= factor;
    return *this;
}


// Friend declaration for << operator
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point(" << p.m_x << ", " << p.m_y << ")";
    return os;
}
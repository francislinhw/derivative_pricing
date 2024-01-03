#include "Point.hpp"
#include <iostream>
#include <sstream>

// Default constructor - Initialize to a default of (0,0)
Point::Point() : m_x(0), m_y(0){
        std::cout << "Default constructor called." << std::endl;
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

double Point::Distance(const Point p) const {
    return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}

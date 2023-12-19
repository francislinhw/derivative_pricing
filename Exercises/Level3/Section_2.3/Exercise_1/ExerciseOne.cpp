#include <iostream>
#include <cmath>

class Point {
private:
    double m_x, m_y;

public:
    // Default constructor
    Point() : m_x(0), m_y(0) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Custom constructor
    Point(double x, double y) : m_x(x), m_y(y) {
        std::cout << "Custom constructor called." << std::endl;
    }

    // Copy constructor
    Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) {
        std::cout << "Copy constructor called." << std::endl;
    }

    // Destructor
    ~Point() {
        std::cout << "bye my point.. (Destructor called)." << std::endl;
    }

    // Method to calculate distance to another point
    double Distance(const Point p) const {
        return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
    }
};

int main() {
    Point p1; // Default constructor
    Point p2(3.0, 4.0); // Custom constructor

    std::cout << "Distance: " << p1.Distance(p2) << std::endl; // Copy constructor is called for p2 to Distance()

    return 0; // Destructor called for p1 and p2
}

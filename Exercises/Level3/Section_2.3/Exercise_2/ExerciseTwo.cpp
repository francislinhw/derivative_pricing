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

    void SetX(double x) { m_x = x; }

    // Method to calculate distance to another point
    double DistanceWithChange(Point& p) {
        p.SetX(4); // It is okay to alter the input point.
        double dx = m_x - p.m_x; double dy = m_y - p.m_y;
        return std::sqrt(dx*dx + dy*dy);
    }

    // Method to calculate distance to another point
    double Distance(const Point& p) const {
        double dx = m_x - p.m_x; double dy = m_y - p.m_y;
        return std::sqrt(dx*dx + dy*dy);
    }

};

int main() {
    Point p1; // Default constructor
    Point p2(3.0, 4.0); // Custom constructor

    std::cout << "Distance: " << p1.Distance(p2) << std::endl; // Called by reference without Copy Constructor
    std::cout << "Distance with Change: " << p1.DistanceWithChange(p2) << std::endl; // Called by reference without Copy Constructor

    return 0; // Destructor called for p1 and p2
}

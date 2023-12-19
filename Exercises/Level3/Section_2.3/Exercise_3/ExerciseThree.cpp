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

    // Overloaded getters and setters for x
    void X(double new_x) { m_x = new_x; }
    double X() const { return m_x; }

    // Overloaded getters and setters for y
    void Y(double new_y) { m_y = new_y; }
    double Y() const { return m_y; }

    // Overloaded Distance functions
    // Distance from the origin
    double Distance() const {
        return std::sqrt(m_x * m_x + m_y * m_y);
    }
    
    // Distance between two points
    double Distance(const Point& p) const {
        double dx = m_x - p.m_x;
        double dy = m_y - p.m_y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

int main() {
    Point p1;
    Point p2(10.0, 24.0);

    p1.X(5.0); // Set x using overloaded setter
    p1.Y(12.0); // Set y using overloaded setter

    std::cout << "p1: " << p1.X() << ", " << p1.Y() << std::endl; // Use overloaded getters
    std::cout << "Distance from p1 to origin: " << p1.Distance() << std::endl;
    std::cout << "Distance from p1 to p2: " << p1.Distance(p2) << std::endl;

    return 0;
}

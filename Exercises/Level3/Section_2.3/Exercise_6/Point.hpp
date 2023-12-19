#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
private:
    double m_x, m_y;

public:
    // Constructors and destructor declaration
    Point();
    Point(double x, double y);
    Point(const Point& p);
    ~Point();

    // Overloaded getters and setters for x
    void X(double new_x);
    double X() const; // Corrected return type

    // Overloaded getters and setters for y
    void Y(double new_y);
    double Y() const; // Corrected return type

    // Distance functions declaration
    double Distance() const; // Corrected declaration
    double Distance(const Point& p) const; // Corrected declaration

    // ToString function declaration
    std::string ToString() const; // Removed extra 'const' in return type
};

#endif // POINT_H
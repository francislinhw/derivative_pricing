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
    double X() const; // Corrected as const

    // Overloaded getters and setters for y
    void Y(double new_y);
    double Y() const; // Corrected as const

    // Distance functions declaration
    double Distance() const; // Corrected as const declaration
    double Distance(const Point& p) const; // Corrected as const declaration

    // ToString function declaration
    std::string ToString() const; // Corrected as const
};

#endif // POINT_H
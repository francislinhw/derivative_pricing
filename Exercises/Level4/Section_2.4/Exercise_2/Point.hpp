#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <cmath> // For std::sqrt in Distance()

class Point {
private:
    double m_x, m_y;

public:
    // Constructors
    Point();
    Point(double x, double y);
    Point(const Point& p);

    // Destructor
    ~Point();

    // Getters
    double X() const; // Declaration only
    double Y() const; // Declaration only

    // Setters
    void X(double new_x) {
        m_x = new_x;
        // std::cout << "Set X by default inline function." << std::endl;
    }
    void Y(double new_y) {
        m_y = new_y;
        // std::cout << "Set Y by default inline function." << std::endl;
    }

    // Operator Overloading
    Point operator - () const;
    Point operator - (const Point& p) const;
    Point operator * (double factor) const;
    Point operator + (const Point& p) const;
    bool operator == (const Point& p) const;
    Point& operator = (const Point& source);
    Point& operator *= (double factor);

    // Other member functions
    double Distance() const;
    double Distance(const Point& p) const;
    std::string ToString() const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

inline double Point::X() const {
    // std::cout << "Get X by Normal inline function." << std::endl;
    return m_x;
}
inline double Point::Y() const {
    // std::cout << "Get X by Normal inline function." << std::endl;
    return m_y;
}

#endif // POINT_H

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
    inline void X(double new_x) {
        m_x = new_x;
        std::cout << "Set X by default inline function." << std::endl;
    }
    inline void Y(double new_y) {
        m_y = new_y;
        std::cout << "Set Y by default inline function." << std::endl;
    }

    // Other member functions
    double Distance() const;
    double Distance(const Point& p) const;
    std::string ToString() const;
};

inline double Point::X() const {
    std::cout << "Get X by Normal inline function." << std::endl;
    return m_x;
}
inline double Point::Y() const {
    std::cout << "Get X by Normal inline function." << std::endl;
    return m_y;
}

#endif // POINT_H

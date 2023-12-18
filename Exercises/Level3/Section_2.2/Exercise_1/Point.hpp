#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
private:
    double m_x; // The x-coordinate
    double m_y; // The y-coordinate

public:
    Point(); // Default constructor
    ~Point(); // Destructor

    double GetX() const; // Getter for the x-coordinate
    double GetY() const; // Getter for the y-coordinate

    void SetX(double x); // Setter for the x-coordinate
    void SetY(double y); // Setter for the y-coordinate

    std::string ToString() const; // Returns a string description of the point
};

#endif // POINT_H

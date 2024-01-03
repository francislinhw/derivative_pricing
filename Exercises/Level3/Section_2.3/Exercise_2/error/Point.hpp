// In this exercise we are going to add distance functions to the Point class. 
// The distance functions have the following signature:
// double DistanceOrigin(); 
// Calculate the distance to the origin (0, 0). double Distance(Point p); 
// Calculate the distance between two points.
#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
private:
    double m_x; // The x-coordinate
    double m_y; // The y-coordinate

public:
    Point(); // Default constructor
    Point(double x, double y); // Initializes with x and y Constructor
    Point(const Point& p); // Copy constructor
    ~Point(); // Destructor

    double GetX() const; // Getter for the x-coordinate
    double GetY() const; // Getter for the y-coordinate

    void SetX(double x); // Setter for the x-coordinate
    void SetY(double y); // Setter for the y-coordinate

    std::string ToString() const; // Returns a string description of the point
    double DistanceOrigin() const; // Calculate the distance to the origin
    double Distance(const Point& p) const; // Calculate the distance between two points
    double DistanceWithChange(Point& p); // Calculate the distance between two points but change the input point
};

#endif // POINT_H

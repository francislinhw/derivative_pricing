#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"
#include <string>

class Line {
private:
    Point startPoint;
    Point endPoint;

public:
    Line();  // Default constructor
    Line(const Point& start, const Point& end);  // Constructor with start- and end-point
    Line(const Line& line);  // Copy constructor
    ~Line();  // Destructor

    // Getters for the start- and end-points
    const Point& P1() const;
    const Point& P2() const;

    // Setters for the start- and end-points
    void P1(const Point& p);
    void P2(const Point& p);

    std::string ToString() const;  // Description of the line
    double Length() const;  // Calculate the length of the line
};

#endif // LINE_HPP

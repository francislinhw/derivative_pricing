#include "Line.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

// Default constructor
Line::Line() : startPoint(0, 0), endPoint(0, 0) {
    std::cout << "Line Default constructor called." << std::endl;
}

// Constructor with start- and end-point
Line::Line(const Point& start, const Point& end) : startPoint(start), endPoint(end) {
    std::cout << "Line Custom constructor called." << std::endl;
}

// Copy constructor
Line::Line(const Line& other) : startPoint(other.startPoint), endPoint(other.endPoint) {
    std::cout << "Line Copy constructor called." << std::endl;
}

// Destructor
Line::~Line() {
    std::cout << "bye my line... (destructor called)." << std::endl;
}

// Getters for the start- and end-points
const Point& Line::P1() const { return startPoint; }
const Point& Line::P2() const { return endPoint; }

// Setters for the start- and end-points
void Line::P1(const Point& p) { startPoint = p; }
void Line::P2(const Point& p) { endPoint = p; }

// ToString function
std::string Line::ToString() const {
    std::stringstream ss;
    ss << "Line from " << startPoint.ToString() << " to " << endPoint.ToString();
    return ss.str();
}

// Length function
// • A Length() function that returns the length of the line. Note that you can use the
// distance function on the embeddedPoint objects to calculate the length. This
// mechanism is called “delegation”.
double Line::Length() const {
    return startPoint.Distance(endPoint);
}

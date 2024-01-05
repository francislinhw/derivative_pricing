// Next the Point and Line classes (and the Circle class if applicable) must derive from Shape.
// • Add the Shape class in the inheritance list of the Point,Line and optionally the Circle class.
// • The constructors of the Point, Line and optionally the Circle class should call the appropriate constructor in the Shapebase class.
// • The assignment operator should call the assignment operator of theShapebase class. Otherwise the shape data will not be copied.
// • Finally add code to the main program to test inheritance:
#include "Line.hpp"
#include <sstream>
#include <cmath>

namespace francis {
    namespace CAD {

        // Default constructor
        Line::Line() : Shape(), startPoint(0, 0), endPoint(0, 0) {}

        // Constructor with start- and end-point
        Line::Line(const Point& start, const Point& end) : Shape(), startPoint(start), endPoint(end) {}

        // Copy constructor
        Line::Line(const Line& other) : Shape(), startPoint(other.startPoint), endPoint(other.endPoint) {}

        // Destructor
        Line::~Line() {}

        // Getters for the start- and end-points
        const Point& Line::P1() const { return startPoint; }
        const Point& Line::P2() const { return endPoint; }

        // Setters for the start- and end-points
        void Line::P1(const Point& p) { startPoint = p; }
        void Line::P2(const Point& p) { endPoint = p; }

        // ToString function
        std::string Line::ToString() const {
            std::stringstream ss;
            ss << "Line from " << startPoint << " to " << endPoint;
            ss << " ID: " << std::to_string(ID());
            return ss.str();
        }

        // Length function
        double Line::Length() const {
            return startPoint.Distance(endPoint);
        }

        // Negate both points of the line
        Line Line::operator - () const {
            return Line(-startPoint, -endPoint);
        }

        // Add two lines by adding their corresponding points
        Line Line::operator - (const Line& l) const {
            return Line(startPoint - l.startPoint, endPoint - l.endPoint);
        }

        // Scale the line by a factor, scaling both points
        Line Line::operator * (double factor) const {
            return Line(startPoint * factor, endPoint * factor);
        }

        // Add two lines by adding their corresponding points
        Line Line::operator + (const Line& l) const {
            return Line(startPoint + l.startPoint, endPoint + l.endPoint);
        }

        // Equality check based on start and end points
        bool Line::operator == (const Line& l) const {
            return (startPoint == l.startPoint) && (endPoint == l.endPoint);
        }

        // Assignment operator
        Line& Line::operator = (const Line& source) {
            if (this == &source) {
                return *this; // Handle self-assignment
            }

            Shape::operator=(source); // Call base class assignment operator
            startPoint = source.startPoint;
            endPoint = source.endPoint;
            return *this;
        }

        // Scale the line and assign the new values to the points
        Line& Line::operator *= (double factor) {
            startPoint *= factor;
            endPoint *= factor;
            return *this;
        }

        // Friend declaration for << operator
        std::ostream& operator << (std::ostream& os, const Line& line) {
            os << "Line from " << line.startPoint << " to " << line.endPoint;
            return os;
        }
    }
}

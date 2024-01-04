#include "Line.hpp"
#include <sstream>
#include <cmath>

namespace francis {
    namespace CAD {

        // Default constructor
        Line::Line() : startPoint(0, 0), endPoint(0, 0) {}

        // Constructor with start- and end-point
        Line::Line(const Point& start, const Point& end) : startPoint(start), endPoint(end) {}

        // Copy constructor
        Line::Line(const Line& other) : startPoint(other.startPoint), endPoint(other.endPoint) {}

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
        std::ostream& operator << (std::ostream& os, const Line& l) {
            os << l.ToString();
            return os;
        }
    }
}

#include <boost/variant.hpp>
#include "Point.hpp" // Assuming Point, Line, Circle classes are defined
#include "Line.hpp"
#include "Circle.hpp"


using francis::CAD::Point;
using francis::CAD::Shape;
using francis::CAD::Circle;
using francis::CAD::Line;

class MoveShapeVisitor : public boost::static_visitor<> {
private:
    double m_dx, m_dy;
public:
    MoveShapeVisitor(double dx, double dy) : m_dx(dx), m_dy(dy) {}

    void operator() (Point& p) const {
        p.X(p.X() + m_dx);
        p.Y(p.Y() + m_dy);
    }

    void operator() (Line& l) const {
        l.P1().X(l.P1().X() + m_dx);
        l.P1().Y(l.P1().Y() + m_dy);
        l.P2().X(l.P2().X() + m_dx);
        l.P2().Y(l.P2().Y() + m_dy);
    }

    void operator() (Circle& c) const {
        c.CentrePoint().X(c.CentrePoint().X() + m_dx);
        c.CentrePoint().Y(c.CentrePoint().Y() + m_dy);
    }
};
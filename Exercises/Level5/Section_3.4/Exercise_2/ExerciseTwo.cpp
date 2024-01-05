// Exercise 2: Creating Shape Base Class
// It can be useful to create a hierarchy of related classes using base- and derived classes.
// • Classes are related (same family)
// • Common data and functionality can be put in a base class.
// • You can work with derived classes as if it is the base class.
// In this exercise we are going to transform the Point and Line class into a Shape hierarchy as shown in Figure 1.
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"

using namespace std;
using francis::CAD::Shape;
using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    
    Shape s; // Create shape.
    Point p(10, 20); // Create point.
    Line l(Point(1,2), Point(3, 4)); // Create line.
    
    cout << s.ToString() << endl; // Print shape.
    cout << p.ToString() << endl; // Print point.
    cout << l.ToString() << endl; // Print line.
    
    cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
    cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work? Yes, it works because of inheritance.
    cout << "Line ID: " << l.ID() << endl;  // ID of the line. Does this work? Yes, it works because of inheritance.
    
    Shape* sp; // Create pointer to a shape variable.
    sp = &p; // Point in a shape variable. Possible? Yes, the Point class is also a Shape (inheritance).
    cout << sp->ToString() << endl; // What is printed? It prints the ToSring() from the Point object: Point(10, 20)

    Point p2;
    p2 = p;
    cout << p2.ToString() << ", " << p2.ID() << endl; // Is the ID copied if you do not call, No, because I have implemnted an operater '=' in Point
                                                      // the base class assignment in point? Yes, I include the shape '=' in the Point '='.

    return 0;
    /*
     * Answers are in the above comments.
     *
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * ID: 1663560013
     * Point(10, 20) ID: 1363538198
     * Line from Point(1, 2) to Point(3, 4) ID: 912734261
     * Shape ID: 1663560013
     * Point ID: 1363538198
     * Line ID: 912734261
     * Point(10, 20) ID: 1363538198
     * Point(10, 20) ID: 1363538198, 1363538198
     * 
    */
}

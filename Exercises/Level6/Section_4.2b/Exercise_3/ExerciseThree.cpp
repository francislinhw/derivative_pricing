// Exercise 3: Point Array (concrete inheritance)
// You can create an array of points by directly instantiating the Array class for the Point class.
// This works well but we can’t add points specific functionality to the Array class in this way.
// A solution is to create a derived class of which the template argument is fixed to a specific type
// (concrete inheritance) as shown in Figure 3.
// In this exercise we will create a PointArray which is derived from Array with the template argument set to Point.
// • Add a new source- and header file for the PointArray class to your project.
// • Create a regular class called PointArray which is derived from Array.
//   The template argument given to Array is Point.
// • Since they are not inherited, create proper constructors, destructor and assignment
//   operator and call the base class where appropriate.
// • Now we can add functionality specific for a point array. For example add a Length()
//   function that returns the total length between the points in the array. • Change the main program to test the point array.
#include "Array.cpp"
#include "NumericArray.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"
#include "PointArray.hpp"

using namespace std;
using francis::CAD::Shape;
using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    PointArray pa(3);
    pa.SetElement(0, Point(1, 2));
    pa.SetElement(1, Point(1, 3));
    pa.SetElement(2, Point(1, 4));

    std::cout << "Total length: " << pa.Length() << std::endl;

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * Total length: 2 // |2 - 4|
    */
}
#include "Array.hpp"
#include "NumericArray.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"

using namespace std;
using francis::CAD::Shape;
using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    Stack<Shape*> myStack(3); // Create a stack of int with a size of 5

    try {
        // Push elements ...
        myStack.Push(new Point(1, 3));                    // [2]
        myStack.Push(new Circle(Point(1, 4), 5));         // [1]
        myStack.Push(new Line(Point(1, 1), Point(2, 2))); // [0]

        for (int i = 0; i!=3; i++) {
            Shape* poppedValue = myStack.Pop();
            if (poppedValue != nullptr) { // Check for null before dereferencing
                std::cout << "Popped: " << *poppedValue << std::endl; // Dereference the pointer
                delete poppedValue; // Delete the Shape to prevent memory leaks
            } else {
                std::cout << "Popped: " << poppedValue << std::endl;               
            }
        }

    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}
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
#include "StackException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

using namespace std;
using francis::CAD::Shape;
using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    Stack<Shape*, 5> myStack;

    try {
        // Push elements onto the stack
        for (int i = 0; i < 4; ++i) {
            myStack.Push(new Point(i, i + i));
        }
        myStack.Push(new Circle(Point(1, 1), 3));
    } catch (const StackException& e) {
        std::cerr << e.GetMessage() << std::endl;
    }

    try {
        // Pop elements from the stack
        for (int i = 0; i < 5; ++i) {
            Shape* poppedValue = myStack.Pop();
            std::cout << "Popped: " << *poppedValue << std::endl;
        }
    } catch (const StackException& e) {
        std::cerr << e.GetMessage() << std::endl;
    }

    return 0;
}
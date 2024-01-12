// Exercise 6: Value Template Arguments
// Not only generic types can act as template variable. You can also use an int value as template variable.
// This value can then be used inside the class.
// Change the Stack class so that it uses a value template argument to set the stack size
// (remove the constructor with size):
// template <typename T, int size> class Stack {};
// Note that now only stacks with the same size template argument can be copied/assigned.
#include "Array.cpp"
#include "NumericArray.cpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"
#include "PointArray.hpp"
#include "Stack.cpp"
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
    // Stack<Shape*, 4> testStack; A different size stack is not allowed copied/assigned.

    try {
        // Push elements onto the stack
        for (int i = 0; i < 4; ++i) {
            myStack.Push(new Point(i, i + i));
        }
        myStack.Push(new Circle(Point(1, 1), 3));
    } catch (const StackException& e) {
        std::cerr << e.GetMessage() << std::endl;
    }

    // testStack = myStack; // error: no viable overloaded '=' as a different size stack is not allowed copied/assigned.

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
    /*
     * 
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Popped: Circle: Centre at Point(1, 1), Radius 3
     * Circle ID: 470211272
     * Popped: Point(3, 6)
     * Point ID: 984943658
     * Popped: Point(2, 4)
     * Point ID: 1622650073
     * Popped: Point(1, 2)
     * Point ID: 282475249
     * Popped: Point(0, 0)
     * Point ID: 16807
    */
}
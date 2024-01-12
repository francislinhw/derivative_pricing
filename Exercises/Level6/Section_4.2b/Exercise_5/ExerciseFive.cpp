// Exercise 5: Layering Exceptions
// When you use the Stack class and the stack is full or empty when pushing or popping an element you get an exception from the Array class.
// Since the user of the Stack class does not know that an Array class is used internally,
// you don’t want that the client must know about the array exceptions.
// Thus the array exception must be translated to a stack exception.
// • The stack exception classes can be implemented in a header file only for simplicity.
// • Create a StackException base class and
// a StackFullException and StackEmptyException derived class.
// • In the Push() function of stack, place the code in a try ... catch block and catch the
// array exception. In the catch handler, throw a StackFullException exception.
// • In the Pop() function of stack, place the code in a try ... catch block and catch the
// array exception. In the catch handler, throw a StackEmptyException exception. Also
// set the current index back to 0.
// • Change the test program so it catches the stack exception.
#include "Array.cpp"
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
    Stack<int> myStack(5);

    try {
        // Push elements onto the stack
        for (int i = 0; i < 5; ++i) {
            myStack.Push(i);
        }
        myStack.Push(6); // This should throw a StackFullException
    } catch (const StackException& e) {
        std::cerr << e.GetMessage() << std::endl;
    }

    try {
        // Pop elements from the stack
        for (int i = 0; i < 6; ++i) {
            std::cout << "Popped: " << myStack.Pop() << std::endl;
        }
    } catch (const StackException& e) {
        std::cerr << e.GetMessage() << std::endl;
    }

    std::cout << "Current Index after Empty Exception:" << to_string(myStack.GetCurrentIndex()) << std::endl;

    return 0;
    /***
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Stack full exception at index 5
     * Popped: 4
     * Popped: 3
     * Popped: 2
     * Popped: 1
     * Popped: 0
     * Popped: Stack empty exception.
     * Current Index after Empty Exception:0
    */
}
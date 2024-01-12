// Exercise 4: Stack Class (composition)
// In this exercise we will make a Stack class. For the data storage we can use the Array class.
// Deriving from Array is not a good idea because there is no relation between Array and Stack.
// The stack would then inherit indexed operations which should not be a functionality of a stack.
// But we can use the Array class as a data member as shown in Figure 4:
// • Add a new source and header file for the Stack class to your project.
// • Create a template class called Stack. It is not a derived class but it uses an Array as
//   data member. You also need a data member for the current index in the array.
// • Create the regular constructors, destructor and assignment operator.
// • Add a Push() function. It should store the element at the current position in the
// embedded array. Increment the current position afterwards. There is no need for checking the current index because the array will throw an exception when the stack is full. Make sure the current index is not changed when the Array class threw an exception.
// • Add a Pop() function that decrements the current position and then returns the element at that position. Make sure the current index is not changed when
// the Array class throws an exception.
// • Change the main function to test the stack.
// Using another class as data member is called composition.
// In this case the Stack class uses internally an Array class.
// Forwarding functionality to another class is called delegation.
// Here the Stack class delegates the storage of elements to the Array class.
#include "Array.cpp"
#include "NumericArray.cpp"
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
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Popped: Line from Point(1, 1) to Point(2, 2)
     * Line ID: 101027544
     * Popped: Circle: Centre at Point(1, 4), Radius 5
     * Circle ID: 1622650073
     * Popped: Point(1, 3)
     * Point ID: 16807
    */
}
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
}
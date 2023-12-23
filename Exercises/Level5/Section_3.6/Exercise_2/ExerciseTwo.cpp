#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "ArrayException.hpp"

using namespace std;
using francis::CAD::Shape;
using francis::CAD::Point;
using francis::CAD::Circle;
using namespace francis::Containers; // Access everything within Containers namespace
using francis::CAD::Line; // Single class
namespace FCAD = francis::CAD; // Alias for francis::CAD

int main() {
    // Use fully qualified class name with template parameter
    
    Array<int> arr;  // Assume Array has size 10

    try {
        std::cout << arr[10] << std::endl;  // This will cause an exception
    } catch (const ArrayException& e) {
        std::cerr << e.GetMessage() << std::endl;
    }

    return 0;
}


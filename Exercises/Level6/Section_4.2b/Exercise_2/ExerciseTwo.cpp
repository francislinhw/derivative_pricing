// Exercise 2: Numeric Array (generic inheritance)
// With templates it is possible to call functionality on the template argument.
// But when you do this, you limit the types you can use as the template argument because they have to support that functionality.
// Thus when adding numeric functionality to the Array class like calculating the sum,
// you would limit the types possible as the template argument to types that support numeric operations.
// It is better to leave the Array class as generic as possible so it can be used in various situations.
// Numeric functionality can then be put in a derived class which itself is also a template (generic inheritance) as shown in Figure 2.

#include "Array.cpp"
#include "NumericArray.cpp"
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
    try {
        // Create NumericArrays of double
        NumericArray<double> numArray1(5);
        NumericArray<int> numArray2(5);
        NumericArray<double> numArrayTest(6);

        // Initialize the arrays
        for (int i = 0; i < numArray1.Size(); ++i) {
            numArray1[i] = i * 1;  // Just some values for testing scale operator
            numArray2[i] = i * 2;  // Just some values for testing scale operator
        }

        for (int i = 0; i < numArrayTest.Size(); ++i) {
            numArrayTest[i] = i * 1;  // Just some values for testing scale operator
        }

        // Print the arrays
        std::cout << "Array 1: ";
        for (int i = 0; i < numArray1.Size(); ++i) {
            std::cout << numArray1[i] << ' ';
        }
        std::cout << std::endl;

        std::cout << "Array 2: ";
        for (int i = 0; i < numArray2.Size(); ++i) {
            std::cout << numArray2[i] << ' ';
        }
        std::cout << std::endl;

        // Test scaling
        numArray1 = numArray1 * 2.0; // Scale by 
        // Testing scale operator
        NumericArray<int> numArraySum = numArray2 + numArray2;
        std::cout << "Array 2 + Array 2: ";
        for (int i = 0; i < numArraySum.Size(); ++i) {
            std::cout << numArraySum[i] << ' ';
        }
        std::cout << std::endl;

        // Test dot product
        double dotProduct = numArray1.DotProduct(numArray1);

        std::cout << "Dot Product (Array 1 * Array 1): " << dotProduct << std::endl;

        double dotProductTest = numArray1.DotProduct(numArrayTest);

        std::cout << "Dot Product (Array 1 * Array 3): " << dotProduct << std::endl;

    } catch (const ArrayException& ex) {
        std::cout << ex.GetMessage() << std::endl;
    } catch (...) {
        std::cout << "An unknown error has occurred." << std::endl;
    }

    return 0;
    /* 
     * What assumptions do you make about the type used as template argument? 
     * Can you create a numeric array with Point objects?
     * 
     * Answer: When I create a NumericArray class as a derived class from a generic Array class,
     *         my specific assumptions about the type T used as the template to perform on the elements of the Numeric.
     *         I expect that the functions like scaling, addition of elements, and dot product calculation are supported by <T>
     *         However, Regarding creating a NumericArray with Point objects:
     * 
     *         In principle, I can instantiate a NumericArray with any type, including Point objects. 
     *         However, whether this is meaningful or not depends on the operations you intend to perform on the NumericArray.
     *         If I need an array of Point objects and want to use the additional functionalities,
     *         I had better create another class to ensure that these operations are meaningfully defined for Point objects.
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Array 1: 0 1 2 3 4 5 6 7 8 9 
     * Array 2: 0 2 4 6 8 10 12 14 16 18 
     * Array 2 + Array 2: 0 4 8 12 16 20 24 28 32 36 
     * Dot Product (Array 1 * Array 1): 1140
    */
}
#include "Array.hpp"
#include "NumericArray.hpp"
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

        // Initialize the arrays
        for (int i = 0; i < numArray1.Size(); ++i) {
            numArray1[i] = i * 1.1;  // Just some values for testing
            numArray2[i] = i * 2;  // Just some values for testing
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
        //Test addition
        NumericArray<int> numArraySum = numArray2 + numArray2;
        std::cout << "Array 2 + Array 2: ";
        for (int i = 0; i < numArraySum.Size(); ++i) {
            std::cout << numArraySum[i] << ' ';
        }
        std::cout << std::endl;

        // Test dot product
        double dotProduct = numArray1.DotProduct(numArray1);

        std::cout << "Dot Product (Array 1 * Array 1): " << dotProduct << std::endl;

    } catch (const ArrayException& ex) {
        std::cout << ex.GetMessage() << std::endl;
    } catch (...) {
        std::cout << "An unknown error has occurred." << std::endl;
    }

    return 0;
}
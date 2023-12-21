#include <iostream>
#include "Array.hpp"
#include "Point.hpp"

void CreateAndFillArray(Array& arr) {
    for (int i = 0; i < arr.Size(); ++i) {
        double x, y;
        std::cout << "Enter x and y for point " << i << ": ";
        std::cin >> x >> y;
        if (!std::cin) {
            std::cerr << "Invalid input. Exiting." << std::endl;
            return;
        }
        arr[i] = Point(x, y);
    }
}

void PrintArray(const Array& arr) {
    for (int i = 0; i < arr.Size(); ++i) {
        std::cout << "Point " << i << ": " << arr[i] << std::endl;
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the arrays: ";
    std::cin >> size;
    if (!std::cin || size < 1) {
        std::cerr << "Invalid size... Exiting." << std::endl;
        return 1;
    }

    Array arr(size);
    CreateAndFillArray(arr);
    PrintArray(arr);

    std::cout << "\nCreating a second array of the same size.\n";
    Array arr2(size);
    CreateAndFillArray(arr2);
    PrintArray(arr2);

    for (int i = 0; i < arr.Size(); ++i) {
        std::cout << i << " element of array is the same: " << ((arr[i] == arr2[i])? "Yes" : "No") << std::endl;
    }

    std::cout << "\nAssigning arr2 to arr and comparing elements.\n";
    arr = arr2;
    for (int i = 0; i < arr.Size(); ++i) {
        std::cout << i << " element of array is the same: " << ((arr[i] == arr2[i])? "Yes" : "No") << std::endl;
    }

    return 0;

/***
 * To make the array class complete, 
 * you should also add the following const version of the square bracket operator. 
 * Can you explain why you would need this?:
 * 
 * // const Point& operator [] (int index) const;
 * 
 * My Answer: The const can make the const function, obj to access the array
 * to garentee the data will not be modified.
 * 
 * // Sample Code
 * void PrintElement(const Array& arr, int index) {
 *  std::cout << arr[index] << std::endl;
 * }
 * 
 * Like the above code, it accepts const Array, if our Array does not offer const []
 * the compliler will not work correctly.
*/

}

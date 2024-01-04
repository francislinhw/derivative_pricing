// It is easy to forget to delete memory created with new.
// A good practice is to let a class manage memory.
// Then the client of that class does not have to manage memory and can’t forget to delete memory.
// So instead of creating a C array with new, you can use an array class that handle memory for you.
// • In the main program, test the Array class.
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
        std::cout << i << " element of array arr and arr1 are the same: " << ((arr[i] == arr2[i])? "Yes" : "No") << std::endl;
    }

    std::cout << "\nAssigning arr2 to arr and comparing elements.\n";
    arr = arr2;
    for (int i = 0; i < arr.Size(); ++i) {
        std::cout << i << " element of array arr and arr1 are the same: " << ((arr[i] == arr2[i])? "Yes" : "No") << std::endl;
    }

    return 0;

    /*
     * To make the array class complete, 
     * you should also add the following const version of the square bracket operator. 
     * Can you explain why you would need this?
     * 
     * // const Point& operator [] (int index) const;
     * 
     * Answer: The const can make the const function, obj to access the array
     * to garentee the data will not be modified.
     * 
     *      // Sample Code
     *      void PrintElement(const Array& arr, int index) {
     *       std::cout << arr[index] << std::endl;
     *      }
     * 
     * Like the above code, it accepts const Array, if our Array does not offer const []
     * the compliler will not work correctly.
     * 
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Enter the size of the arrays: 3
     * Enter x and y for point 0: 1 1
     * Enter x and y for point 1: 10 12
     * Enter x and y for point 2: 5 13
     * Point 0: Point(1, 1)
     * Point 1: Point(10, 12)
     * Point 2: Point(5, 13)
     * 
     * Creating a second array of the same size.
     * Enter x and y for point 0: 2 2
     * Enter x and y for point 1: 20 25
     * Enter x and y for point 2: 7 24
     * Point 0: Point(2, 2)
     * Point 1: Point(20, 25)
     * Point 2: Point(7, 24)
     * 0 element of array arr and arr1 are the same: No
     * 1 element of array arr and arr1 are the same: No
     * 2 element of array arr and arr1 are the same: No
     * 
     * Assigning arr2 to arr and comparing elements.
     * 0 element of array arr and arr1 are the same: Yes
     * 1 element of array arr and arr1 are the same: Yes
     * 2 element of array arr and arr1 are the same: Yes
     * 
    */
}

// Exercise 2: STL Iterators
// Using iterators you can iterate a STL container without knowing which container it is. In this exercise you create a function that calculates the sum of a container with doubles.
// • Create a template function called Sum() that accepts the template argument T as input and returns a double. The template argument will be a container.
// • In the implementation get an iterator (T::const_iterator) for the end. Then create a loop that iterates the container T and adds all values. Finally return the sum.
// • In the main program, call the Sum() function for the different container from the previous exercise.
// The Sum() function created calculates the sum of the complete container. Also create a Sum() function that calculates the sum between two iterators. The function then uses the template argument for the iterator type and accepts two iterators, the start and end iterator.

#include <iostream>
#include <list>
#include <vector>
#include <numeric> // For std::accumulate

// Template function to calculate the sum of elements in a container
// template <typename T>
// double Sum(const T& container) {
//     return std::accumulate(container.begin(), container.end(), 0.0);
// }

// Template function to calculate the sum between two iterators
template <typename Iter>
double Sum(Iter start, Iter end) {
    return std::accumulate(start, end, 0.0);
}

// Template function to calculate the sum of elements in a container
template <typename T>
double Sum(const T& container) {
    typename T::const_iterator it; // Iterator for container
    double sum = 0.0; // Initialize sum

    // Iterate through the container and add each element to sum
    for (it = container.begin(); it != container.end(); ++it) {
        sum += *it;
    }

    return sum;
}

int main() {
    // Using containers from the previous example
    std::list<double> my_list = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<double> my_vector = {6.6, 7.7, 8.8, 9.9, 10.1};

    // Call the Sum() function for the list
    double list_sum = Sum(my_list);
    std::cout << "Sum of list: " << list_sum << "\n";

    // Call the Sum() function for the vector
    double vector_sum = Sum(my_vector);
    std::cout << "Sum of vector: " << vector_sum << "\n";

    // Call the Sum() function with iterator arguments for a portion of the vector
    double partial_sum = Sum(my_vector.begin(), my_vector.begin() + 3);
    std::cout << "Sum of first three elements of vector: " << partial_sum << "\n";

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Sum of list: 16.5
     * Sum of vector: 43.1
     * Sum of first three elements of vector: 23.1
     *      
     *  
    */
}

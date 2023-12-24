#include <iostream>
#include <list>
#include <vector>
#include <numeric> // For std::accumulate

// Template function to calculate the sum of elements in a container
template <typename T>
double Sum(const T& container) {
    return std::accumulate(container.begin(), container.end(), 0.0);
}

// Template function to calculate the sum between two iterators
template <typename Iter>
double Sum(Iter start, Iter end) {
    return std::accumulate(start, end, 0.0);
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
}

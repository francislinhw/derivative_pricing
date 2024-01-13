// Exercise 3: STL Algorithms
// STL already contains many algorithms that work with containers.
// Use the count_if algorithm to count the number of elements smaller than a certain number.
// The count_if function accepts a functor.
// Thus pass it a global function that checks the double input is smaller than a certain value.
// Replace the global checking function, by a function object.
// This is a class that overload the round bracket operator that in this case has the same signature and functionality as the global function you created previously.
// Only in this case the value to check for should not be a ‘literal’ value, but taken from a data member that was set in the constructor of the function object.

#include <iostream>
#include <vector>
#include <algorithm>
#include "IsSmallerFunctor.hpp"

// Global function for comparison
bool isSmaller(double value, double threshold) {
    return value < threshold;
}

int main() {
    std::vector<double> data = {1.0, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};

    // Count using global function since that is not 'literal'
    double threshold = 5.0;
    auto count1 = std::count_if(data.begin(), data.end(), [threshold](double value) {
        return isSmaller(value, threshold);
    });
    std::cout << "Number of elements smaller than " << threshold << " (global function): " << count1 << std::endl;

    // Count using function object
    IsSmallerFunctor isSmallerObj(threshold);
    auto count2 = std::count_if(data.begin(), data.end(), isSmallerObj);
    std::cout << "Number of elements smaller than " << threshold << " (functor): " << count2 << std::endl;

    return 0;
    /*
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Number of elements smaller than 5 (global function): 4
     * Number of elements smaller than 5 (functor): 4
     * 
    */
}

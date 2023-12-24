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

    // Count using global function
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
}

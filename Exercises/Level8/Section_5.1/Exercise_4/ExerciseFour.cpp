#include <boost/random.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>
#include <map>
#include <ctime>

int main() {
    // Mersenne Twister random number generator
    boost::random::mt19937 myRng;

    // Set the seed based on the current time
    myRng.seed(static_cast<boost::uint32_t>(std::time(0)));

    // Uniform distribution in range [1,6]
    boost::random::uniform_int_distribution<int> six(1, 6);

    std::map<int, long> statistics; // Map to hold frequencies
    int trials;
    std::cout << "How many trials? ";
    std::cin >> trials;

    // Generate dice rolls
    for (int i = 0; i < trials; ++i) {
        int outcome = six(myRng);
        ++statistics[outcome];
        /**
         * Notes for ++statistics[outcome]:
         * In C++, the expression is used to increment the value associated with a key in a map. 
         * Accessing the Map Entry: statistics[outcome] accesses the map entry with the key outcome. 
         * If outcome is not already a key in the map, this operation automatically creates a new entry in the map.
         * The ++ operator then increments the value associated with this key.
         * In the context of this exercise, each time a particular outcome of the dice roll (like 1, 2, 3, 4, 5, or 6) occurs,
         * this operation increments the count of that outcome in the map statistics.
         * This way, we keep track of how many times each outcome has occurred during the simulation.
         * 
        */
    }

    // Calculate and display percentages
    for (int i = 1; i <= 6; ++i) {
        double percentage = (static_cast<double>(statistics[i]) / trials) * 100.0;
        std::cout << "Trial " << i << " has " << percentage << "% outcomes\n";
    }

    return 0;
/*
 * My Answer: 
 *
 * How many trials? 1000000
 * Trial 1 has 16.6653% outcomes
 * Trial 2 has 16.6663% outcomes
 * Trial 3 has 16.6646% outcomes
 * Trial 4 has 16.6689% outcomes
 * Trial 5 has 16.6663% outcomes
 * Trial 6 has 16.6657% outcomes
 * 
*/
}

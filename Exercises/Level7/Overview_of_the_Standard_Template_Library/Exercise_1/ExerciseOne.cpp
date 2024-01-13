// Exercise 1: STL Containers
// One of the features of STL are the containers. In this exercise you will practice with the different STL containers. In the main program:
// • Create a list of doubles and add some data. Use the front() and back() functions to access the first and last element.
// • Create a vector of doubles and add some data. Then use the index operator to access some elements. Also make the vector grow.
// • Create a map that maps strings to doubles. Fill the map and access elements using the square bracket operator.

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>

int main() {
    // Create a list of doubles
    std::list<double> my_list = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "First element in list: " << my_list.front() << "\n";
    std::cout << "Last element in list: " << my_list.back() << "\n";

    // Create a vector of doubles
    std::vector<double> my_vector = {6.6, 7.7, 8.8, 9.9, 10.1};
    my_vector.push_back(11.1); // Making the vector grow
    std::cout << "Element at index 2 in vector: " << my_vector[2] << "\n";
    std::cout << "Element at index 4 in vector: " << my_vector[4] << "\n";

    // Create a map from strings to doubles
    std::map<std::string, double> my_map;
    my_map["one"] = 1.11;
    my_map["two"] = 2.22;
    my_map["three"] = 3.33;
    std::cout << "Value associated with 'two' in map: " << my_map["two"] << "\n";

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * First element in list: 1.1
     * Last element in list: 5.5
     * Element at index 2 in vector: 8.8
     * Element at index 4 in vector: 10.1
     * Value associated with 'two' in map: 2.22
     * 
    */
}

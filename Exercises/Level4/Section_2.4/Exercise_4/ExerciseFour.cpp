// Exercise 4: Friends
// Normally, only member functions of a class can access the private members of that class.
// Global functions and other classes can’t access the private members of that class.
// You can make an exception on that rule by declaring certain functions or classes as friend.
// For example the << operator for sending the point or line to the std::ostream class had to be a global function and thus can’t access the private members.
// Move the << operator
// of Point and Line inside the class definition and declare it as friend. The function remains a global function but it can now access the data members directly without the need for calling the getters or ToString() function.
// Normally, friends are to be avoided because it violates the data hiding principle. But in case of global operator functions it makes sense because you would actually want to make those global operator functions as member function but this was not possible.
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    // Create Point objects
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);

    // Use the friend ostream << operator to output Point details
    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p2: " << p2 << std::endl;

    // Create a Line object using two Points
    Line line(p1, p2);

    // Use the friend ostream << operator to output Line details
    std::cout << "Line: " << line << std::endl;

    // Create a Circle object using Point and double
    Circle circle(p1, 2);

    // Use the friend ostream << operator to output circle details
    std::cout << "Circle: " << circle << std::endl;

    return 0;
}

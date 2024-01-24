// Exercise 2: Tuple
// Boost tuples can be used to store different kinds of data as one entity.
// It can be used if we need to combine data without the need to create a separate class.
// In this exercise, create a typedef for a Person tuple that contains a name, age and length.
// Also create a function that prints the person tuple. Use the get<T>() member functions the retrieve the data.
// Create a few person tuple instances and print them.
// Also increment the age of one of the persons. Note that to change a value of one of the tuple elements,
// you can also use the get<T>() function since it returns a reference to the value.
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
#include <iostream>

typedef boost::tuple<std::string, int, double> Person; // Name, Age, Length

void PrintPerson(const Person& p) {
    std::cout << "Name: " << p.get<0>() 
              << ", Age: " << p.get<1>() 
              << ", Length: " << p.get<2>() << std::endl;
}

int main() {
    Person person1("Alice", 30, 1.65);
    Person person2("Bob", 25, 1.80);
    Person person3("Charlie", 35, 1.75);

    PrintPerson(person1);
    PrintPerson(person2);
    PrintPerson(person3);

    // Increment the age of Alice
    person1.get<1>() += 1; 

    std::cout << "After incrementing Alice's age:" << std::endl;
    PrintPerson(person1);

    return 0;
    /*
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Name: Alice, Age: 30, Length: 1.65
     * Name: Bob, Age: 25, Length: 1.8
     * Name: Charlie, Age: 35, Length: 1.75
     * After incrementing Alice's age:
     * Name: Alice, Age: 31, Length: 1.65
    */
}

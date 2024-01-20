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

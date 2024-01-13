#include "VanillaPricingEngine.hpp"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>

VanillaPricingEngine::VanillaPricingEngine() : PricingEngine() {
    std::cout << "Vanilla Pricing Engine Built!" << std::endl;
} // Default constructor

VanillaPricingEngine::VanillaPricingEngine(const VanillaPricingEngine& source) : PricingEngine() {
    std::cout << "Vanilla Pricing Engine Built!" << std::endl;
}

VanillaPricingEngine& VanillaPricingEngine::operator=(const VanillaPricingEngine& source) {
    // Protect against self-assignment
    if (this == &source) {
        return *this;
    }
    PricingEngine::operator=(source); // Call base class assignment operator
    return *this;
}

std::ostream& operator<<(std::ostream& os, const VanillaPricingEngine& source) {
    os << source.ToString(); // Assuming Shape has a ToString member function.
    return os;
}

VanillaPricingEngine::~VanillaPricingEngine() {
    std::cout << "Vanilla Pricing Engine Ends!" << std::endl;
} // Destructor

std::string VanillaPricingEngine::ToString() const {
    return "Option";
}

void VanillaPricingEngine::Calculate() {

} // Pure virtual function makes Shape an abstract class

void VanillaPricingEngine::Print() const {

} // Template Method

double VanillaPricingEngine::delta() const {
    return 0.0;
}
double VanillaPricingEngine::deltaForward() const {
    return 0.0;
}
double VanillaPricingEngine::gamma() const {
    return 0.0;
}
double VanillaPricingEngine::theta() const {
    return 0.0;
}
double VanillaPricingEngine::thetaPerDay() const {
    return 0.0;
}
double VanillaPricingEngine::vega() const {
    return 0.0;
}
double VanillaPricingEngine::rho() const {
    return 0.0;
}
double VanillaPricingEngine::dividendRho() const {
    return 0.0;
}
double VanillaPricingEngine::strikeSensitivity() const {
    return 0.0;
}
double VanillaPricingEngine::itmCashProbability() const {
    return 0.0;
}
double VanillaPricingEngine::NPV() const {
    return 0.0;
} 

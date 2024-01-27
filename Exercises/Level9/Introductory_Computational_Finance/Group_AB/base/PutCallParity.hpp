// OptionParameters.hpp
#include <base/OptionParameters.hpp>
#include <cmath>
#ifndef PUT_CALL_PARITY_HPP
#define PUT_CALL_PARITY_HPP

// Function to calculate put price using put-call parity
double calculatePutPrice(const OptionParameters& params, double callPrice) {
    return callPrice + params.K * exp(-params.r * params.T) - params.S;
}

// Function to check if put-call parity is satisfied
bool isParitySatisfied(const OptionParameters& params, double callPrice, double putPrice) {
    double computedPutPrice = calculatePutPrice(params, callPrice);
    return std::abs(computedPutPrice - putPrice) < 1e-6;  // Allowing for some numerical tolerance
}

#endif // PUT_CALL_PARITY_HPP
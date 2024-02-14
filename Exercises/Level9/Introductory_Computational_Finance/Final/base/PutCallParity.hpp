// PutCallParity.hpp
#ifndef PUT_CALL_PARITY_HPP
#define PUT_CALL_PARITY_HPP

#include "base/OptionBasicParas.hpp"

// Function to calculate put price using put-call parity
inline double calculatePutPrice(const OptionParameters& params, double callPrice) {
    return callPrice + params.K * exp(-params.r * params.T) - params.S;
}

// Function to calculate put price using put-call parity
inline double calculateCallPrice(const OptionParameters& params, double putPrice) {
    return putPrice + params.S - params.K * exp(-params.r * params.T);
}
// Function to check if put-call parity is satisfied
inline bool isParitySatisfied(const OptionParameters& params, double callPrice, double putPrice) {
    double computedPutPrice = calculatePutPrice(params, callPrice);
    double computedCallPrice = calculateCallPrice(params, putPrice);
    // Allowing for some numerical tolerance
    return (std::abs(computedPutPrice - putPrice) < 1e-6) and 
    (std::abs(computedCallPrice - callPrice) < 1e-6);
}

#endif // PUT_CALL_PARITY_HPP
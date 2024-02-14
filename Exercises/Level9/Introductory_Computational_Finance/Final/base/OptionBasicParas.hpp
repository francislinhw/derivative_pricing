#ifndef OPTION_BASIC_PARAS_HPP
#define OPTION_BASIC_PARAS_HPP

#include "base/OptionType.hpp"

struct OptionParameters {
    double T;    // Time to maturity
    double K;    // Strike price
    double sig;  // Volatility
    double r;    // Risk-free interest rate
    double S;    // Underlying asset price
    double CostOfCarry;    // Underlying asset price
    OptionType Type;     // European / American

    // Default constructor
    OptionParameters() : S(0), K(0), T(0), sig(0), r(0), CostOfCarry(0), Type(EUROPEAN) {}

    OptionParameters(double S, double K, double T, double sig, double r, double b, OptionType Type)
        : S(S), K(K), T(T), sig(sig), r(r), CostOfCarry(b), Type(Type) {}
};

#endif
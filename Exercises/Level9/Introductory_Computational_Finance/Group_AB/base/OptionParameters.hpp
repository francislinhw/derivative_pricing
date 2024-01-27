// OptionParameters.hpp
#ifndef OPTION_PARAMETERS_HPP
#define OPTION_PARAMETERS_HPP

struct OptionParameters {
    double T;    // Time to maturity
    double K;    // Strike price
    double sig;  // Volatility
    double r;    // Risk-free interest rate
    double S;    // Underlying asset price
    double CostOfCarry;    // Underlying asset price
};

#endif // OPTION_PARAMETERS_HPP

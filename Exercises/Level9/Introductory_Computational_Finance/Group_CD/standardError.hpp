#ifndef STANDARD_ERROR_HPP
#define STANDARD_ERROR_HPP
#include <vector>
#include <cmath>
#include <numeric>
#include <iostream>

template <typename T>
double calculateStandardDeviation(const std::vector<T>& callPrices, double r, double T) {
    size_t M = callPrices.size();
    T mean = std::accumulate(callPrices.begin(), callPrices.end(), T(0)) / static_cast<T>(M);
    T sumOfSquares = std::accumulate(callPrices.begin(), callPrices.end(), T(0), 
                                     [mean](T accumulator, T value) {
                                         return accumulator + (value - mean) * (value - mean);
                                     });
    double variance = (sumOfSquares - (mean * mean * static_cast<T>(M))) / static_cast<T>(M - 1);
    return std::sqrt(variance) * std::exp(-r * T);
}

template <typename T>
double calculateStandardError(const std::vector<T>& callPrices, double r, double T) {
    double sd = calculateStandardDeviation(callPrices, r, T);
    size_t M = callPrices.size();
    return sd / std::sqrt(static_cast<T>(M));
}

/*
 * // Usage example in my Monte Carlo simulation loop:
 * std::vector<double> callPrices;
 * 
 * // Assume this vector is filled with simulated call prices
 * // After simulation loop
 * double r = 0.08; // Risk-free rate
 * double T = 1.0;  // Time to maturity
 * double sd = calculateStandardDeviation(callPrices, r, T);
 * double se = calculateStandardError(callPrices, r, T);
 * std::cout << "Standard Deviation: " << sd << std::endl;
 * std::cout << "Standard Error: " << se << std::endl;
 */

#endif
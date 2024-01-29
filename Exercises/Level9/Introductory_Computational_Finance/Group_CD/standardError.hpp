#ifndef STANDARD_ERROR_HPP
#define STANDARD_ERROR_HPP
#include <vector>
#include <cmath>
#include <numeric>

template <typename T>
double calculateStandardDeviation(const std::vector<T>& callPrices, double r, double timeToMaturity) {
    size_t M = callPrices.size();
    T mean = std::accumulate(callPrices.begin(), callPrices.end(), 0.0) / M;
    T sumOfSquares = std::accumulate(callPrices.begin(), callPrices.end(), 0.0, 
                                     [mean](T accumulator, T value) {
                                         return accumulator + (value - mean) * (value - mean);
                                     });
    double variance = (sumOfSquares - mean * mean * M) / (M - 1);
    return std::sqrt(variance) * std::exp(-r * timeToMaturity);
}

template <typename T>
double calculateStandardError(const std::vector<T>& callPrices, double r, double timeToMaturity) {
    double sd = calculateStandardDeviation(callPrices, r, timeToMaturity);
    size_t M = callPrices.size();
    return sd / std::sqrt(M);
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
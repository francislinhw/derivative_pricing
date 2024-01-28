#include "VanillaPricingEngine.hpp"
#include <cmath>
#include <boost/math/distributions/normal.hpp>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>

VanillaPricingEngine::VanillaPricingEngine() : PricingEngine() {
  // std::cout << "Vanilla Pricing Engine Built!" << std::endl;
} // Default constructor

VanillaPricingEngine::VanillaPricingEngine(const VanillaPricingEngine& source) : PricingEngine() {
  //  std::cout << "Vanilla Pricing Engine Built!" << std::endl;
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
  // std::cout << "Vanilla Pricing Engine Ends!" << std::endl;
} // Destructor

std::string VanillaPricingEngine::ToString() const {
    return "Option";
}

void VanillaPricingEngine::Calculate() {

} // Pure virtual function makes Shape an abstract class

void VanillaPricingEngine::Print() const {

} // Template Method

double VanillaPricingEngine::delta() const {
    boost::math::normal_distribution<> nd;
    if (isCall) {
        double d1 = (log(underlyingPrice / strike) + (costOfCarry + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        return exp((costOfCarry-interest) * timeToMaturity) * cdf(nd, d1);
    } else if (!isCall) {
        double d1 = (log(underlyingPrice / strike) + (costOfCarry + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        return exp((costOfCarry-interest) * timeToMaturity) * (cdf(nd, d1) - 1);
    return 0;
    }
}

double VanillaPricingEngine::numericalDelta() {
    // Store the original underlying price
    double originalUnderlyingPrice = underlyingPrice;
    
    // Calculate the NPV with a decreased underlying price
    VanillaPricingEngine::UnderlyingPrice(originalUnderlyingPrice - numericalGreeksBump);
    double v0 = NPV();
    
    // Calculate the NPV with an increased underlying price
    VanillaPricingEngine::UnderlyingPrice(originalUnderlyingPrice + numericalGreeksBump);
    double v1 = NPV();
    
    // Reset the underlying price to the original value
    VanillaPricingEngine::UnderlyingPrice(originalUnderlyingPrice);
    
    // Calculate the numerical delta using the central difference method
    return (v1 - v0) / (2 * numericalGreeksBump);
}
double VanillaPricingEngine::deltaForward() const {
    return 0.0;
}

double VanillaPricingEngine::gamma() const {
    boost::math::normal_distribution<> nd;
    double d1 = (log(underlyingPrice / strike) + (interest + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
    return pdf(nd, d1) * exp((costOfCarry-interest) * timeToMaturity) / (underlyingPrice * volatility * sqrt(timeToMaturity));
}

double VanillaPricingEngine::numericalGamma() {
    // Store the original underlying price
    double originalUnderlyingPrice = underlyingPrice;
    
    // Calculate the NPV with an increased underlying price
    VanillaPricingEngine::UnderlyingPrice(originalUnderlyingPrice + numericalGreeksBump);
    double v_plus_h = NPV();
    
    // Calculate the NPV at the original underlying price
    VanillaPricingEngine::UnderlyingPrice(originalUnderlyingPrice);
    double v = NPV();
    
    // Calculate the NPV with a decreased underlying price
    VanillaPricingEngine::UnderlyingPrice(originalUnderlyingPrice - numericalGreeksBump);
    double v_minus_h = NPV();
    
    // Reset the underlying price to the original value
    VanillaPricingEngine::UnderlyingPrice(originalUnderlyingPrice);
    
    // Calculate the numerical gamma using the central difference method
    return (v_plus_h - 2*v + v_minus_h) / (numericalGreeksBump * numericalGreeksBump);
}

double VanillaPricingEngine::theta() const {
    if (isCall) {
        boost::math::normal_distribution<> nd;
        double d1 = (log(underlyingPrice / strike) + (interest + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        double d2 = d1 - volatility * sqrt(timeToMaturity);
        return -underlyingPrice * pdf(nd, d1) * volatility * exp((costOfCarry-interest) * timeToMaturity) / (2 * sqrt(timeToMaturity)) - 
               costOfCarry * underlyingPrice * cdf(nd, d1) * exp((costOfCarry-interest) * timeToMaturity) - 
               interest * strike * exp(-interest * timeToMaturity) * cdf(nd, d2);
    } else if (!isCall) {
        boost::math::normal_distribution<> nd;
        double d1 = (log(underlyingPrice / strike) + (interest + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        double d2 = d1 - volatility * sqrt(timeToMaturity);
        return -underlyingPrice * pdf(nd, d1) * volatility * exp((costOfCarry-interest) * timeToMaturity) / (2 * sqrt(timeToMaturity)) + 
               costOfCarry * underlyingPrice * cdf(nd, -d1) * exp((costOfCarry-interest) * timeToMaturity) + 
               interest * strike * exp(-interest * timeToMaturity) * cdf(nd, -d2);
    }
    return 0;
}

double VanillaPricingEngine::thetaPerDay() const {
    return 0.0;
}

double VanillaPricingEngine::vega() const {
    boost::math::normal_distribution<> nd;
    if (isCall) {
        double d1 = (log(underlyingPrice / strike) + (interest + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        return underlyingPrice * sqrt(timeToMaturity) * pdf(nd, d1) * exp((costOfCarry-interest) * timeToMaturity);
    } else if (!isCall) {
        double d1 = (log(underlyingPrice / strike) + (interest + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        double d2 = d1 - volatility * sqrt(timeToMaturity);
        return -underlyingPrice * pdf(nd, d1) * volatility * exp((costOfCarry-interest) * timeToMaturity) / (2 * sqrt(timeToMaturity)) + 
               costOfCarry * underlyingPrice * cdf(nd, -d1) * exp((costOfCarry-interest) * timeToMaturity) + 
               interest * strike * exp(-interest * timeToMaturity) * cdf(nd, -d2);
    }
    return 0;
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
    if (isCall) {
        boost::math::normal_distribution<> nd;
        double d1 = (log(underlyingPrice / strike) + (interest + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        double d2 = d1 - volatility * sqrt(timeToMaturity);
        return underlyingPrice * cdf(nd, d1) - strike * exp(-interest * timeToMaturity) * cdf(nd, d2);
    } else if (!isCall) {
        boost::math::normal_distribution<> nd;
        double d1 = (log(underlyingPrice / strike) + (interest + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        double d2 = d1 - volatility * sqrt(timeToMaturity);
        return strike * exp(-interest * timeToMaturity) * cdf(nd, -d2) - underlyingPrice * cdf(nd, -d1);
    }
    return 0;
}

VanillaPricingEngine::VanillaPricingEngine(double underlyingPrice,
                                           double strike,
                                           double timeToMarity,
                                           double volatility,
                                           double interest,
                                           double costOfCarry,
                                           bool isCall) {
    underlyingPrice = underlyingPrice;
    strike = strike;
    timeToMaturity = timeToMarity;
    volatility = volatility;
    interest = interest;
    costOfCarry = costOfCarry;
    isCall = isCall;
}

void VanillaPricingEngine::UnderlyingPrice(double underlyingPrice) {
    this->underlyingPrice = underlyingPrice;
}
void VanillaPricingEngine::Strike(double strike) {
    this->strike = strike;
}
void VanillaPricingEngine::TimeToMaturity(double timeToMaturity) {
    this->timeToMaturity = timeToMaturity;
}
void VanillaPricingEngine::Volatility(double volatility) {
    this->volatility = volatility;
}
void VanillaPricingEngine::Interest(double interest) {
    this->interest = interest;
}
void VanillaPricingEngine::CostOfCarry(double costOfCarry) {
    this->costOfCarry = costOfCarry;
}
void VanillaPricingEngine::Flavor(bool flavor) {
    this->isCall = flavor;
}
double VanillaPricingEngine::NumericalGreeksBump() {
    return numericalGreeksBump;
}
void VanillaPricingEngine::NumericalGreeksBump(double numericalGreeksBump) {
    this->numericalGreeksBump = numericalGreeksBump;
}
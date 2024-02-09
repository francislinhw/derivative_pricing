#include <AnalyticPricingEngine.hpp>
#include <cmath>
#include <boost/math/distributions/normal.hpp>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>

AnalyticPricingEngine::AnalyticPricingEngine() : PricingEngine() {
  // std::cout << "Vanilla Pricing Engine Built!" << std::endl;
} // Default constructor

AnalyticPricingEngine::AnalyticPricingEngine(const AnalyticPricingEngine& source) : PricingEngine() {
  //  std::cout << "Vanilla Pricing Engine Built!" << std::endl;
}

AnalyticPricingEngine& AnalyticPricingEngine::operator=(const AnalyticPricingEngine& source) {
    // Protect against self-assignment
    if (this == &source) {
        return *this;
    }
    PricingEngine::operator=(source); // Call base class assignment operator
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AnalyticPricingEngine& source) {
    os << source.ToString(); // Assuming Shape has a ToString member function.
    return os;
}

AnalyticPricingEngine::~AnalyticPricingEngine() {
  // std::cout << "Vanilla Pricing Engine Ends!" << std::endl;
} // Destructor

std::string AnalyticPricingEngine::ToString() const {
    return "Option";
}

void AnalyticPricingEngine::Calculate() {

} // Pure virtual function makes Shape an abstract class

void AnalyticPricingEngine::Print() const {

} // Template Method

double AnalyticPricingEngine::delta() const {
    boost::math::normal_distribution<> nd;
    if (isCall) {
        double d1 = (log(underlyingPrice / strike) + (costOfCarry + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        return exp((costOfCarry-interest) * timeToMaturity) * cdf(nd, d1);
    } else if (!isCall) {
        double d1 = (log(underlyingPrice / strike) + (costOfCarry + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
        return exp((costOfCarry-interest) * timeToMaturity) * (cdf(nd, d1) - 1);
    }
    return 0;
}

double AnalyticPricingEngine::numericalDelta() {
    // Store the original underlying price
    double originalUnderlyingPrice = underlyingPrice;
    
    // Calculate the NPV with a decreased underlying price
    AnalyticPricingEngine::UnderlyingPrice(originalUnderlyingPrice - numericalGreeksBump);
    double v0 = NPV();
    
    // Calculate the NPV with an increased underlying price
    AnalyticPricingEngine::UnderlyingPrice(originalUnderlyingPrice + numericalGreeksBump);
    double v1 = NPV();
    
    // Reset the underlying price to the original value
    AnalyticPricingEngine::UnderlyingPrice(originalUnderlyingPrice);
    
    // Calculate the numerical delta using the central difference method
    return (v1 - v0) / (2 * numericalGreeksBump);
}
double AnalyticPricingEngine::deltaForward() const {
    return 0.0;
}

double AnalyticPricingEngine::gamma() const {
    boost::math::normal_distribution<> nd;
    double d1 = (log(underlyingPrice / strike) + (interest + volatility * volatility * 0.5) * timeToMaturity) / (volatility * sqrt(timeToMaturity));
    return pdf(nd, d1) * exp((costOfCarry-interest) * timeToMaturity) / (underlyingPrice * volatility * sqrt(timeToMaturity));
}

double AnalyticPricingEngine::numericalGamma() {
    // Store the original underlying price
    double originalUnderlyingPrice = underlyingPrice;
    
    // Calculate the NPV with an increased underlying price
    AnalyticPricingEngine::UnderlyingPrice(originalUnderlyingPrice + numericalGreeksBump);
    double v_plus_h = NPV();
    
    // Calculate the NPV at the original underlying price
    AnalyticPricingEngine::UnderlyingPrice(originalUnderlyingPrice);
    double v = NPV();
    
    // Calculate the NPV with a decreased underlying price
    AnalyticPricingEngine::UnderlyingPrice(originalUnderlyingPrice - numericalGreeksBump);
    double v_minus_h = NPV();
    
    // Reset the underlying price to the original value
    AnalyticPricingEngine::UnderlyingPrice(originalUnderlyingPrice);
    
    // Calculate the numerical gamma using the central difference method
    return (v_plus_h - 2*v + v_minus_h) / (numericalGreeksBump * numericalGreeksBump);
}

double AnalyticPricingEngine::theta() const {
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

double AnalyticPricingEngine::thetaPerDay() const {
    return 0.0;
}

double AnalyticPricingEngine::vega() const {
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

double AnalyticPricingEngine::rho() const {
    return 0.0;
}

double AnalyticPricingEngine::dividendRho() const {
    return 0.0;
}

double AnalyticPricingEngine::strikeSensitivity() const {
    return 0.0;
}

double AnalyticPricingEngine::itmCashProbability() const {
    return 0.0;
}

double AnalyticPricingEngine::NPV() const {
    if (type == EUROPEAN) {
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
    } else if (type == AMERICAN) {
        if (isCall) {
            // B-a) Program the above formulae, and incorporate into your well-designed options pricing classes.
            if (std::isinf(timeToMaturity) && timeToMaturity > 0) {
                double y1;
                double sigma_squared = volatility * volatility;
                double discriminant = sqrt((costOfCarry/sigma_squared - 0.5) * (costOfCarry/sigma_squared - 0.5) + 2 * interest / sigma_squared);
                y1 = 0.5 - (costOfCarry/sigma_squared) + discriminant;
                return (strike / (y1 - 1)) * pow(((y1 - 1) / y1) * (underlyingPrice / strike), y1);
            } else {
                throw std::logic_error("NO ANALYTIC SOLUTION ERROR!");
            }
        } else if (!isCall) {
            if (std::isinf(timeToMaturity) && timeToMaturity > 0) {
                double y2;
                double sigma_squared = volatility * volatility;
                double discriminant = sqrt((costOfCarry/sigma_squared - 0.5) * (costOfCarry/sigma_squared - 0.5) + 2 * interest / sigma_squared);
                y2 = 0.5 - (costOfCarry/sigma_squared) - discriminant;
                return (strike / (1 - y2)) * pow(((y2 - 1) / y2) * (underlyingPrice / strike), y2);
            } else {
                throw std::logic_error("NO ANALYTIC SOLUTION ERROR!");
            }
        }
    }
    return 0;
}

AnalyticPricingEngine::AnalyticPricingEngine(double underlyingPrice,
                                           double strike,
                                           double timeToMarity,
                                           double volatility,
                                           double interest,
                                           double costOfCarry,
                                           bool isCall,
                                           OptionType type) {
    underlyingPrice = underlyingPrice;
    strike = strike;
    timeToMaturity = timeToMarity;
    volatility = volatility;
    interest = interest;
    costOfCarry = costOfCarry;
    isCall = isCall;
    type = type;
}

void AnalyticPricingEngine::UnderlyingPrice(double underlyingPrice) {
    this->underlyingPrice = underlyingPrice;
}
void AnalyticPricingEngine::Strike(double strike) {
    this->strike = strike;
}
void AnalyticPricingEngine::TimeToMaturity(double timeToMaturity) {
    this->timeToMaturity = timeToMaturity;
}
void AnalyticPricingEngine::Volatility(double volatility) {
    this->volatility = volatility;
}
void AnalyticPricingEngine::Interest(double interest) {
    this->interest = interest;
}
void AnalyticPricingEngine::CostOfCarry(double costOfCarry) {
    this->costOfCarry = costOfCarry;
}
void AnalyticPricingEngine::Flavor(bool flavor) {
    this->isCall = flavor;
}
void AnalyticPricingEngine::Type(OptionType type) {
    this->type = type;
}
double AnalyticPricingEngine::NumericalGreeksBump() const {
    return numericalGreeksBump;
}
void AnalyticPricingEngine::NumericalGreeksBump(double numericalGreeksBump) {
    this->numericalGreeksBump = numericalGreeksBump;
}
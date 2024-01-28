
#ifndef PERPETUAL_AMERICAN_OPTION_HPP
#define PERPETUAL_AMERICAN_OPTION_HPP
#include "PricingEngine.hpp"
#include "VanillaPricingEngine.hpp"
#include <iostream>
#include <memory>
#include <cmath>

// Define the VanillaOption class
class PerpetualAemricanOption {
public:
    
    static std::unique_ptr<PricingEngine> engine;
    
    double underlyingPrice;
    double strike;
    double timeToMaturity;
    double volatility;
    double interest;
    double costOfCarry;
    bool isCall;

    PerpetualAemricanOption(double underlyingPrice,
                            double strike,
                            double timeToMarity,
                            double volatility,
                            double interest,
                            double costOfCarry,
                            bool isCall);

    ~PerpetualAemricanOption();
    void UnderlyingPrice(double underlyingPrice);
    void Strike(double strike);
    void TimeToMaturity(double timeToMaturity);
    void Volatility(double volatility);
    void Interest(double interest);
    void CostOfCarry(double costOfCarry);
    void Flavor(bool flavor);

    double UnderlyingPrice();
    double Strike();
    double TimeToMaturity();
    double Volatility();
    double Interest();
    double CostOfCarry();
    bool Flavor();

    double delta() const;
    double numericalDelta();
    double deltaForward() const;
    double gamma() const;
    double numericalGamma();
    double theta() const;
    double thetaPerDay() const;
    double vega() const;
    double rho() const;
    double dividendRho() const;
    double strikeSensitivity() const;
    double itmCashProbability() const;
    double NPV() const;

    void setPricingEngine(std::unique_ptr<PricingEngine> newEngine);
    void setPricingEngine(VanillaPricingEngine& engine);
};

#endif
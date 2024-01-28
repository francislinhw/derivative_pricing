
#ifndef VANILLA_OPTION_HPP
#define VANILLA_OPTION_HPP
#include <PricingEngine.hpp>
#include <base/OptionType.hpp>
#include <AnalyticPricingEngine.hpp>
#include <iostream>
#include <memory>
#include <cmath>

// Define the VanillaOption class
class VanillaOption {
public:
    
    static std::unique_ptr<PricingEngine> engine;
    
    double underlyingPrice;
    double strike;
    double timeToMaturity;
    double volatility;
    double interest;
    double costOfCarry;
    bool isCall;
    OptionType type;

    VanillaOption(double underlyingPrice,
                  double strike,
                  double timeToMarity,
                  double volatility,
                  double interest,
                  double costOfCarry,
                  bool isCall,
                  OptionType type);

    ~VanillaOption();
    void UnderlyingPrice(double underlyingPrice);
    void Strike(double strike);
    void TimeToMaturity(double timeToMaturity);
    void Volatility(double volatility);
    void Interest(double interest);
    void CostOfCarry(double costOfCarry);
    void Flavor(bool flavor);
    void Type(OptionType type);

    double UnderlyingPrice();
    double Strike();
    double TimeToMaturity();
    double Volatility();
    double Interest();
    double CostOfCarry();
    bool Flavor();
    OptionType Type();

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
    void setPricingEngine(AnalyticPricingEngine& engine);
};

#endif
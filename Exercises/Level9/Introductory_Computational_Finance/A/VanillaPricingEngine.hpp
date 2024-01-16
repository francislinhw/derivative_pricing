#ifndef VANILLA_PRICING_ENGINE_HPP
#define VANILLA_PRICING_ENGINE_HPP
#include "PricingEngine.hpp"
#include <string>
#include <stdlib.h>
#include <ctime>


class VanillaPricingEngine : public PricingEngine {
    private:

        double underlyingPrice;
        double strike;
        double timeToMaturity;
        double volatility;
        double interest;
        double costOfCarry;
        bool isCall;

    public:
        VanillaPricingEngine(); // Default constructor

        VanillaPricingEngine(const VanillaPricingEngine& source);

        VanillaPricingEngine& operator=(const VanillaPricingEngine& source);

        friend std::ostream& operator<<(std::ostream& os, const VanillaPricingEngine& source);

        ~VanillaPricingEngine(); // Destructor

        std::string ToString() const;


        VanillaPricingEngine(double underlyingPrice,
                             double strike,
                             double timeToMarity,
                             double volatility,
                             double interest,
                             double costOfCarry,
                             bool isCall);

        void UnderlyingPrice(double underlyingPrice);
        void Strike(double strike);
        void TimeToMaturity(double timeToMaturity);
        void Volatility(double volatility);
        void Interest(double interest);
        void CostOfCarry(double costOfCarry);
        void Flavor(bool flavor);

        void Calculate(); // Pure virtual function makes Shape an abstract class

        void Print() const; // Template Method

        double delta() const;
        double deltaForward() const;
        double gamma() const;
        double theta() const;
        double thetaPerDay() const;
        double vega() const;
        double rho() const;
        double dividendRho() const;
        double strikeSensitivity() const;
        double itmCashProbability() const;
        double NPV() const;
};

#endif
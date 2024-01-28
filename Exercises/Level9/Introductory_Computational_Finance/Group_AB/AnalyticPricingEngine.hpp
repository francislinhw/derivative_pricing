#ifndef ANALYTIC_PRICING_ENGINE_HPP
#define ANALYTIC_PRICING_ENGINE_HPP
#include "PricingEngine.hpp"
#include <string>
#include <stdlib.h>
#include <ctime>


class AnalyticPricingEngine : public PricingEngine {
    private:

        double underlyingPrice;
        double strike;
        double timeToMaturity;
        double volatility;
        double interest;
        double costOfCarry;
        bool isCall;
        double numericalGreeksBump = 0.00001; // h for numerical greeks

    public:
        AnalyticPricingEngine(); // Default constructor

        AnalyticPricingEngine(const AnalyticPricingEngine& source);

        AnalyticPricingEngine& operator=(const AnalyticPricingEngine& source);

        friend std::ostream& operator<<(std::ostream& os, const AnalyticPricingEngine& source);

        ~AnalyticPricingEngine(); // Destructor

        std::string ToString() const;


        AnalyticPricingEngine(double underlyingPrice,
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
        double NumericalGreeksBump();
        void NumericalGreeksBump(double numericalGreeksBump);

        void Calculate(); // Pure virtual function makes Shape an abstract class

        void Print() const; // Template Method

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
};

#endif
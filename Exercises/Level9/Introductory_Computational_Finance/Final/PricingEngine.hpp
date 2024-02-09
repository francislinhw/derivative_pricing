#ifndef PRICING_ENGINE_HPP
#define PRICING_ENGINE_HPP
#include <string>
#include <base/OptionType.hpp>
#include <stdlib.h>
#include <iostream>


class PricingEngine {

    public:
        PricingEngine(){
          //  std::cout << "Pricing Engine Built" << std::endl;
        }

        virtual ~PricingEngine() = default;

        virtual double delta() const = 0;
        virtual double numericalDelta() = 0;
        virtual double deltaForward() const = 0;
        virtual double gamma() const = 0;
        virtual double numericalGamma() = 0;
        virtual double theta() const = 0;
        virtual double thetaPerDay() const = 0;
        virtual double vega() const = 0;
        virtual double rho() const = 0;
        virtual double dividendRho() const = 0;
        virtual double strikeSensitivity() const = 0;
        virtual double itmCashProbability() const = 0;
        virtual double NPV() const = 0;
        virtual double NumericalGreeksBump() const = 0;
        virtual void NumericalGreeksBump(double numericalGreeksBump) = 0;

        virtual void UnderlyingPrice(double underlyingPrice) = 0;
        virtual void Strike(double strike) = 0;
        virtual void TimeToMaturity(double timeToMaturity) = 0;
        virtual void Volatility(double volatility) = 0;
        virtual void Interest(double interest) = 0;
        virtual void CostOfCarry(double costOfCarry) = 0;
        virtual void Flavor(bool isCall) = 0;
        virtual void Type(OptionType type) = 0;
};

#endif // SHAPE_HPP
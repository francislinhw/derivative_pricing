#ifndef VANILLA_PRICING_ENGINE_HPP
#define VANILLA_PRICING_ENGINE_HPP
#include "PricingEngine.hpp"
#include <string>
#include <stdlib.h>
#include <ctime>


class VanillaPricingEngine : public PricingEngine {
    public:
        VanillaPricingEngine(); // Default constructor

        VanillaPricingEngine(const VanillaPricingEngine& source);

        VanillaPricingEngine& operator=(const VanillaPricingEngine& source);

        friend std::ostream& operator<<(std::ostream& os, const VanillaPricingEngine& source);

        ~VanillaPricingEngine(); // Destructor

        std::string ToString() const;

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
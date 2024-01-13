#ifndef PRICING_ENGINE_HPP
#define PRICING_ENGINE_HPP
#include <string>
#include <stdlib.h>
#include <iostream>


class PricingEngine {

    public:
        PricingEngine(){
            std::cout << "Pricing Engine Built" << std::endl;
        }

        ~PricingEngine() {
            std::cout << "Pricing Engine Ends" << std::endl;
        }

        double delta() const {
            return 0.0;
        }
        double deltaForward() const {
            return 0.0;
        }
        double gamma() const {
            return 0.0;
        }
        double theta() const {
            return 0.0;
        }
        double thetaPerDay() const {
            return 0.0;
        }
        double vega() const {
            return 0.0;
        }
        double rho() const {
            return 0.0;
        }
        double dividendRho() const {
            return 0.0;
        }
        double strikeSensitivity() const {
            return 0.0;
        }
        double itmCashProbability() const {
            return 0.0;
        }
        double NPV() const {
            return 0.0;
        }
};

#endif // SHAPE_HPP
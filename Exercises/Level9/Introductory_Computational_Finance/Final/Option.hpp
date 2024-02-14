#ifndef OPTION_HPP
#define OPTION_HPP

#include "PricingEngine.hpp"
#include "base/OptionType.hpp"

#include <string>
#include <stdlib.h>
#include <iostream>
#include <memory>


class Option {

    public:
        Option(){
          //  std::cout << "Pricing Engine Built" << std::endl;
        }

        virtual ~Option() = default;

        // Option Basic Parameters
        virtual double UnderlyingPrice() const = 0;
        virtual double Strike() const = 0;
        virtual double TimeToMaturity() const = 0;
        virtual double Volatility() const = 0;
        virtual double Interest() const = 0;
        virtual double CostOfCarry() const = 0;
        virtual bool Flavor() const = 0;
        virtual OptionType Type() const = 0;

        virtual double delta() const = 0;
        virtual double numericalDelta() = 0;
        virtual double gamma() const = 0;
        virtual double numericalGamma() = 0;
        virtual double NPV() const = 0;

        virtual void setPricingEngine(std::unique_ptr<PricingEngine> newEngine) = 0;
};

#endif // OPTION_HPP
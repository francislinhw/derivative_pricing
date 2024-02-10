#ifndef OPTION_HPP
#define OPTION_HPP
#include <string>
#include "PricingEngine.hpp"
#include "base/OptionType.hpp"
#include <stdlib.h>
#include <iostream>


class Option {

    public:
        Option(){
          //  std::cout << "Pricing Engine Built" << std::endl;
        }

        virtual ~Option() = default;

        virtual double delta() const = 0;
        virtual double numericalDelta() = 0;
        virtual double gamma() const = 0;
        virtual double numericalGamma() = 0;
        virtual double NPV() const = 0;

        virtual void setPricingEngine(std::unique_ptr<PricingEngine> newEngine) = 0;
};

#endif // OPTION_HPP
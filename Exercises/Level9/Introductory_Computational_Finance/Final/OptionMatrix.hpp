#ifndef OPTION_MATRIX_HPP
#define OPTION_MATRIX_HPP
#include <string>
#include <stdlib.h>
#include <iostream>
#include "base/OptionParameters.hpp"
#include "PricingEngine.hpp"
#include "base/OptionType.hpp"
#include "AnalyticPricingEngine.hpp"



class OptionMatrix {

    public:
        OptionMatrix(){
          //  std::cout << "Option Matrix" << std::endl;
        }

        virtual ~OptionMatrix() = default;

        virtual void setPricingEngine(std::unique_ptr<PricingEngine> newEngine) = 0;
};

#endif // OPTION_MATRIX_HPP
#ifndef OPTION_MATRIX_HPP
#define OPTION_MATRIX_HPP
#include <string>
#include <base/OptionParameters.hpp>
#include <PricingEngine.hpp>
#include <base/OptionType.hpp>
#include <stdlib.h>
#include <iostream>


class OptionMatrix {
    private:

      std::vector<std::vector<OptionParameters>> matrix;

    public:
        OptionMatrix(){
          //  std::cout << "Option Matrix" << std::endl;
        }

        virtual ~OptionMatrix() = default;

        double delta() const;
        double numericalDelta();
        double gamma() const;
        double numericalGamma();
        double NPV() const;
        void matrixPricer();

      
        virtual void setPricingEngine(std::unique_ptr<PricingEngine> newEngine) = 0;
};

#endif // OPTION_MATRIX_HPP
#include "VanillaOption.hpp"
#include "VanillaPricingEngine.hpp"
#include <iostream>
#include <memory>

int main() {
    double underlyingPrice = 60;
    double strike = 65;
    double timeToMaturity = 0.25;
    double volatility = 0.30;
    double interest = 0.08;
    double costOfCarry = 0;
    bool isCall = true;

    VanillaOption vanillaCallOption(underlyingPrice, strike, timeToMaturity, volatility, interest, costOfCarry, isCall);
    VanillaOption vanillaPutOption(underlyingPrice, strike, timeToMaturity, volatility, interest, costOfCarry, !isCall);

    std::unique_ptr<VanillaPricingEngine> callPricingEngine = std::make_unique<VanillaPricingEngine>();
    std::unique_ptr<VanillaPricingEngine> putPricingEngine = std::make_unique<VanillaPricingEngine>();

    vanillaCallOption.setPricingEngine(std::move(callPricingEngine));
    vanillaPutOption.setPricingEngine(std::move(putPricingEngine));

    std::cout << "Call Option Price: " << vanillaCallOption.NPV() << std::endl;
    std::cout << "Put Option Price: " << vanillaPutOption.NPV() << std::endl;

    return 0;
}
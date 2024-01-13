#include "PricingEngine.hpp"
#include "VanillaPricingEngine.hpp"
#include "VanillaOption.hpp"
#include <iostream>

int main() {

    double underlyingPrice = 60;
    double strike = 65;
    double timeToMarity = 0.25;
    double volatility = 0.30;
    double interest = 0.08;
    double costOfCarry = 0;
    bool isCall = true;

    // Create a vanilla option
    VanillaOption vanillaOption(underlyingPrice,
                                strike,
                                timeToMarity,
                                volatility,
                                interest,
                                costOfCarry,
                                isCall); // A call option with strike=100 and expiry=1 year

    // Create a pricing engine
    VanillaPricingEngine engine;

    vanillaOption.setPricingEngine(engine);

    // Calculate and Print the MV and Greeks
    std::cout << "Option Price: " << vanillaOption.NPV() << std::endl;
    std::cout << "Option Price: " << engine.NPV() << std::endl;



    return 0;
}
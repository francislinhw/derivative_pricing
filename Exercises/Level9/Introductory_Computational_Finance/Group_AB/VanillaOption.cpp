#include "PricingEngine.hpp"
#include "VanillaOption.hpp"
#include <iostream>
#include <cmath>
#include <AnalyticPricingEngine.hpp>

// Define the VanillaOption class
VanillaOption::VanillaOption(double underlyingPrice,
                             double strike,
                             double timeToMarity,
                             double volatility,
                             double interest,
                             double costOfCarry,
                             bool isCall,
                             OptionType optionType) :
    Option(),
    underlyingPrice(underlyingPrice),
    strike(strike),
    timeToMaturity(timeToMarity),
    volatility(volatility),
    interest(interest),
    costOfCarry(costOfCarry),
    isCall(isCall),
    type(optionType)  {}

VanillaOption::~VanillaOption() {
    // std::cout << "Option Deleted!" << std::endl;
}

void VanillaOption::UnderlyingPrice(double underlyingPrice) {
    VanillaOption::underlyingPrice = underlyingPrice;
}
void VanillaOption::Strike(double strike) {
    VanillaOption::strike = strike;
}
void VanillaOption::TimeToMaturity(double timeToMaturity) {
    VanillaOption::timeToMaturity = timeToMaturity;
}
void VanillaOption::Volatility(double volatility) {
    VanillaOption::volatility = volatility;
}
void VanillaOption::Interest(double interest) {
    VanillaOption::interest = interest;
}
void VanillaOption::CostOfCarry(double costOfCarry) {
    VanillaOption::costOfCarry = costOfCarry;
}
void VanillaOption::Flavor(bool flavor) {
    VanillaOption::isCall = flavor;
}

void VanillaOption::Type(OptionType type) {
    VanillaOption::type = type;
}

double VanillaOption::UnderlyingPrice() {
    return underlyingPrice;
}
double VanillaOption::Strike() {
    return strike;
}
double VanillaOption::TimeToMaturity() {
    return timeToMaturity;
}
double VanillaOption::Volatility() {
    return volatility;
}
double VanillaOption::Interest() {
    return interest;
}
double VanillaOption::CostOfCarry() {
    return costOfCarry;
}
bool VanillaOption::Flavor() {
    return isCall;
}

double VanillaOption::delta() const {
    return engine->delta();
}

double VanillaOption::numericalDelta() {
    return engine->numericalDelta();
}

double VanillaOption::deltaForward() const {
    return engine->deltaForward();
}

double VanillaOption::gamma() const {
    return engine->gamma();
}

double VanillaOption::numericalGamma() {
    return engine->numericalGamma();
}

double VanillaOption::theta() const {
    return engine->theta();
}

double VanillaOption::thetaPerDay() const {
    return engine->thetaPerDay();
}

double VanillaOption::vega() const {
    return engine->vega();
}

double VanillaOption::rho() const {
    return engine->rho();
}

double VanillaOption::dividendRho() const {
    return engine->dividendRho();
}

double VanillaOption::strikeSensitivity() const {
    return engine->strikeSensitivity();
}

double VanillaOption::itmCashProbability() const {
    return engine->itmCashProbability();
}

double VanillaOption::NPV() const {
    return engine->NPV();
}

OptionType VanillaOption::Type() {
    return type;
}

void VanillaOption::setPricingEngine(std::unique_ptr<PricingEngine> newEngine) {
    engine = std::move(newEngine); // Set the new pricing engine
    
    engine->UnderlyingPrice(underlyingPrice);
    engine->Strike(strike);
    engine->TimeToMaturity(timeToMaturity);
    engine->Volatility(volatility);
    engine->Interest(interest);
    engine->CostOfCarry(costOfCarry);
    engine->Flavor(isCall);
    engine->Type(type);
}


void VanillaOption::setPricingEngine(AnalyticPricingEngine& engine) {
    engine.UnderlyingPrice(underlyingPrice);
    engine.Strike(strike);
    engine.TimeToMaturity(timeToMaturity);
    engine.Volatility(volatility);
    engine.Interest(interest);
    engine.CostOfCarry(costOfCarry);
    engine.Flavor(isCall);
    engine = engine;
}

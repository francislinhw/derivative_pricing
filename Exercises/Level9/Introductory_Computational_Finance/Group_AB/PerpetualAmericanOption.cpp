#include <PricingEngine.hpp>
#include <PerpetualAmericanOption.hpp>
#include <iostream>
#include <cmath>
#include <AnalyticPricingEngine.hpp>

// Define the VanillaOption class
PerpetualAemricanOption::PerpetualAemricanOption(double underlyingPrice,
                                                 double strike,
                                                 double volatility,
                                                 double interest,
                                                 double costOfCarry,
                                                 bool isCall) :
    underlyingPrice(underlyingPrice),
    strike(strike),
    volatility(volatility),
    interest(interest),
    costOfCarry(costOfCarry),
    isCall(isCall) {}

PerpetualAemricanOption::~PerpetualAemricanOption() {
    // std::cout << "Option Deleted!" << std::endl;
}

void PerpetualAemricanOption::UnderlyingPrice(double underlyingPrice) {
    PerpetualAemricanOption::underlyingPrice = underlyingPrice;
}
void PerpetualAemricanOption::Strike(double strike) {
    PerpetualAemricanOption::strike = strike;
}
void PerpetualAemricanOption::Volatility(double volatility) {
    PerpetualAemricanOption::volatility = volatility;
}
void PerpetualAemricanOption::Interest(double interest) {
    PerpetualAemricanOption::interest = interest;
}
void PerpetualAemricanOption::CostOfCarry(double costOfCarry) {
    PerpetualAemricanOption::costOfCarry = costOfCarry;
}
void PerpetualAemricanOption::Flavor(bool flavor) {
    PerpetualAemricanOption::isCall = flavor;
}

double PerpetualAemricanOption::UnderlyingPrice() {
    return underlyingPrice;
}
double PerpetualAemricanOption::Strike() {
    return strike;
}
double PerpetualAemricanOption::TimeToMaturity() {
    return timeToMaturity;
}
double PerpetualAemricanOption::Volatility() {
    return volatility;
}
double PerpetualAemricanOption::Interest() {
    return interest;
}
double PerpetualAemricanOption::CostOfCarry() {
    return costOfCarry;
}
bool PerpetualAemricanOption::Flavor() {
    return isCall;
}

double PerpetualAemricanOption::delta() const {
    return engine->delta();
}

double PerpetualAemricanOption::numericalDelta() {
    return engine->numericalDelta();
}

double PerpetualAemricanOption::deltaForward() const {
    return engine->deltaForward();
}

double PerpetualAemricanOption::gamma() const {
    return engine->gamma();
}

double PerpetualAemricanOption::numericalGamma() {
    return engine->numericalGamma();
}

double PerpetualAemricanOption::theta() const {
    return engine->theta();
}

double PerpetualAemricanOption::thetaPerDay() const {
    return engine->thetaPerDay();
}

double PerpetualAemricanOption::vega() const {
    return engine->vega();
}

double PerpetualAemricanOption::rho() const {
    return engine->rho();
}

double PerpetualAemricanOption::dividendRho() const {
    return engine->dividendRho();
}

double PerpetualAemricanOption::strikeSensitivity() const {
    return engine->strikeSensitivity();
}

double PerpetualAemricanOption::itmCashProbability() const {
    return engine->itmCashProbability();
}

double PerpetualAemricanOption::NPV() const {
    return engine->NPV();
}

void PerpetualAemricanOption::setPricingEngine(std::unique_ptr<PricingEngine> newEngine) {
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


void PerpetualAemricanOption::setPricingEngine(AnalyticPricingEngine& engine) {
    engine.UnderlyingPrice(underlyingPrice);
    engine.Strike(strike);
    engine.TimeToMaturity(timeToMaturity);
    engine.Volatility(volatility);
    engine.Interest(interest);
    engine.CostOfCarry(costOfCarry);
    engine.Flavor(isCall);
    engine = engine;
}

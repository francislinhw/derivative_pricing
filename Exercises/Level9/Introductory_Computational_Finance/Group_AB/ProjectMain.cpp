#include <base/OptionParameters.hpp>
#include <base/PutCallParity.hpp>
#include <base/Mesh.hpp>
#include <VanillaOption.hpp>
#include <VanillaPricingEngine.hpp>
#include <iostream>
#include <memory>
#include <map>

int main() {

    std::map<std::string, OptionParameters> optionBatches;

    // Batch 1 ~ 4
    optionBatches["Batch 1"] = {0.25, 65, 0.30, 0.08, 60, 0};
    optionBatches["Batch 2"] = {1.0, 100, 0.2, 0.0, 100, 0};
    optionBatches["Batch 3"] = {1.0, 10, 0.50, 0.12, 5, 0};
    optionBatches["Batch 4"] = {30.0, 100.0, 0.30, 0.08, 100.0, 0};

    bool Call = true;
    bool Put = false;

    double batchOnecallOptionPrice, batchOneputOptionPrice;
    double batchTwocallOptionPrice, batchTwoputOptionPrice;
    double batchThreecallOptionPrice, batchThreeputOptionPrice;
    double batchFourcallOptionPrice, batchFourputOptionPrice;

    // a) Implement the above formulae for call and put option pricing using the data sets Batch 1 to Batch 4. Check
    // your answers, as you will need them when we discuss numerical methods for option pricing.

    VanillaOption batchOnevanillaCallOption(optionBatches["Batch 1"].S,
                                            optionBatches["Batch 1"].K,
                                            optionBatches["Batch 1"].T,
                                            optionBatches["Batch 1"].sig,
                                            optionBatches["Batch 1"].r,
                                            optionBatches["Batch 1"].CostOfCarry,
                                            Call);

    VanillaOption batchOnevanillaPutOption(optionBatches["Batch 1"].S,
                                           optionBatches["Batch 1"].K,
                                           optionBatches["Batch 1"].T,
                                           optionBatches["Batch 1"].sig,
                                           optionBatches["Batch 1"].r,
                                           optionBatches["Batch 1"].CostOfCarry,
                                           Put);

    VanillaOption batchTwovanillaCallOption(optionBatches["Batch 2"].S,
                                            optionBatches["Batch 2"].K,
                                            optionBatches["Batch 2"].T,
                                            optionBatches["Batch 2"].sig,
                                            optionBatches["Batch 2"].r,
                                            optionBatches["Batch 2"].CostOfCarry,
                                            Call);

    VanillaOption batchTwovanillaPutOption(optionBatches["Batch 2"].S,
                                           optionBatches["Batch 2"].K,
                                           optionBatches["Batch 2"].T,
                                           optionBatches["Batch 2"].sig,
                                           optionBatches["Batch 2"].r,
                                           optionBatches["Batch 2"].CostOfCarry,
                                           Put);

    VanillaOption batchThreevanillaCallOption(optionBatches["Batch 3"].S,
                                              optionBatches["Batch 3"].K,
                                              optionBatches["Batch 3"].T,
                                              optionBatches["Batch 3"].sig,
                                              optionBatches["Batch 3"].r,
                                              optionBatches["Batch 3"].CostOfCarry,
                                              Call);

    VanillaOption batchThreevanillaPutOption(optionBatches["Batch 3"].S,
                                             optionBatches["Batch 3"].K,
                                             optionBatches["Batch 3"].T,
                                             optionBatches["Batch 3"].sig,
                                             optionBatches["Batch 3"].r,
                                             optionBatches["Batch 3"].CostOfCarry,
                                             Put);

    VanillaOption batchFourvanillaCallOption(optionBatches["Batch 4"].S,
                                             optionBatches["Batch 4"].K,
                                             optionBatches["Batch 4"].T,
                                             optionBatches["Batch 4"].sig,
                                             optionBatches["Batch 4"].r,
                                             optionBatches["Batch 4"].CostOfCarry,
                                             Call);

    VanillaOption batchFourvanillaPutOption(optionBatches["Batch 4"].S,
                                            optionBatches["Batch 4"].K,
                                            optionBatches["Batch 4"].T,
                                            optionBatches["Batch 4"].sig,
                                            optionBatches["Batch 4"].r,
                                            optionBatches["Batch 4"].CostOfCarry,
                                            Put);

    std::unique_ptr<VanillaPricingEngine> batchOnecallPricingEngine = std::make_unique<VanillaPricingEngine>();
    std::unique_ptr<VanillaPricingEngine> batchOneputPricingEngine = std::make_unique<VanillaPricingEngine>();
    std::unique_ptr<VanillaPricingEngine> batchTwocallPricingEngine = std::make_unique<VanillaPricingEngine>();
    std::unique_ptr<VanillaPricingEngine> batchTwoputPricingEngine = std::make_unique<VanillaPricingEngine>();
    std::unique_ptr<VanillaPricingEngine> batchThreecallPricingEngine = std::make_unique<VanillaPricingEngine>();
    std::unique_ptr<VanillaPricingEngine> batchThreeputPricingEngine = std::make_unique<VanillaPricingEngine>();
    std::unique_ptr<VanillaPricingEngine> batchFourcallPricingEngine = std::make_unique<VanillaPricingEngine>();
    std::unique_ptr<VanillaPricingEngine> batchFourputPricingEngine = std::make_unique<VanillaPricingEngine>();


    batchOnevanillaCallOption.setPricingEngine(std::move(batchOnecallPricingEngine));
    batchOnevanillaPutOption.setPricingEngine(std::move(batchOneputPricingEngine));
    batchTwovanillaCallOption.setPricingEngine(std::move(batchTwocallPricingEngine));
    batchTwovanillaPutOption.setPricingEngine(std::move(batchTwoputPricingEngine));
    batchThreevanillaCallOption.setPricingEngine(std::move(batchThreecallPricingEngine));
    batchThreevanillaPutOption.setPricingEngine(std::move(batchThreeputPricingEngine));
    batchFourvanillaCallOption.setPricingEngine(std::move(batchFourcallPricingEngine));
    batchFourvanillaPutOption.setPricingEngine(std::move(batchFourputPricingEngine));

    batchOnecallOptionPrice = batchOnevanillaCallOption.NPV();
    batchOneputOptionPrice = batchOnevanillaPutOption.NPV();
    batchTwocallOptionPrice = batchTwovanillaCallOption.NPV();
    batchTwoputOptionPrice = batchTwovanillaPutOption.NPV();
    batchThreecallOptionPrice = batchThreevanillaCallOption.NPV();
    batchThreeputOptionPrice = batchThreevanillaPutOption.NPV();
    batchFourcallOptionPrice = batchFourvanillaCallOption.NPV();
    batchFourputOptionPrice = batchFourvanillaPutOption.NPV();

    std::cout << "Batch 1 Call Option Price: " << batchOnecallOptionPrice << std::endl;
    std::cout << "Batch 1 Put Option Price: " << batchOneputOptionPrice << std::endl;
    std::cout << "Batch 2 Call Option Price: " << batchTwocallOptionPrice << std::endl;
    std::cout << "Batch 2 Put Option Price: " << batchTwoputOptionPrice << std::endl;
    std::cout << "Batch 3 Call Option Price: " << batchThreecallOptionPrice << std::endl;
    std::cout << "Batch 3 Put Option Price: " << batchThreeputOptionPrice << std::endl;
    std::cout << "Batch 4 Call Option Price: " << batchFourcallOptionPrice << std::endl;
    std::cout << "Batch 4 Put Option Price: " << batchFourputOptionPrice << std::endl;

    // b) Applytheput-callparityrelationshiptocomputecallandputoptionprices.Forexample,giventhecallprice,
    // compute the put price based on this formula using Batches 1 to 4.
    // Check your answers with the prices from part a).
    // Note that there are two useful ways to implement parity:
    // As a mechanism to calculate the call (or put) price for a corresponding put (or call) price,
    // or as a mechanism to check if a given set of put/call prices satisfy parity.
    // The ideal submission will neatly implement both approaches.

    // Call and put prices from part a)
    std::map<std::string, double> callPrices = {
        {"Batch 1", batchOnecallOptionPrice},
        {"Batch 2", batchTwocallOptionPrice},
        {"Batch 3", batchThreecallOptionPrice},
        {"Batch 4", batchFourcallOptionPrice}
    };

    std::map<std::string, double> putPrices = {
        {"Batch 1", batchOneputOptionPrice},
        {"Batch 2", batchTwoputOptionPrice},
        {"Batch 3", batchThreeputOptionPrice},
        {"Batch 4", batchFourputOptionPrice}
    };

    // Calculating put prices and checking parity
    for (const auto& batch : optionBatches) {
        const std::string& batchName = batch.first;
        const OptionParameters& params = batch.second;
        double callPrice = callPrices[batchName];
        double computedPutPrice = calculatePutPrice(params, callPrice);
        double actualPutPrice = putPrices[batchName];

        std::cout << "Computed Put Price for " << batchName << ": " << computedPutPrice << std::endl;
        std::cout << "Actual Put Price for " << batchName << ": " << actualPutPrice << std::endl;
        std::cout << "Put-Call Parity Satisfied: " << (isParitySatisfied(params, callPrice, actualPutPrice) ? "Yes" : "No") << std::endl;
        std::cout << std::endl;
    }

    // c) Say we wish to compute option prices for a monotonically increasing range of underlying values of S,
    // for example 10, 11, 12, ..., 50. To this end, the output will be a vector.
    // This entails calling the option pricing formulae for each value S and each computed option price will be stored in a std::vector<double> object.
    // It will be useful to write a global function that produces a mesh array of doubles separated by a mesh size h.
    // Create mesh array for S values from 10 to 50 with a step of 1

    std::vector<double> underlyingValues = createMesh(10, 50, 1);

    std::vector<OptionParameters> meshOptionParameters = createMeshOptionParameters(optionBatches["Batch 1"],
                                                                                    underlyingValues,
                                                                                    OptionVariables::UnderlyingPrice);

    std::pair<std::vector<double>, std::vector<double>> prices = computeOptionPricesVector(meshOptionParameters);
    std::vector<double> callPricesVector = prices.first;
    std::vector<double> putPricesVector = prices.second;

    // Output the results
    std::cout << "\nOption Parameters Analysis:\n" << std::endl;
    for (size_t i = 0; i < meshOptionParameters.size(); ++i) {
        std::cout << "S = " << meshOptionParameters[i].S << ", Call Option Price = " << callPricesVector[i] << std::endl;
        std::cout << "S = " << meshOptionParameters[i].S << ", Put Option Price = " << putPricesVector[i] << std::endl;
    }

    // d) Now we wish to extend part c and compute option prices as a function of 
    //      i) expiry time, 
    //      ii) volatility, or 
    //      iii) any of the option pricing parameters.
    //
    // Essentially, the purpose here is to be able to input a matrix (vector of vectors) of option parameters,
    // and receive a matrix of option prices as the result.
    // Encapsulate this functionality in the most flexible/robust way you can think of.

    std::vector<double> expiryTimeValues = createMesh(0.2, 1, 0.02);
    std::vector<double> volatilityValues = createMesh(0.1, 0.5, 0.01);
    std::vector<double> riskFreeRateValues = createMesh(0.01, 0.05, 0.001);

    std::vector<OptionParameters> meshExpiryOptionParameters = createMeshOptionParameters(optionBatches["Batch 1"],
                                                                                          expiryTimeValues,
                                                                                          OptionVariables::TimeToMaturity);

    std::vector<OptionParameters> meshVolatilityOptionParameters = createMeshOptionParameters(optionBatches["Batch 1"],
                                                                                              volatilityValues,
                                                                                              OptionVariables::Volatility);

    std::vector<OptionParameters> meshRFROptionParameters = createMeshOptionParameters(optionBatches["Batch 1"],
                                                                                       riskFreeRateValues,
                                                                                       OptionVariables::RiskFreeRate);

    std::pair<std::vector<double>, std::vector<double>> expiryMovedprices = computeOptionPricesVector(meshExpiryOptionParameters);
    std::vector<double> expCallPricesVector = expiryMovedprices.first;
    std::vector<double> expPutPricesVector = expiryMovedprices.second;

    std::pair<std::vector<double>, std::vector<double>> volatilityMovedprices = computeOptionPricesVector(meshVolatilityOptionParameters);
    std::vector<double> volCallPricesVector = volatilityMovedprices.first;
    std::vector<double> volPutPricesVector = volatilityMovedprices.second;

    std::pair<std::vector<double>, std::vector<double>> rfrMovedprices = computeOptionPricesVector(meshRFROptionParameters);
    std::vector<double> rfrCallPricesVector = rfrMovedprices.first;
    std::vector<double> rfrPutPricesVector = rfrMovedprices.second;

    // Output the results
    std::cout << "\nOption Parameters Analysis:\n" << std::endl;
    for (size_t i = 0; i < meshOptionParameters.size(); ++i) {
        std::cout << "S = " << meshOptionParameters[i].S << ", Call Option Price = " << callPricesVector[i] << std::endl;
        std::cout << "S = " << meshOptionParameters[i].S << ", Put Option Price = " << putPricesVector[i] << std::endl;
        std::cout << "T = " << meshExpiryOptionParameters[i].T << ", Call Option Price = " << expCallPricesVector[i] << std::endl;
        std::cout << "T = " << meshExpiryOptionParameters[i].T << ", Put Option Price = " << expPutPricesVector[i] << std::endl;
        std::cout << "Sig = " << meshVolatilityOptionParameters[i].sig << ", Call Option Price = " << volCallPricesVector[i] << std::endl;
        std::cout << "Sig = " << meshVolatilityOptionParameters[i].sig << ", Put Option Price = " << volPutPricesVector[i] << std::endl;
        std::cout << "r = " << meshRFROptionParameters[i].r << ", Call Option Price = " << rfrCallPricesVector[i] << std::endl;
        std::cout << "r = " << meshRFROptionParameters[i].r << ", Put Option Price = " << rfrPutPricesVector[i] << std::endl;
    }

    std::vector<std::vector<OptionParameters>> paramsMatrix = {
        {OptionParameters(50, 100, 1.0, 0.2, 0.05, 0), OptionParameters(51, 100, 1.0, 0.2, 0.05, 0)},
        {OptionParameters(50, 100, 1.0, 0.25, 0.05, 0), OptionParameters(51, 100, 1.0, 0.25, 0.05, 0)}
    };

    auto pricesMatrix = computeOptionPricesMatrix(paramsMatrix);

    return 0;
}
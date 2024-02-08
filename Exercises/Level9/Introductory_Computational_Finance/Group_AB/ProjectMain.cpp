#include <base/OptionParameters.hpp>
#include <base/PutCallParity.hpp>
#include <base/Mesh.hpp>
#include <base/OptionType.hpp>
#include <VanillaOption.hpp>
#include <PerpetualAmericanOption.hpp>
#include <AnalyticPricingEngine.hpp>
#include <iostream>
#include <memory>
#include <map>

int main() {

    std::map<std::string, OptionParameters> optionBatches;

    // Batch 1 ~ 4
    optionBatches["Batch 1"] = OptionParameters(60, 65, 0.25, 0.3, 0.08, 0, EUROPEAN);
    optionBatches["Batch 2"] = OptionParameters(100, 100, 1.0, 0.2, 0.0, 0, EUROPEAN);
    optionBatches["Batch 3"] = OptionParameters(5, 10, 1.0, 0.5, 0.12, 0, EUROPEAN);
    optionBatches["Batch 4"] = OptionParameters(100, 100, 30.0, 0.3, 0.08, 0, EUROPEAN);

    bool Call = true;
    bool Put = false;

    double batchOnecallOptionPrice, batchOneputOptionPrice;
    double batchTwocallOptionPrice, batchTwoputOptionPrice;
    double batchThreecallOptionPrice, batchThreeputOptionPrice;
    double batchFourcallOptionPrice, batchFourputOptionPrice;

    // A-a) Implement the above formulae for call and put option pricing using the data sets Batch 1 to Batch 4. Check
    // your answers, as you will need them when we discuss numerical methods for option pricing.

    VanillaOption batchOnevanillaCallOption(optionBatches["Batch 1"].S,
                                            optionBatches["Batch 1"].K,
                                            optionBatches["Batch 1"].T,
                                            optionBatches["Batch 1"].sig,
                                            optionBatches["Batch 1"].r,
                                            optionBatches["Batch 1"].CostOfCarry,
                                            Call,
                                            EUROPEAN);

    VanillaOption batchOnevanillaPutOption(optionBatches["Batch 1"].S,
                                           optionBatches["Batch 1"].K,
                                           optionBatches["Batch 1"].T,
                                           optionBatches["Batch 1"].sig,
                                           optionBatches["Batch 1"].r,
                                           optionBatches["Batch 1"].CostOfCarry,
                                           Put,
                                           EUROPEAN);

    VanillaOption batchTwovanillaCallOption(optionBatches["Batch 2"].S,
                                            optionBatches["Batch 2"].K,
                                            optionBatches["Batch 2"].T,
                                            optionBatches["Batch 2"].sig,
                                            optionBatches["Batch 2"].r,
                                            optionBatches["Batch 2"].CostOfCarry,
                                            Call,
                                            EUROPEAN);

    VanillaOption batchTwovanillaPutOption(optionBatches["Batch 2"].S,
                                           optionBatches["Batch 2"].K,
                                           optionBatches["Batch 2"].T,
                                           optionBatches["Batch 2"].sig,
                                           optionBatches["Batch 2"].r,
                                           optionBatches["Batch 2"].CostOfCarry,
                                           Put,
                                           EUROPEAN);

    VanillaOption batchThreevanillaCallOption(optionBatches["Batch 3"].S,
                                              optionBatches["Batch 3"].K,
                                              optionBatches["Batch 3"].T,
                                              optionBatches["Batch 3"].sig,
                                              optionBatches["Batch 3"].r,
                                              optionBatches["Batch 3"].CostOfCarry,
                                              Call,
                                              EUROPEAN);

    VanillaOption batchThreevanillaPutOption(optionBatches["Batch 3"].S,
                                             optionBatches["Batch 3"].K,
                                             optionBatches["Batch 3"].T,
                                             optionBatches["Batch 3"].sig,
                                             optionBatches["Batch 3"].r,
                                             optionBatches["Batch 3"].CostOfCarry,
                                             Put,
                                             EUROPEAN);

    VanillaOption batchFourvanillaCallOption(optionBatches["Batch 4"].S,
                                             optionBatches["Batch 4"].K,
                                             optionBatches["Batch 4"].T,
                                             optionBatches["Batch 4"].sig,
                                             optionBatches["Batch 4"].r,
                                             optionBatches["Batch 4"].CostOfCarry,
                                             Call,
                                             EUROPEAN);

    VanillaOption batchFourvanillaPutOption(optionBatches["Batch 4"].S,
                                            optionBatches["Batch 4"].K,
                                            optionBatches["Batch 4"].T,
                                            optionBatches["Batch 4"].sig,
                                            optionBatches["Batch 4"].r,
                                            optionBatches["Batch 4"].CostOfCarry,
                                            Put,
                                            EUROPEAN);

    // Create Analytical Pricing Engines for options
    std::unique_ptr<AnalyticPricingEngine> batchOnecallPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchOneputPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchTwocallPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchTwoputPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchThreecallPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchThreeputPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchFourcallPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchFourputPricingEngine = std::make_unique<AnalyticPricingEngine>();

    // Set the Pricing Engines to the corresponding Options
    batchOnevanillaCallOption.setPricingEngine(std::move(batchOnecallPricingEngine));
    batchOnevanillaPutOption.setPricingEngine(std::move(batchOneputPricingEngine));
    batchTwovanillaCallOption.setPricingEngine(std::move(batchTwocallPricingEngine));
    batchTwovanillaPutOption.setPricingEngine(std::move(batchTwoputPricingEngine));
    batchThreevanillaCallOption.setPricingEngine(std::move(batchThreecallPricingEngine));
    batchThreevanillaPutOption.setPricingEngine(std::move(batchThreeputPricingEngine));
    batchFourvanillaCallOption.setPricingEngine(std::move(batchFourcallPricingEngine));
    batchFourvanillaPutOption.setPricingEngine(std::move(batchFourputPricingEngine));

    // Get the Net Present Value (NPV) of Option by the calculation of Analytic Solution
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

    // A-b) Applytheput-callparityrelationshiptocomputecallandputoptionprices.Forexample,giventhecallprice,
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
        double computedCallPrice = calculateCallPrice(params, actualPutPrice);

        std::cout << "Computed Call Price for " << batchName << ": " << computedCallPrice << std::endl;
        std::cout << "Actual Call Price for " << batchName << ": " << callPrice << std::endl;
        std::cout << "Computed Put Price for " << batchName << ": " << computedPutPrice << std::endl;
        std::cout << "Actual Put Price for " << batchName << ": " << actualPutPrice << std::endl;
        std::cout << "Put-Call Parity Satisfied: " << (isParitySatisfied(params, callPrice, actualPutPrice) ? "Yes" : "No") << std::endl;
        std::cout << std::endl;
    }

    // A-c) Say we wish to compute option prices for a monotonically increasing range of underlying values of S,
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

    // A-d) Now we wish to extend part c and compute option prices as a function of 
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
        {OptionParameters(50, 100, 1.0, 0.2, 0.05, 0, EUROPEAN), OptionParameters(51, 100, 1.0, 0.2, 0.05, 0, EUROPEAN)},
        {OptionParameters(50, 100, 1.0, 0.25, 0.05, 0, EUROPEAN), OptionParameters(51, 100, 1.0, 0.25, 0.05, 0, EUROPEAN)}
    };

    auto pricesMatrix = computeOptionPricesMatrix(paramsMatrix);

    // A-a) Implement the above formulae for gamma for call and put future option pricing using the data set:
    //     K = 100,
    //     S = 105,
    //     T = 0.5,
    //     r = 0.1,
    //     b = 0 and
    //     sig = 0.36. (exact delta call = 0.5946, delta put = -0.3566).

    VanillaOption greeksTestVanillaCallOption(105,
                                              100,
                                              0.5,
                                              0.36,
                                              0.1,
                                              0,
                                              Call,
                                              EUROPEAN);

    VanillaOption greeksTestVanillaPutOption(105,
                                             100,
                                             0.5,
                                             0.36,
                                             0.1,
                                             0,
                                             Put,
                                             EUROPEAN);

    std::unique_ptr<AnalyticPricingEngine> greeksTestCallPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> greeksTestPutPricingEngine = std::make_unique<AnalyticPricingEngine>();

    greeksTestVanillaCallOption.setPricingEngine(std::move(greeksTestCallPricingEngine));
    greeksTestVanillaPutOption.setPricingEngine(std::move(greeksTestPutPricingEngine));

    std::cout << "Call Option Delta: " << greeksTestVanillaCallOption.delta() << std::endl;
    std::cout << "Put Option Delta: " << greeksTestVanillaPutOption.delta() << std::endl;

    // A-b) We now use the code in part a to compute call delta price for a monotonically increasing range of underlying values of S,
    // for example 10, 11, 12, ..., 50.
    // To this end,
    // the output will be a vector and it entails calling the above formula for a call delta for each value S and each computed option price will be store in a std::vector<double> object.
    // It will be useful to reuse the above global function that produces a mesh array of double separated by a mesh size h.

    // Create a mesh for the underlying stock prices S
    std::vector<double> S_mesh = createMesh(80, 120, 1);

    // Vector to store delta values
    std::vector<double> delta_values;

    // Compute delta for each S value in the mesh
    for (double S : S_mesh) {
        // Create a call option with the current S value
        VanillaOption callOption(S,
                                 100,
                                 0.5,
                                 0.36,
                                 0.1,
                                 0,
                                 Call,
                                 EUROPEAN);

        VanillaOption putOption(S,
                                100,
                                0.5,
                                0.36,
                                0.1,
                                0,
                                Put,
                                EUROPEAN);

        // Create a pricing engine and set it to the option
        std::unique_ptr<AnalyticPricingEngine> pricingEngine = std::make_unique<AnalyticPricingEngine>();
        callOption.setPricingEngine(std::move(pricingEngine));

        // Compute the delta and add it to the delta_values vector
        double delta = callOption.delta();
        delta_values.push_back(delta);
    }

    // Output the results
    std::cout << "\nDelta values for call options with S ranging from 10 to 50:\n\n";
    for (size_t i = 0; i < S_mesh.size(); ++i) {
        std::cout << "S = " << S_mesh[i] << ", Delta = " << delta_values[i] << "\n";
    }

    // A-c) Incorporate this into your above matrix pricer code,
    // so you can input a matrix of option parameters and receive a matrix of either Delta or Gamma as the result.
    // Define a matrix of option parameters
    std::vector<std::vector<OptionParameters>> optionParamsMatrix = {
        // Row for different S values
        {OptionParameters(50, 100, 1, 0.2, 0.05, 0, EUROPEAN), OptionParameters(51, 100, 1, 0.2, 0.05, 0, EUROPEAN)},
        // Row for different T values
        {OptionParameters(50, 100, 0.8, 0.2, 0.05, 0, EUROPEAN), OptionParameters(50, 100, 1.2, 0.2, 0.05, 0, EUROPEAN)}
        // Add more rows as needed
    };

    // Compute Delta matrix
    std::vector<std::vector<double>> deltaMatrix = computeGreeksMatrix(optionParamsMatrix, DELTA);

    // Compute Gamma matrix
    std::vector<std::vector<double>> gammaMatrix = computeGreeksMatrix(optionParamsMatrix, GAMMA);

    // Output the results
    std::cout << "Delta Matrix:\n";
    for (const auto& row : deltaMatrix) {
        for (double value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nGamma Matrix:\n";
    for (const auto& row : gammaMatrix) {
        for (double value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    // A-d) We now use divided differences to approximate option sensitivities.
    // In some cases, an exact formula may not exist (or is difficult to find) and we resort to numerical methods.
    // In general, we can approximate first and second-order derivatives in S by 3-point second order approximations, for example:

    // double h = 0.00005; // User can also set h manually.
    // batchOnevanillaCallOption.engine->NumericalGreeksBump(h);
    std::cout << "\nParameter h: " << greeksTestVanillaCallOption.engine->NumericalGreeksBump() << std::endl;
    std::cout << "Batch 1 Call Option Numerical Delta: " << greeksTestVanillaCallOption.numericalDelta() << std::endl;
    std::cout << "Batch 1 Call Option Delta: " << greeksTestVanillaCallOption.delta() << std::endl;
    std::cout << "Batch 1 Call Option Numerical Gamma: " << greeksTestVanillaCallOption.numericalGamma() << std::endl;
    std::cout << "Batch 1 Call Option Gamma: " << greeksTestVanillaCallOption.gamma() << std::endl;

    // B-a) Program the above formulae, and incorporate into your well-designed options pricing classes. (In my analytical engine)
    // B-b) Test the data with K=100,sig=0.1,r=0.1,b=0.02,S=110(checkC=18.5035,P=3.03106).

    PerpetualAemricanOption perpAmericanCallOption(110,
                                                   100,
                                                   0.1,
                                                   0.1,
                                                   0.02,
                                                   Call);

    PerpetualAemricanOption perpAmericanPutOption(110,
                                                  100,
                                                  0.1,
                                                  0.1,
                                                  0.02,
                                                  Put);

    std::unique_ptr<AnalyticPricingEngine> perpAmericanCallOptionEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> perpAmericanPutOptionEngine = std::make_unique<AnalyticPricingEngine>();

    perpAmericanCallOption.setPricingEngine(std::move(perpAmericanCallOptionEngine));
    perpAmericanPutOption.setPricingEngine(std::move(perpAmericanPutOptionEngine));

    std::cout << "Perpetual American Option Call Price: " << perpAmericanCallOption.NPV() << std::endl;
    std::cout << "Perpetual American Option Put Price: " << perpAmericanPutOption.NPV() << std::endl;

    // B-c) We now use the code in part a) to compute call and put option price for a monotonically increasing range of underlying values of S,
    // for example 10, 11, 12, ..., 50.
    // To this end, the output will be a vector and this exercise entails calling the option pricing formulae in part a) for each value S and each computed option price will be stored in a std::vector<double> object.
    // It will be useful to reuse the above global function that produces a mesh array of double separated by a mesh size h.

    // Vector to store delta values
    std::vector<double> paoCallPriceValues;
    std::vector<double> paoPutPriceValues;

    // Compute delta for each S value in the mesh
    for (double S : S_mesh) {
        // Create a call option with the current S value
        PerpetualAemricanOption perpAmericanCallOption(S,
                                                       100,
                                                       0.1,
                                                       0.1,
                                                       0.02,
                                                       Call);

        PerpetualAemricanOption perpAmericanPutOption(S,
                                                      100,
                                                      0.1,
                                                      0.1,
                                                      0.02,
                                                      Put);

        // Create a pricing engine and set it to the option
        std::unique_ptr<AnalyticPricingEngine> perpCallpricingEngine = std::make_unique<AnalyticPricingEngine>();
        std::unique_ptr<AnalyticPricingEngine> perpPutpricingEngine = std::make_unique<AnalyticPricingEngine>();

        perpAmericanCallOption.setPricingEngine(std::move(perpCallpricingEngine));
        perpAmericanPutOption.setPricingEngine(std::move(perpPutpricingEngine));

        // Compute the delta and add it to the delta_values vector
        paoCallPriceValues.push_back(perpAmericanCallOption.NPV());
        paoPutPriceValues.push_back(perpAmericanPutOption.NPV());
    }

    // Output the results
    std::cout << "\nDelta values for Perpetual American options with S ranging from 80 to 120:\n\n";
    for (size_t i = 0; i < S_mesh.size(); ++i) {
        std::cout << "S = " << S_mesh[i] << ", Call Price = " << paoCallPriceValues[i] << "\n";
        std::cout << "S = " << S_mesh[i] << ", Put Price = " << paoPutPriceValues[i] << "\n";
    }

    // B-d) Incorporate this into your above matrix pricer code,
    // so you can input a matrix of option parameters and receive a matrix of Perpetual American option prices.

    std::vector<std::vector<OptionParameters>> perpAmericanOptionParamsMatrix = {
        // Row for different S values
        {OptionParameters(50, 100, INFINITY, 0.2, 0.05, 0, AMERICAN), OptionParameters(51, 100, INFINITY, 0.2, 0.05, 0, AMERICAN)},
        // Row for different T values
        {OptionParameters(50, 100, INFINITY, 0.2, 0.05, 0, AMERICAN), OptionParameters(50, 100, INFINITY, 0.2, 0.05, 0, AMERICAN)}
        // Add more rows as needed
    };

    // Compute Delta matrix
    std::vector<std::vector<double>> perpAmericanDeltaMatrix = computeOptionPricesMatrix(perpAmericanOptionParamsMatrix);

    // Compute Gamma matrix
    std::vector<std::vector<double>> perpAmericangammaMatrix = computeOptionPricesMatrix(perpAmericanOptionParamsMatrix);

    // Output the results
    std::cout << "Price Matrix:\n";
    for (const auto& row : perpAmericanDeltaMatrix) {
        for (double value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    return 0;

    /*
     * 
     * ============== *
     * PROGRAM OUTPUT *
     * ============== *
     * 
     * Batch 1 Call Option Price: 2.13337
     * Batch 1 Put Option Price: 5.84628
     * Batch 2 Call Option Price: 7.96557
     * Batch 2 Put Option Price: 7.96557
     * Batch 3 Call Option Price: 0.204058
     * Batch 3 Put Option Price: 4.07326
     * Batch 4 Call Option Price: 92.1757
     * Batch 4 Put Option Price: 1.2475
     * Computed Call Price for Batch 1: 2.13337
     * Actual Call Price for Batch 1: 2.13337
     * Computed Put Price for Batch 1: 5.84628
     * Actual Put Price for Batch 1: 5.84628
     * Put-Call Parity Satisfied: Yes
     * Computed Call Price for Batch 2: 7.96557
     * Actual Call Price for Batch 2: 7.96557
     * Computed Put Price for Batch 2: 7.96557
     * Actual Put Price for Batch 2: 7.96557
     * Put-Call Parity Satisfied: Yes
     * Computed Call Price for Batch 3: 0.204058
     * Actual Call Price for Batch 3: 0.204058
     * Computed Put Price for Batch 3: 4.07326
     * Actual Put Price for Batch 3: 4.07326
     * Put-Call Parity Satisfied: Yes
     * Computed Call Price for Batch 4: 92.1757
     * Actual Call Price for Batch 4: 92.1757
     * Computed Put Price for Batch 4: 1.2475
     * Actual Put Price for Batch 4: 1.2475
     * Put-Call Parity Satisfied: Yes
     * Option Parameters Analysis:
     * S = 10, Call Option Price = 7.792e-36
     * S = 10, Put Option Price = 53.7129
     * S = 11, Call Option Price = 1.88964e-32
     * S = 11, Put Option Price = 52.7129
     * S = 12, Call Option Price = 1.64204e-29
     * S = 12, Put Option Price = 51.7129
     * S = 13, Call Option Price = 6.19303e-27
     * S = 13, Put Option Price = 50.7129
     * S = 14, Call Option Price = 1.17207e-24
     * S = 14, Put Option Price = 49.7129
     * S = 15, Call Option Price = 1.24529e-22
     * S = 15, Put Option Price = 48.7129
     * S = 16, Call Option Price = 8.11387e-21
     * S = 16, Put Option Price = 47.7129
     * S = 17, Call Option Price = 3.47944e-19
     * S = 17, Put Option Price = 46.7129
     * S = 18, Call Option Price = 1.03991e-17
     * S = 18, Put Option Price = 45.7129
     * S = 19, Call Option Price = 2.27042e-16
     * S = 19, Put Option Price = 44.7129
     * S = 20, Call Option Price = 3.76503e-15
     * S = 20, Put Option Price = 43.7129
     * S = 21, Call Option Price = 4.89964e-14
     * S = 21, Put Option Price = 42.7129
     * S = 22, Call Option Price = 5.1436e-13
     * S = 22, Put Option Price = 41.7129
     * S = 23, Call Option Price = 4.45934e-12
     * S = 23, Put Option Price = 40.7129
     * S = 24, Call Option Price = 3.25772e-11
     * S = 24, Put Option Price = 39.7129
     * S = 25, Call Option Price = 2.0405e-10
     * S = 25, Put Option Price = 38.7129
     * S = 26, Call Option Price = 1.11246e-09
     * S = 26, Put Option Price = 37.7129
     * S = 27, Call Option Price = 5.34891e-09
     * S = 27, Put Option Price = 36.7129
     * S = 28, Call Option Price = 2.29454e-08
     * S = 28, Put Option Price = 35.7129
     * S = 29, Call Option Price = 8.8713e-08
     * S = 29, Put Option Price = 34.7129
     * S = 30, Call Option Price = 3.11926e-07
     * S = 30, Put Option Price = 33.7129
     * S = 31, Call Option Price = 1.00545e-06
     * S = 31, Put Option Price = 32.7129
     * S = 32, Call Option Price = 2.99241e-06
     * S = 32, Put Option Price = 31.7129
     * S = 33, Call Option Price = 8.27565e-06
     * S = 33, Put Option Price = 30.7129
     * S = 34, Call Option Price = 2.13896e-05
     * S = 34, Put Option Price = 29.7129
     * S = 35, Call Option Price = 5.19359e-05
     * S = 35, Put Option Price = 28.713
     * S = 36, Call Option Price = 0.000119024
     * S = 36, Put Option Price = 27.713
     * S = 37, Call Option Price = 0.000258548
     * S = 37, Put Option Price = 26.7132
     * S = 38, Call Option Price = 0.000534403
     * S = 38, Put Option Price = 25.7134
     * S = 39, Call Option Price = 0.00105474
     * S = 39, Put Option Price = 24.714
     * S = 40, Call Option Price = 0.00199417
     * S = 40, Put Option Price = 23.7149
     * S = 41, Call Option Price = 0.00362244
     * S = 41, Put Option Price = 22.7165
     * S = 42, Call Option Price = 0.00633924
     * S = 42, Put Option Price = 21.7193
     * S = 43, Call Option Price = 0.010714
     * S = 43, Put Option Price = 20.7236
     * S = 44, Call Option Price = 0.0175282
     * S = 44, Put Option Price = 19.7304
     * S = 45, Call Option Price = 0.0278174
     * S = 45, Put Option Price = 18.7407
     * S = 46, Call Option Price = 0.0429083
     * S = 46, Put Option Price = 17.7558
     * S = 47, Call Option Price = 0.0644467
     * S = 47, Put Option Price = 16.7774
     * S = 48, Call Option Price = 0.0944125
     * S = 48, Put Option Price = 15.8073
     * S = 49, Call Option Price = 0.135117
     * S = 49, Put Option Price = 14.848
     * S = 50, Call Option Price = 0.189181
     * S = 50, Put Option Price = 13.9021
     * Option Parameters Analysis:
     * S = 10, Call Option Price = 7.792e-36
     * S = 10, Put Option Price = 53.7129
     * T = 0.2, Call Option Price = 1.70096
     * T = 0.2, Put Option Price = 5.66924
     * Sig = 0.1, Call Option Price = 0.173097
     * Sig = 0.1, Put Option Price = 3.88601
     * r = 0.01, Call Option Price = 1.79948
     * r = 0.01, Put Option Price = 6.63718
     * S = 11, Call Option Price = 1.88964e-32
     * S = 11, Put Option Price = 52.7129
     * T = 0.22, Call Option Price = 1.87665
     * T = 0.22, Put Option Price = 5.74266
     * Sig = 0.11, Call Option Price = 0.237149
     * Sig = 0.11, Put Option Price = 3.95006
     * r = 0.011, Call Option Price = 1.80397
     * r = 0.011, Put Option Price = 6.62546
     * S = 12, Call Option Price = 1.64204e-29
     * S = 12, Put Option Price = 51.7129
     * T = 0.24, Call Option Price = 2.04867
     * T = 0.24, Put Option Price = 5.81257
     * Sig = 0.12, Call Option Price = 0.30857
     * Sig = 0.12, Put Option Price = 4.02148
     * r = 0.012, Call Option Price = 1.80847
     * r = 0.012, Put Option Price = 6.61376
     * S = 13, Call Option Price = 6.19303e-27
     * S = 13, Put Option Price = 50.7129
     * T = 0.26, Call Option Price = 2.21724
     * T = 0.26, Put Option Price = 5.8792
     * Sig = 0.13, Call Option Price = 0.386235
     * Sig = 0.13, Put Option Price = 4.09915
     * r = 0.013, Call Option Price = 1.81298
     * r = 0.013, Put Option Price = 6.60207
     * S = 14, Call Option Price = 1.17207e-24
     * S = 14, Put Option Price = 49.7129
     * T = 0.28, Call Option Price = 2.3826
     * T = 0.28, Put Option Price = 5.94278
     * Sig = 0.14, Call Option Price = 0.469188
     * Sig = 0.14, Put Option Price = 4.1821
     * r = 0.014, Call Option Price = 1.8175
     * r = 0.014, Put Option Price = 6.59039
     * S = 15, Call Option Price = 1.24529e-22
     * S = 15, Put Option Price = 48.7129
     * T = 0.3, Call Option Price = 2.54494
     * T = 0.3, Put Option Price = 6.00351
     * Sig = 0.15, Call Option Price = 0.556628
     * Sig = 0.15, Put Option Price = 4.26954
     * r = 0.015, Call Option Price = 1.82202
     * r = 0.015, Put Option Price = 6.57873
     * S = 16, Call Option Price = 8.11387e-21
     * S = 16, Put Option Price = 47.7129
     * T = 0.32, Call Option Price = 2.70447
     * T = 0.32, Put Option Price = 6.06159
     * Sig = 0.16, Call Option Price = 0.647891
     * Sig = 0.16, Put Option Price = 4.36081
     * r = 0.016, Call Option Price = 1.82655
     * r = 0.016, Put Option Price = 6.56707
     * S = 17, Call Option Price = 3.47944e-19
     * S = 17, Put Option Price = 46.7129
     * T = 0.34, Call Option Price = 2.86135
     * T = 0.34, Put Option Price = 6.11718
     * Sig = 0.17, Call Option Price = 0.742427
     * Sig = 0.17, Put Option Price = 4.45534
     * r = 0.017, Call Option Price = 1.83109
     * r = 0.017, Put Option Price = 6.55543
     * S = 18, Call Option Price = 1.03991e-17
     * S = 18, Put Option Price = 45.7129
     * T = 0.36, Call Option Price = 3.01575
     * T = 0.36, Put Option Price = 6.17045
     * Sig = 0.18, Call Option Price = 0.839776
     * Sig = 0.18, Put Option Price = 4.55269
     * r = 0.018, Call Option Price = 1.83564
     * r = 0.018, Put Option Price = 6.5438
     * S = 19, Call Option Price = 2.27042e-16
     * S = 19, Put Option Price = 44.7129
     * T = 0.38, Call Option Price = 3.1678
     * T = 0.38, Put Option Price = 6.22153
     * Sig = 0.19, Call Option Price = 0.939559
     * Sig = 0.19, Put Option Price = 4.65247
     * r = 0.019, Call Option Price = 1.8402
     * r = 0.019, Put Option Price = 6.53218
     * S = 20, Call Option Price = 3.76503e-15
     * S = 20, Put Option Price = 43.7129
     * T = 0.4, Call Option Price = 3.31764
     * T = 0.4, Put Option Price = 6.27057
     * Sig = 0.2, Call Option Price = 1.04145
     * Sig = 0.2, Put Option Price = 4.75437
     * r = 0.02, Call Option Price = 1.84476
     * r = 0.02, Put Option Price = 6.52057
     * S = 21, Call Option Price = 4.89964e-14
     * S = 21, Put Option Price = 42.7129
     * T = 0.42, Call Option Price = 3.4654
     * T = 0.42, Put Option Price = 6.31768
     * Sig = 0.21, Call Option Price = 1.14519
     * Sig = 0.21, Put Option Price = 4.85811
     * r = 0.021, Call Option Price = 1.84934
     * r = 0.021, Put Option Price = 6.50898
     * S = 22, Call Option Price = 5.1436e-13
     * S = 22, Put Option Price = 41.7129
     * T = 0.44, Call Option Price = 3.61117
     * T = 0.44, Put Option Price = 6.36297
     * Sig = 0.22, Call Option Price = 1.25055
     * Sig = 0.22, Put Option Price = 4.96347
     * r = 0.022, Call Option Price = 1.85392
     * r = 0.022, Put Option Price = 6.4974
     * S = 23, Call Option Price = 4.45934e-12
     * S = 23, Put Option Price = 40.7129
     * T = 0.46, Call Option Price = 3.75507
     * T = 0.46, Put Option Price = 6.40654
     * Sig = 0.23, Call Option Price = 1.35734
     * Sig = 0.23, Put Option Price = 5.07025
     * r = 0.023, Call Option Price = 1.85851
     * r = 0.023, Put Option Price = 6.48583
     * S = 24, Call Option Price = 3.25772e-11
     * S = 24, Put Option Price = 39.7129
     * T = 0.48, Call Option Price = 3.89717
     * T = 0.48, Put Option Price = 6.44849
     * Sig = 0.24, Call Option Price = 1.46538
     * Sig = 0.24, Put Option Price = 5.17829
     * r = 0.024, Call Option Price = 1.8631
     * r = 0.024, Put Option Price = 6.47427
     * S = 25, Call Option Price = 2.0405e-10
     * S = 25, Put Option Price = 38.7129
     * T = 0.5, Call Option Price = 4.03758
     * T = 0.5, Put Option Price = 6.4889
     * Sig = 0.25, Call Option Price = 1.57454
     * Sig = 0.25, Put Option Price = 5.28745
     * r = 0.025, Call Option Price = 1.86771
     * r = 0.025, Put Option Price = 6.46272
     * S = 26, Call Option Price = 1.11246e-09
     * S = 26, Put Option Price = 37.7129
     * T = 0.52, Call Option Price = 4.17637
     * T = 0.52, Put Option Price = 6.52784
     * Sig = 0.26, Call Option Price = 1.6847
     * Sig = 0.26, Put Option Price = 5.39761
     * r = 0.026, Call Option Price = 1.87232
     * r = 0.026, Put Option Price = 6.45119
     * S = 27, Call Option Price = 5.34891e-09
     * S = 27, Put Option Price = 36.7129
     * T = 0.54, Call Option Price = 4.3136
     * T = 0.54, Put Option Price = 6.56539
     * Sig = 0.27, Call Option Price = 1.79574
     * Sig = 0.27, Put Option Price = 5.50866
     * r = 0.027, Call Option Price = 1.87694
     * r = 0.027, Put Option Price = 6.43967
     * S = 28, Call Option Price = 2.29454e-08
     * S = 28, Put Option Price = 35.7129
     * T = 0.56, Call Option Price = 4.44935
     * T = 0.56, Put Option Price = 6.60162
     * Sig = 0.28, Call Option Price = 1.90759
     * Sig = 0.28, Put Option Price = 5.6205
     * r = 0.028, Call Option Price = 1.88157
     * r = 0.028, Put Option Price = 6.42816
     * S = 29, Call Option Price = 8.8713e-08
     * S = 29, Put Option Price = 34.7129
     * T = 0.58, Call Option Price = 4.58369
     * T = 0.58, Put Option Price = 6.63659
     * Sig = 0.29, Call Option Price = 2.02016
     * Sig = 0.29, Put Option Price = 5.73307
     * r = 0.029, Call Option Price = 1.8862
     * r = 0.029, Put Option Price = 6.41666
     * S = 30, Call Option Price = 3.11926e-07
     * S = 30, Put Option Price = 33.7129
     * T = 0.6, Call Option Price = 4.71666
     * T = 0.6, Put Option Price = 6.67035
     * Sig = 0.3, Call Option Price = 2.13337
     * Sig = 0.3, Put Option Price = 5.84628
     * r = 0.03, Call Option Price = 1.89085
     * r = 0.03, Put Option Price = 6.40517
     * S = 31, Call Option Price = 1.00545e-06
     * S = 31, Put Option Price = 32.7129
     * T = 0.62, Call Option Price = 4.84832
     * T = 0.62, Put Option Price = 6.70297
     * Sig = 0.31, Call Option Price = 2.24717
     * Sig = 0.31, Put Option Price = 5.96008
     * r = 0.031, Call Option Price = 1.8955
     * r = 0.031, Put Option Price = 6.3937
     * S = 32, Call Option Price = 2.99241e-06
     * S = 32, Put Option Price = 31.7129
     * T = 0.64, Call Option Price = 4.97872
     * T = 0.64, Put Option Price = 6.73448
     * Sig = 0.32, Call Option Price = 2.3615
     * Sig = 0.32, Put Option Price = 6.07441
     * r = 0.032, Call Option Price = 1.90016
     * r = 0.032, Put Option Price = 6.38224
     * S = 33, Call Option Price = 8.27565e-06
     * S = 33, Put Option Price = 30.7129
     * T = 0.66, Call Option Price = 5.10791
     * T = 0.66, Put Option Price = 6.76494
     * Sig = 0.33, Call Option Price = 2.47631
     * Sig = 0.33, Put Option Price = 6.18922
     * r = 0.033, Call Option Price = 1.90483
     * r = 0.033, Put Option Price = 6.37079
     * S = 34, Call Option Price = 2.13896e-05
     * S = 34, Put Option Price = 29.7129
     * T = 0.68, Call Option Price = 5.23593
     * T = 0.68, Put Option Price = 6.79439
     * Sig = 0.34, Call Option Price = 2.59156
     * Sig = 0.34, Put Option Price = 6.30447
     * r = 0.034, Call Option Price = 1.90951
     * r = 0.034, Put Option Price = 6.35935
     * S = 35, Call Option Price = 5.19359e-05
     * S = 35, Put Option Price = 28.713
     * T = 0.7, Call Option Price = 5.36283
     * T = 0.7, Put Option Price = 6.82288
     * Sig = 0.35, Call Option Price = 2.7072
     * Sig = 0.35, Put Option Price = 6.42012
     * r = 0.035, Call Option Price = 1.91419
     * r = 0.035, Put Option Price = 6.34792
     * S = 36, Call Option Price = 0.000119024
     * S = 36, Put Option Price = 27.713
     * T = 0.72, Call Option Price = 5.48864
     * T = 0.72, Put Option Price = 6.85043
     * Sig = 0.36, Call Option Price = 2.82322
     * Sig = 0.36, Put Option Price = 6.53613
     * r = 0.036, Call Option Price = 1.91888
     * r = 0.036, Put Option Price = 6.33651
     * S = 37, Call Option Price = 0.000258548
     * S = 37, Put Option Price = 26.7132
     * T = 0.74, Call Option Price = 5.6134
     * T = 0.74, Put Option Price = 6.87709
     * Sig = 0.37, Call Option Price = 2.93956
     * Sig = 0.37, Put Option Price = 6.65248
     * r = 0.037, Call Option Price = 1.92358
     * r = 0.037, Put Option Price = 6.32511
     * S = 38, Call Option Price = 0.000534403
     * S = 38, Put Option Price = 25.7134
     * T = 0.76, Call Option Price = 5.73715
     * T = 0.76, Put Option Price = 6.90289
     * Sig = 0.38, Call Option Price = 3.05622
     * Sig = 0.38, Put Option Price = 6.76913
     * r = 0.038, Call Option Price = 1.92829
     * r = 0.038, Put Option Price = 6.31372
     * S = 39, Call Option Price = 0.00105474
     * S = 39, Put Option Price = 24.714
     * T = 0.78, Call Option Price = 5.85991
     * T = 0.78, Put Option Price = 6.92786
     * Sig = 0.39, Call Option Price = 3.17315
     * Sig = 0.39, Put Option Price = 6.88606
     * r = 0.039, Call Option Price = 1.93301
     * r = 0.039, Put Option Price = 6.30234
     * S = 40, Call Option Price = 0.00199417
     * S = 40, Put Option Price = 23.7149
     * T = 0.8, Call Option Price = 5.98171
     * T = 0.8, Put Option Price = 6.95204
     * Sig = 0.4, Call Option Price = 3.29033
     * Sig = 0.4, Put Option Price = 7.00325
     * r = 0.04, Call Option Price = 1.93773
     * r = 0.04, Put Option Price = 6.29097
     * S = 41, Call Option Price = 0.00362244
     * S = 41, Put Option Price = 22.7165
     * T = 0.82, Call Option Price = 6.10259
     * T = 0.82, Put Option Price = 6.97544
     * Sig = 0.41, Call Option Price = 3.40775
     * Sig = 0.41, Put Option Price = 7.12067
     * r = 0.041, Call Option Price = 1.94247
     * r = 0.041, Put Option Price = 6.27962
     * S = 42, Call Option Price = 0.00633924
     * S = 42, Put Option Price = 21.7193
     * T = 0.84, Call Option Price = 6.22258
     * T = 0.84, Put Option Price = 6.99811
     * Sig = 0.42, Call Option Price = 3.52539
     * Sig = 0.42, Put Option Price = 7.23831
     * r = 0.042, Call Option Price = 1.94721
     * r = 0.042, Put Option Price = 6.26828
     * S = 43, Call Option Price = 0.010714
     * S = 43, Put Option Price = 20.7236
     * T = 0.86, Call Option Price = 6.34169
     * T = 0.86, Put Option Price = 7.02006
     * Sig = 0.43, Call Option Price = 3.64323
     * Sig = 0.43, Put Option Price = 7.35614
     * r = 0.043, Call Option Price = 1.95196
     * r = 0.043, Put Option Price = 6.25695
     * S = 44, Call Option Price = 0.0175282
     * S = 44, Put Option Price = 19.7304
     * T = 0.88, Call Option Price = 6.45996
     * T = 0.88, Put Option Price = 7.04132
     * Sig = 0.44, Call Option Price = 3.76125
     * Sig = 0.44, Put Option Price = 7.47416
     * r = 0.044, Call Option Price = 1.95671
     * r = 0.044, Put Option Price = 6.24563
     * S = 45, Call Option Price = 0.0278174
     * S = 45, Put Option Price = 18.7407
     * T = 0.9, Call Option Price = 6.5774
     * T = 0.9, Put Option Price = 7.06191
     * Sig = 0.45, Call Option Price = 3.87943
     * Sig = 0.45, Put Option Price = 7.59235
     * r = 0.045, Call Option Price = 1.96148
     * r = 0.045, Put Option Price = 6.23433
     * S = 46, Call Option Price = 0.0429083
     * S = 46, Put Option Price = 17.7558
     * T = 0.92, Call Option Price = 6.69404
     * T = 0.92, Put Option Price = 7.08185
     * Sig = 0.46, Call Option Price = 3.99777
     * Sig = 0.46, Put Option Price = 7.71069
     * r = 0.046, Call Option Price = 1.96625
     * r = 0.046, Put Option Price = 6.22303
     * S = 47, Call Option Price = 0.0644467
     * S = 47, Put Option Price = 16.7774
     * T = 0.94, Call Option Price = 6.8099
     * T = 0.94, Put Option Price = 7.10117
     * Sig = 0.47, Call Option Price = 4.11626
     * Sig = 0.47, Put Option Price = 7.82917
     * r = 0.047, Call Option Price = 1.97103
     * r = 0.047, Put Option Price = 6.21175
     * S = 48, Call Option Price = 0.0944125
     * S = 48, Put Option Price = 15.8073
     * T = 0.96, Call Option Price = 6.925
     * T = 0.96, Put Option Price = 7.11988
     * Sig = 0.48, Call Option Price = 4.23487
     * Sig = 0.48, Put Option Price = 7.94778
     * r = 0.048, Call Option Price = 1.97582
     * r = 0.048, Put Option Price = 6.20048
     * S = 49, Call Option Price = 0.135117
     * S = 49, Put Option Price = 14.848
     * T = 0.98, Call Option Price = 7.03936
     * T = 0.98, Put Option Price = 7.138
     * Sig = 0.49, Call Option Price = 4.3536
     * Sig = 0.49, Put Option Price = 8.06651
     * r = 0.049, Call Option Price = 1.98062
     * r = 0.049, Put Option Price = 6.18923
     * S = 50, Call Option Price = 0.189181
     * S = 50, Put Option Price = 13.9021
     * T = 0, Call Option Price = 0
     * T = 0, Put Option Price = 0.173097
     * Sig = 0, Call Option Price = 3.88601
     * Sig = 0, Put Option Price = 1.79948
     * r = 0, Call Option Price = 6.63718
     * r = 0, Put Option Price = 0
     * Call Option Delta: 0.594629
     * Put Option Delta: -0.356601
     * Delta values for call options with S ranging from 10 to 50:
     * S = 80, Delta = 0.215772
     * S = 81, Delta = 0.230011
     * S = 82, Delta = 0.244562
     * S = 83, Delta = 0.259392
     * S = 84, Delta = 0.274471
     * S = 85, Delta = 0.289765
     * S = 86, Delta = 0.305241
     * S = 87, Delta = 0.320867
     * S = 88, Delta = 0.33661
     * S = 89, Delta = 0.352438
     * S = 90, Delta = 0.368319
     * S = 91, Delta = 0.384223
     * S = 92, Delta = 0.400118
     * S = 93, Delta = 0.415977
     * S = 94, Delta = 0.431772
     * S = 95, Delta = 0.447475
     * S = 96, Delta = 0.463062
     * S = 97, Delta = 0.478508
     * S = 98, Delta = 0.493791
     * S = 99, Delta = 0.50889
     * S = 100, Delta = 0.523785
     * S = 101, Delta = 0.538459
     * S = 102, Delta = 0.552894
     * S = 103, Delta = 0.567076
     * S = 104, Delta = 0.580992
     * S = 105, Delta = 0.594629
     * S = 106, Delta = 0.607976
     * S = 107, Delta = 0.621025
     * S = 108, Delta = 0.633767
     * S = 109, Delta = 0.646196
     * S = 110, Delta = 0.658306
     * S = 111, Delta = 0.670094
     * S = 112, Delta = 0.681556
     * S = 113, Delta = 0.692691
     * S = 114, Delta = 0.703497
     * S = 115, Delta = 0.713974
     * S = 116, Delta = 0.724123
     * S = 117, Delta = 0.733946
     * S = 118, Delta = 0.743445
     * S = 119, Delta = 0.752624
     * S = 120, Delta = 0.761485
     * Delta Matrix:
     * 0.000363083 0.00051747 
     * 7.37317e-05 0.00106251 
     * Gamma Matrix:
     * 0.000295918 0.000393026 
     * 7.53759e-05 0.000718823 
     * Parameter h: 1e-05
     * Batch 1 Call Option Numerical Delta: 0.696851
     * Batch 1 Call Option Delta: 0.594629
     * Batch 1 Call Option Numerical Gamma: 0.013074
     * Batch 1 Call Option Gamma: 0.0124321
     * Perpetual American Option Call Price: 18.5035
     * Perpetual American Option Put Price: 3.03106
     * Delta values for Perpetual American options with S ranging from 80 to 120:
     * S = 80, Call Price = 6.64256
     * S = 80, Put Price = 21.9493
     * S = 81, Call Price = 6.91339
     * S = 81, Put Price = 20.318
     * S = 82, Call Price = 7.19174
     * S = 82, Put Price = 18.8257
     * S = 83, Call Price = 7.47772
     * S = 83, Put Price = 17.4592
     * S = 84, Call Price = 7.77143
     * S = 84, Put Price = 16.2064
     * S = 85, Call Price = 8.07301
     * S = 85, Put Price = 15.0569
     * S = 86, Call Price = 8.38255
     * S = 86, Put Price = 14.0009
     * S = 87, Call Price = 8.70018
     * S = 87, Put Price = 13.0299
     * S = 88, Call Price = 9.026
     * S = 88, Put Price = 12.1362
     * S = 89, Call Price = 9.36014
     * S = 89, Put Price = 11.3129
     * S = 90, Call Price = 9.7027
     * S = 90, Put Price = 10.5537
     * S = 91, Call Price = 10.0538
     * S = 91, Put Price = 9.85308
     * S = 92, Call Price = 10.4136
     * S = 92, Put Price = 9.20584
     * S = 93, Call Price = 10.7821
     * S = 93, Put Price = 8.60743
     * S = 94, Call Price = 11.1595
     * S = 94, Put Price = 8.05372
     * S = 95, Call Price = 11.546
     * S = 95, Put Price = 7.54093
     * S = 96, Call Price = 11.9416
     * S = 96, Put Price = 7.06565
     * S = 97, Call Price = 12.3464
     * S = 97, Put Price = 6.6248
     * S = 98, Call Price = 12.7605
     * S = 98, Put Price = 6.21556
     * S = 99, Call Price = 13.1842
     * S = 99, Put Price = 5.83537
     * S = 100, Call Price = 13.6174
     * S = 100, Put Price = 5.48192
     * S = 101, Call Price = 14.0603
     * S = 101, Put Price = 5.15308
     * S = 102, Call Price = 14.5131
     * S = 102, Put Price = 4.84691
     * S = 103, Call Price = 14.9758
     * S = 103, Put Price = 4.56167
     * S = 104, Call Price = 15.4486
     * S = 104, Put Price = 4.29572
     * S = 105, Call Price = 15.9316
     * S = 105, Put Price = 4.04761
     * S = 106, Call Price = 16.4249
     * S = 106, Put Price = 3.81598
     * S = 107, Call Price = 16.9286
     * S = 107, Put Price = 3.5996
     * S = 108, Call Price = 17.4429
     * S = 108, Put Price = 3.39733
     * S = 109, Call Price = 17.9678
     * S = 109, Put Price = 3.20813
     * S = 110, Call Price = 18.5035
     * S = 110, Put Price = 3.03106
     * S = 111, Call Price = 19.0501
     * S = 111, Put Price = 2.86523
     * S = 112, Call Price = 19.6078
     * S = 112, Put Price = 2.70985
     * S = 113, Call Price = 20.1765
     * S = 113, Put Price = 2.56416
     * S = 114, Call Price = 20.7566
     * S = 114, Put Price = 2.42748
     * S = 115, Call Price = 21.3481
     * S = 115, Put Price = 2.29919
     * S = 116, Call Price = 21.951
     * S = 116, Put Price = 2.1787
     * S = 117, Call Price = 22.5656
     * S = 117, Put Price = 2.06548
     * S = 118, Call Price = 23.192
     * S = 118, Put Price = 1.95904
     * S = 119, Call Price = 23.8302
     * S = 119, Put Price = 1.85891
     * S = 120, Call Price = 24.4804
     * S = 120, Put Price = 1.76467
     * Price Matrix:
     * 5.04766 50.2914 5.26808 49.151 
     * 5.04766 50.2914 5.04766 50.2914 
     */
}
// Question types and weights (/100):
// 
// 1) 'What is wrong with this code snippet?' -- 15
//
// 2) 'What is wrong with this code snippet?' -- 10
//
// 3) 'Will this code snippet compile? 
//     Why or why-not?'                       -- 15
// 
// 4) 'What does this code output?'           -- 10
// 
// Level 9 output for a given set of inputs:
//
// 5) Exact Method                            -- 20
//
// 6) Monte Carlo Method                      -- 15
//
// 7) Finite Difference Method                -- 15
// 
// Francis (Hung-Wei) Lin
//
// Source Code:
// 
#include "base/OptionParameters.hpp"
#include "base/PutCallParity.hpp"
#include "base/Mesh.hpp"
#include "base/OptionType.hpp"
#include "base/OptionFlavor.hpp"
#include "VanillaOption.hpp"
#include "PerpetualAmericanOption.hpp"
#include "AnalyticPricingEngine.hpp"
#include "Matrix.cpp"
#include "OptionMatrix.hpp"

#include <iostream>
#include <memory>
#include <map>

int main() {

    OptionMatrix testOptMatrix(2, 2);

    std::map<std::string, OptionParameters> optionBatches;

    // Batch 1 ~ 4
    optionBatches["Batch 1"] = OptionParameters(60, 65, 0.25, 0.3, 0.08, 0, EUROPEAN);
    optionBatches["Batch 2"] = OptionParameters(100, 100, 1.0, 0.2, 0.0, 0, EUROPEAN);

    double batchOnecallOptionPrice, batchOneputOptionPrice;
    double batchTwocallOptionPrice, batchTwoputOptionPrice;

    VanillaOption batchOnevanillaCallOption(optionBatches["Batch 1"].S,
                                            optionBatches["Batch 1"].K,
                                            optionBatches["Batch 1"].T,
                                            optionBatches["Batch 1"].sig,
                                            optionBatches["Batch 1"].r,
                                            optionBatches["Batch 1"].CostOfCarry,
                                            CALL,
                                            EUROPEAN);

    VanillaOption batchOnevanillaPutOption(optionBatches["Batch 1"].S,
                                           optionBatches["Batch 1"].K,
                                           optionBatches["Batch 1"].T,
                                           optionBatches["Batch 1"].sig,
                                           optionBatches["Batch 1"].r,
                                           optionBatches["Batch 1"].CostOfCarry,
                                           PUT,
                                           EUROPEAN);

    VanillaOption batchTwovanillaCallOption(optionBatches["Batch 2"].S,
                                            optionBatches["Batch 2"].K,
                                            optionBatches["Batch 2"].T,
                                            optionBatches["Batch 2"].sig,
                                            optionBatches["Batch 2"].r,
                                            optionBatches["Batch 2"].CostOfCarry,
                                            CALL,
                                            EUROPEAN);

    VanillaOption batchTwovanillaPutOption(optionBatches["Batch 2"].S,
                                           optionBatches["Batch 2"].K,
                                           optionBatches["Batch 2"].T,
                                           optionBatches["Batch 2"].sig,
                                           optionBatches["Batch 2"].r,
                                           optionBatches["Batch 2"].CostOfCarry,
                                           PUT,
                                           EUROPEAN);

    testOptMatrix.SetElement(1, 1, &batchOnevanillaCallOption);

    // Create Analytical Pricing Engines for options
    std::unique_ptr<AnalyticPricingEngine> batchOnecallPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchOneputPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchTwocallPricingEngine = std::make_unique<AnalyticPricingEngine>();
    std::unique_ptr<AnalyticPricingEngine> batchTwoputPricingEngine = std::make_unique<AnalyticPricingEngine>();

    // Set the Pricing Engines to the corresponding Options
    batchOnevanillaCallOption.setPricingEngine(std::move(batchOnecallPricingEngine));
    batchOnevanillaPutOption.setPricingEngine(std::move(batchOneputPricingEngine));
    batchTwovanillaCallOption.setPricingEngine(std::move(batchTwocallPricingEngine));
    batchTwovanillaPutOption.setPricingEngine(std::move(batchTwoputPricingEngine));

    // Get the Net Present Value (NPV) of Option by the calculation of Analytic Solution
    batchOnecallOptionPrice = batchOnevanillaCallOption.NPV();
    batchOneputOptionPrice = batchOnevanillaPutOption.NPV();
    batchTwocallOptionPrice = batchTwovanillaCallOption.NPV();
    batchTwoputOptionPrice = batchTwovanillaPutOption.NPV();

    std::cout << "Batch 1 Call Option Price: " << batchOnecallOptionPrice << std::endl;
    std::cout << "Batch 1 Put Option Price: " << batchOneputOptionPrice << std::endl;
    std::cout << "Batch 2 Call Option Price: " << batchTwocallOptionPrice << std::endl;
    std::cout << "Batch 2 Put Option Price: " << batchTwoputOptionPrice << std::endl;

    // Put Call Parity

    // Call and put prices from part a)
    std::map<std::string, double> callPrices = {
        {"Batch 1", batchOnecallOptionPrice},
        {"Batch 2", batchTwocallOptionPrice},
    };

    std::map<std::string, double> putPrices = {
        {"Batch 1", batchOneputOptionPrice},
        {"Batch 2", batchTwoputOptionPrice},
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

    // Matrix Pricers

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
                                              CALL,
                                              EUROPEAN);

    VanillaOption greeksTestVanillaPutOption(105,
                                             100,
                                             0.5,
                                             0.36,
                                             0.1,
                                             0,
                                             PUT,
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
                                 CALL,
                                 EUROPEAN);

        VanillaOption putOption(S,
                                100,
                                0.5,
                                0.36,
                                0.1,
                                0,
                                PUT,
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
                                                   CALL);

    PerpetualAemricanOption perpAmericanPutOption(110,
                                                  100,
                                                  0.1,
                                                  0.1,
                                                  0.02,
                                                  PUT);

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
                                                       CALL);

        PerpetualAemricanOption perpAmericanPutOption(S,
                                                      100,
                                                      0.1,
                                                      0.1,
                                                      0.02,
                                                      PUT);

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
}
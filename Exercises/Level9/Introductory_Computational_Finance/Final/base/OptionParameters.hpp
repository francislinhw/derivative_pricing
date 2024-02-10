// OptionParameters.hpp
#include <vector>
#include "base/OptionType.hpp"
#include "VanillaOption.hpp"
#include "PerpetualAmericanOption.hpp"
#include "AnalyticPricingEngine.hpp"
#include "Option.hpp"
#ifndef OPTION_PARAMETERS_HPP
#define OPTION_PARAMETERS_HPP

enum Greek {
    DELTA,
    GAMMA
};

// Define an enumeration for specific string literals
enum class OptionVariables {
    TimeToMaturity,    // Time to maturity
    Strike,    // Strike price
    Volatility,  // Volatility
    RiskFreeRate,    // Risk-free interest rate
    UnderlyingPrice,    // Underlying asset price
    CostOfCarry    // Underlying asset price
};

struct OptionParameters {
    double T;    // Time to maturity
    double K;    // Strike price
    double sig;  // Volatility
    double r;    // Risk-free interest rate
    double S;    // Underlying asset price
    double CostOfCarry;    // Underlying asset price
    OptionType Type;     // European / American

    // Default constructor
    OptionParameters() : S(0), K(0), T(0), sig(0), r(0), CostOfCarry(0), Type(EUROPEAN) {}

    OptionParameters(double S, double K, double T, double sig, double r, double b, OptionType Type)
        : S(S), K(K), T(T), sig(sig), r(r), CostOfCarry(b), Type(Type) {}
};

// Function to compute option prices for a range of S values
std::vector<OptionParameters> createMeshOptionParameters(const OptionParameters& params,
                                                         const std::vector<double>& meshValues,
                                                         OptionVariables targetVariable) {
    std::vector<OptionParameters> parameterSets;
    for (double movedValue : meshValues) {
        OptionParameters newParams = params; // Copy existing parameters

        // Update the target variable based on the mesh value
        switch (targetVariable) {
            case OptionVariables::UnderlyingPrice:
                newParams.S = movedValue;
                break;
            case OptionVariables::Strike:
                newParams.K = movedValue;
                break;
            case OptionVariables::TimeToMaturity:
                newParams.T = movedValue;
                break;
            case OptionVariables::Volatility:
                newParams.sig = movedValue;
                break;
            case OptionVariables::RiskFreeRate:
                newParams.r = movedValue;
                break;
            case OptionVariables::CostOfCarry:
                newParams.CostOfCarry = movedValue;
                break;
            default:
                break; // Handle other cases or error
        }

        parameterSets.push_back(newParams);
    }
    return parameterSets;
}

std::vector<std::vector<double>> computeOptionPricesMatrix(const std::vector<std::vector<OptionParameters>>& paramsMatrix) {
    std::vector<std::vector<double>> pricesMatrix;
    for (const auto& paramsRow : paramsMatrix) {
        std::vector<double> pricesRow;
        for (const auto& params : paramsRow) {
            std::unique_ptr<Option> callOption;
            std::unique_ptr<Option> putOption;
            if (params.Type == EUROPEAN) {
                callOption = std::make_unique<VanillaOption>(params.S,
                                                             params.K,
                                                             params.T,
                                                             params.sig,
                                                             params.r,
                                                             params.CostOfCarry,
                                                             true,
                                                             EUROPEAN);

                putOption = std::make_unique<VanillaOption>(params.S,
                                                            params.K,
                                                            params.T,
                                                            params.sig,
                                                            params.r,
                                                            params.CostOfCarry,
                                                            false,
                                                            EUROPEAN);
            } else { // We only have two types of options for now
                callOption = std::make_unique<PerpetualAemricanOption>(params.S,
                                                                       params.K,
                                                                       params.sig,
                                                                       params.r,
                                                                       params.CostOfCarry,
                                                                       true);

                putOption = std::make_unique<PerpetualAemricanOption>(params.S,
                                                                      params.K,
                                                                      params.sig,
                                                                      params.r,
                                                                      params.CostOfCarry,
                                                                      false);
            }

            std::unique_ptr<AnalyticPricingEngine> analyticCallEngine = std::make_unique<AnalyticPricingEngine>();
            std::unique_ptr<AnalyticPricingEngine> analyticPutEngine = std::make_unique<AnalyticPricingEngine>();
            callOption->setPricingEngine(std::move(analyticCallEngine));
            putOption->setPricingEngine(std::move(analyticPutEngine));

            pricesRow.push_back(callOption->NPV());
            pricesRow.push_back(putOption->NPV());
        }
        pricesMatrix.push_back(pricesRow);
    }
    return pricesMatrix;
}

std::pair<std::vector<double>, std::vector<double>>computeOptionPricesVector(const std::vector<OptionParameters>& paramsVector) {
    std::vector<double> callPricesVector;
    std::vector<double> putPricesVector;
        for (const auto& params : paramsVector) {
            std::unique_ptr<Option> callOption;
            std::unique_ptr<Option> putOption;
            if (params.Type == EUROPEAN) {
                callOption = std::make_unique<VanillaOption>(params.S,
                                                             params.K,
                                                             params.T,
                                                             params.sig,
                                                             params.r,
                                                             params.CostOfCarry,
                                                             true,
                                                             EUROPEAN);

                putOption = std::make_unique<VanillaOption>(params.S,
                                                            params.K,
                                                            params.T,
                                                            params.sig,
                                                            params.r,
                                                            params.CostOfCarry,
                                                            false,
                                                            EUROPEAN);
            } else { // We only have two types of options for now
                callOption = std::make_unique<PerpetualAemricanOption>(params.S,
                                                                       params.K,
                                                                       params.sig,
                                                                       params.r,
                                                                       params.CostOfCarry,
                                                                       true);

                putOption = std::make_unique<PerpetualAemricanOption>(params.S,
                                                                      params.K,
                                                                      params.sig,
                                                                      params.r,
                                                                      params.CostOfCarry,
                                                                      false);
            }

            std::unique_ptr<AnalyticPricingEngine> analyticCallEngine = std::make_unique<AnalyticPricingEngine>();
            std::unique_ptr<AnalyticPricingEngine> analyticPutEngine = std::make_unique<AnalyticPricingEngine>();
            callOption->setPricingEngine(std::move(analyticCallEngine));
            putOption->setPricingEngine(std::move(analyticPutEngine));

            callPricesVector.push_back(callOption->NPV());
            putPricesVector.push_back(putOption->NPV());
        }
    return std::make_pair(callPricesVector, putPricesVector);
}

// Function to compute a matrix of Greeks (Delta or Gamma)
std::vector<std::vector<double>> computeGreeksMatrix(const std::vector<std::vector<OptionParameters>>& paramsMatrix, Greek greekToCompute) {
    std::vector<std::vector<double>> greeksMatrix;
    for (const auto& paramsRow : paramsMatrix) {
        std::vector<double> greeksRow;
        for (const auto& params : paramsRow) {
            std::unique_ptr<Option> option;
            if (params.Type == EUROPEAN) {
                option = std::make_unique<VanillaOption>(params.S, params.K, params.T, params.sig, params.r, params.CostOfCarry, true, EUROPEAN);
            } else {
                option = std::make_unique<PerpetualAemricanOption>(params.S, params.K, params.sig, params.r, params.CostOfCarry, true);
            }
            std::unique_ptr<AnalyticPricingEngine> pricingEngine = std::make_unique<AnalyticPricingEngine>();
            option->setPricingEngine(std::move(pricingEngine));

            double greekValue = 0.0;
            if (greekToCompute == DELTA) {
                greekValue = option->delta();
            } else if (greekToCompute == GAMMA) {
                greekValue = option->gamma();
            }
            greeksRow.push_back(greekValue);
        }
        greeksMatrix.push_back(greeksRow);
    }
    return greeksMatrix;
}

    // Notes:
    // // Compute option prices for each S value
    // std::vector<double> callOptPrices;
    // std::vector<double> putOptPrices;
    // for (double S : underlyingValues) {
    //     VanillaOption vanillaCallOption(S,
    //                                     optionBatches["Batch 1"].K,
    //                                     optionBatches["Batch 1"].T,
    //                                     optionBatches["Batch 1"].sig,
    //                                     optionBatches["Batch 1"].r,
    //                                     optionBatches["Batch 1"].CostOfCarry,
    //                                     Call);
 
    //     VanillaOption vanillaPutOption(S,
    //                                    optionBatches["Batch 1"].K,
    //                                    optionBatches["Batch 1"].T,
    //                                    optionBatches["Batch 1"].sig,
    //                                    optionBatches["Batch 1"].r,
    //                                    optionBatches["Batch 1"].CostOfCarry,
    //                                    Put);

    //     std::unique_ptr<VanillaPricingEngine> analyticCallEngine = std::make_unique<VanillaPricingEngine>();
    //     std::unique_ptr<VanillaPricingEngine> analyticPutEngine = std::make_unique<VanillaPricingEngine>();
    //     vanillaCallOption.setPricingEngine(std::move(analyticCallEngine));
    //     vanillaPutOption.setPricingEngine(std::move(analyticPutEngine));

    //     callOptPrices.push_back(vanillaCallOption.NPV());
    //     putOptPrices.push_back(vanillaPutOption.NPV());
    // }
 
    // // Output the results
    // std::cout << "Option Prices:" << std::endl;
    // for (size_t i = 0; i < underlyingValues.size(); ++i) {
    //     std::cout << "S = " << underlyingValues[i] << ", Call Option Price = " << callOptPrices[i] << std::endl;
    //     std::cout << "S = " << underlyingValues[i] << ", Put Option Price = " << putOptPrices[i] << std::endl;
    // }

#endif // OPTION_PARAMETERS_HPP

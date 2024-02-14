#include "OptionMatrix.hpp"
#include "base/PutCallParity.hpp"
#include "AnalyticPricingEngine.hpp"

#include <cassert>
#include <algorithm>

OptionMatrix::OptionMatrix() : Matrix<Option*>() {}  // Use base class constructor

OptionMatrix::OptionMatrix(int row, int column) : Matrix<Option*>(row, column) {}  // Use base class constructor

OptionMatrix::OptionMatrix(const OptionMatrix& optMtx) : Matrix<Option*>(optMtx) {} // The base class copy constructor will handle copying the elements

OptionMatrix::~OptionMatrix() {
    // The base class destructor will handle the deletion
}

Option* OptionMatrix::getOption(int i, int j) {
    return *GetElement(i, j); // Dereference if GetElement returns Option**
}

void OptionMatrix::setPricingEngine(std::unique_ptr<PricingEngine> newEngine) {
    engine = std::move(newEngine); // Set the new pricing engine
}

// Matrix<double> OptionMatrix::priceAllOptions() {
//     // Iterate through the matrix and price all options
//     Matrix<double> optionPrices(DefaultRowSize(), DefaultColumnSize());
//     for (int i = 0; i < (DefaultRowSize()); ++i) {
//         for (int j = 0; j < (DefaultColumnSize()); ++j) {
//             // Allocate memory for a new double
//             optionPrices[i][j] = new double(0.0);
//             if (getOption(i, j)) {
//                 double price = 1.0;
//                 *(optionPrices[i][j]) = price;
//             } else {
//                 // Handle the null pointer case, maybe set to 0 or some error value
//                 double price = 1.0;
//                 *(optionPrices[i][j]) = price;// or std::numeric_limits<double>::quiet_NaN() for indicating an error
//             }
//         }
//     }
//     return optionPrices;
// }

// Matrix<double> OptionMatrix::priceAllOptions() {
//     Matrix<double> optionPrices(DefaultRowSize(), DefaultColumnSize());
//     for (int i = 0; i < optionPrices.RowSize(); ++i) {
//         for (int j = 0; j < optionPrices.ColumnSize(); ++j) {
//             Option* opt = getOption(i, j);
//             std::unique_ptr<PricingEngine> pricingEngine = std::make_unique<PricingEngine>(*engine);
//             opt->setPricingEngine(std::move(pricingEngine));
//             double testprice = opt->NPV();
//             double* price = new double(opt ? opt->NPV() : 0.0);
//             optionPrices.SetElement(i, j, *price); // SetElement will handle the pointer storage
//         }
//     }
//     return optionPrices;
// }

Matrix<double> OptionMatrix::priceAllOptions() {
    Matrix<double> optionPrices(DefaultRowSize(), DefaultColumnSize());
    for (int i = 0; i < optionPrices.RowSize(); ++i) {
        for (int j = 0; j < optionPrices.ColumnSize(); ++j) {
            Option* opt = getOption(i, j);
            if (opt) {
                // Clone the engine or use a specific concrete subclass instance
                // Assume `cloneEngine` is a method that properly clones your engine
                std::unique_ptr<PricingEngine> pricingEngine = cloneEngine(engine);
                
                // Set the cloned engine to the option
                opt->setPricingEngine(std::move(pricingEngine));
                
                // Directly calculate and store the price
                double price = opt->NPV();
                optionPrices.SetElement(i, j, price);
            } else {
                // Handle the null pointer case by setting the price to 0.0 or an error value
                optionPrices.SetElement(i, j, 0.0);
            }
        }
    }
    return optionPrices;
}

bool OptionMatrix::checkPutCallParity() {
    std::map<std::tuple<double, double, double, double>, std::vector<Option*>> optionsMap;

    // Populate the optionsMap with existing options for easy lookup
    for (int i = 0; i < DefaultRowSize(); ++i) {
        for (int j = 0; j < DefaultColumnSize(); ++j) {
            Option* opt = getOption(i, j);
            if (opt) {
                optionsMap[makeOptionKey(opt)].push_back(opt);
            }
        }
    }

    // Iterate through options to check put-call parity
    for (const auto& pair : optionsMap) {
        for (Option* opt : pair.second) {
            Option* correspondingOpt = findCorrespondingOption(optionsMap, opt, opt->Flavor() == CALL ? PUT : CALL);
            if (correspondingOpt) {
                // Check put-call parity logic here
                double price = opt->NPV();
                double correspondingPrice = correspondingOpt->NPV();
                OptionParameters params = OptionParameters(opt->UnderlyingPrice(),
                                                           opt->Strike(),
                                                           opt->TimeToMaturity(),
                                                           opt->Volatility(),
                                                           opt->Interest(),
                                                           opt->CostOfCarry(),
                                                           opt->Type());
                // Add parity check logic as in previous examples
                if (opt->Flavor() == CALL) {
                    std::cout << "Put-Call Parity Satisfied: " << (isParitySatisfied(params, price, correspondingPrice) ? "Yes" : "No") << std::endl;
                } else if (opt->Flavor() == PUT) {
                    std::cout << "Put-Call Parity Satisfied: " << (isParitySatisfied(params, correspondingPrice, price) ? "Yes" : "No") << std::endl;
                }
                
            }
        }
    }

    return true;
}

// A function to create a key from option parameters for matching
std::tuple<double, double, double, double> OptionMatrix::makeOptionKey(const Option* option) {
    // Assuming Option class has methods to get these parameters
    return std::make_tuple(option->Strike(), option->Interest(),
                           option->TimeToMaturity(), option->UnderlyingPrice());
}

// A function to find a corresponding option
Option* OptionMatrix::findCorrespondingOption(
    const std::map<std::tuple<double, double, double, double>,
    std::vector<Option*>>& optionsMap,
    const Option* option,
    OptionFlavor desiredFlavor) 
{
    auto key = makeOptionKey(option);
    auto it = optionsMap.find(key);
    if (it != optionsMap.end()) {
        for (auto* opt : it->second) {
            if (opt->Flavor() == desiredFlavor) { // Assuming Option class has a getType() method
                return opt;
            }
        }
    }
    return nullptr;
}

// returns a unique_ptr to a cloned engine
std::unique_ptr<PricingEngine> OptionMatrix::cloneEngine(const std::unique_ptr<PricingEngine>& engine) {
    // if (dynamic_cast<AnalyticPricingEngine*>(engine.get()) != nullptr) {
    //     return std::make_unique<AnalyticPricingEngine>(*dynamic_cast<AnalyticPricingEngine*>(engine.get()));
    // } else if (dynamic_cast<AnalyticPricingEngine*>(engine.get()) != nullptr) {
    //     return std::make_unique<AnalyticPricingEngine>(*dynamic_cast<AnalyticPricingEngine*>(engine.get()));
    // }
    // // Add more cases as needed
    // throw std::invalid_argument("Unsupported engine type");
    if (auto concreteEngine1 = dynamic_cast<AnalyticPricingEngine*>(engine.get())) {
        return std::make_unique<AnalyticPricingEngine>(*concreteEngine1);
    } else if (auto concreteEngine2 = dynamic_cast<AnalyticPricingEngine*>(engine.get())) {
        return std::make_unique<AnalyticPricingEngine>(*concreteEngine2);
    }
    // Add more conditions for other engine types as necessary
    else {
        // Handle the case where the engine type is unknown or not handled
        throw std::runtime_error("Unsupported engine type for cloning");
    }
}

#include "OptionMatrix.hpp"

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

// Matrix<double> OptionMatrix::priceAllOptions() {
//     // Iterate through the matrix and price all options
//     Matrix<double> optionPrices(DefaultRowSize(), DefaultColumnSize());
//     for (int i = 0; i < DefaultRowSize(); ++i) {
//         for (int j = 0; j < DefaultColumnSize(); ++j) {
//             if (GetElement(i, j)) {
//                 optionPrices[i][j] = getOption(i, j)->NPV();
//             } else {
//                 // Handle the null pointer case, maybe set to 0 or some error value
//                 optionPrices[i][j] = 0; // or std::numeric_limits<double>::quiet_NaN() for indicating an error
//             }
//         }
//     }
//     return optionPrices;
// }

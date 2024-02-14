#ifndef OPTION_MATRIX_HPP
#define OPTION_MATRIX_HPP

#include "Option.hpp"
#include "base/OptionBasicParas.hpp"
#include "PricingEngine.hpp"
#include "Matrix.hpp"
#include "base/OptionFlavor.hpp"

#include <map>
#include <memory>

class OptionMatrix : public Matrix<Option*> {
    public:
        // This is the default option pricing engine if no engine set in Option
        std::unique_ptr<PricingEngine> engine;

        // Constructor, destructor, and other member functions
        OptionMatrix();  // Default Constructor
        OptionMatrix(int row, int column);  // Constructor with size
        OptionMatrix(const OptionMatrix& optMtx);  // Copy constructor
        ~OptionMatrix();  // Destructor
        std::unique_ptr<PricingEngine> cloneEngine(const std::unique_ptr<PricingEngine>& engine);
        
        Option* getOption(int i, int j);
        void setPricingEngine(std::unique_ptr<PricingEngine> newEngine);

        // void insertOption(T* option, size_t row, size_t column) {
        //     // Insert option into the matrix at specified location
        // }

        // Price() method for each option in the matrix, and return a vector.
        Matrix<double> priceAllOptions();
        bool checkPutCallParity();

        // Assistant Type Function
        Option* findCorrespondingOption(
            const std::map<std::tuple<double, double, double, double>,
            std::vector<Option*>>& optionsMap,
            const Option* option,
            OptionFlavor desiredFlavor);

        std::tuple<double, double, double, double> makeOptionKey(const Option* option);
        // Create an interface (or multiple interfaces) to generate the parameter matrices.
        // i.e., one interface can be from 

        // i) console,
        // Matrix<OptionParameters> generateOptions();
        // ii) another hardcoded,
        // Matrix<OptionParameters> generateOptionsFromExistingOption();
        // iii) another from a file,
        // Matrix<OptionParameters> generateOptionsFromFiles();
        // iv) another random numbers,
        // Matrix<OptionParameters> generateOptionsRandomly();
        // v) another a Mesh, etc.
        // Matrix<OptionParameters> generateOptionsMesh();


    /* Notes: 
     *
     * The OptionMatrixPricer can have a generic pricing method,
     * that takes a reference to your Option base class as its parameter.
     * It would then invoke the virtual.
     */

};

#endif // OPTION_MATRIX_HPP
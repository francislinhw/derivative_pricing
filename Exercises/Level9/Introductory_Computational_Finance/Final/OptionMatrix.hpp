#ifndef OPTION_MATRIX_HPP
#define OPTION_MATRIX_HPP

// #include "base/OptionParameters.hpp"
#include "Matrix.hpp"
#include "Option.hpp"

class OptionMatrix : public Matrix<Option*> {
    public:
        // Constructor, destructor, and other member functions
        OptionMatrix();  // Default Constructor
        OptionMatrix(int row, int column);  // Constructor with size
        OptionMatrix(const OptionMatrix& optMtx);  // Copy constructor
        ~OptionMatrix();  // Destructor
        
        Option* getOption(int i, int j);

        // void insertOption(T* option, size_t row, size_t column) {
        //     // Insert option into the matrix at specified location
        // }

        // T* getOption(size_t row, size_t column) const {
        //     // Retrieve option from the matrix
        // }

        // Price() method for each option in the matrix, and return a vector.
        // Matrix<double> priceAllOptions();

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
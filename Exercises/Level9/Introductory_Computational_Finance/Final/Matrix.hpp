#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

template <typename T>
class Matrix {
    private:
        int rowSize;
        int columnSize;
        static int defaultRowSize; // Static member for default size
        static int defaultColumnSize; // Static member for default size
        std::vector<std::vector<T*>> m_data; // 2D vector to store pointers to options

    public:
        static int DefaultRowSize();
        static void DefaultRowSize(int size);
        static int DefaultColumnSize();
        static void DefaultColumnSize(int size);
        static void DefaultMatrixSize(int row, int column);
        static std::vector<int> DefaultMatrixSize();
    
        Matrix();  // Default Constructor
        Matrix(int row, int column);  // Constructor with size
        Matrix(const Matrix& mtx);  // Copy constructor
        ~Matrix();  // Destructor

        int RowSize() const;  // Size of the array
        int ColumnSize() const;  // Size of the array
        void SetElement(int row, int column, const T& p);  // Set element at index
        T* GetElement(int row, int column) const;  // Get element at index
        std::vector<T*>& operator[](int rowIndex);  // Overloaded [] operator
        const std::vector<T*>& operator[](int index) const;  // Overloaded [] operator for const objects
        Matrix& operator=(const Matrix& source);  // Overloaded = operator for const objects

};

#include "Matrix.cpp"

#endif
#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "Matrix.hpp"

template <typename T>
int Matrix<T>::defaultRowSize = 2;

template <typename T>
int Matrix<T>::defaultColumnSize = 2;

template <typename T>
int Matrix<T>::DefaultRowSize() { return defaultRowSize; }

template <typename T>
void Matrix<T>::DefaultRowSize(int size) { defaultRowSize = size; }

template <typename T>
int Matrix<T>::DefaultColumnSize() { return defaultColumnSize; }

template <typename T>
void Matrix<T>::DefaultColumnSize(int size) { defaultColumnSize = size; }

template <typename T>
void Matrix<T>::DefaultMatrixSize(int row, int column) { 
    defaultColumnSize = column;
    defaultRowSize = row;
}

template <typename T>
std::vector<int> Matrix<T>::DefaultMatrixSize() { 
    return std::vector<int> (defaultRowSize, defaultColumnSize);
}

template <typename T>
Matrix<T>::Matrix() : rowSize(defaultRowSize), columnSize(defaultColumnSize) {
    m_data.resize(defaultRowSize); // Resize the outer vector to hold 'rows' number of vectors
    for (int i = 0; i < defaultRowSize; ++i) {
        m_data[i].resize(defaultColumnSize); // Resize each inner vector to hold 'columns' number of T* pointers
        for (int j = 0; j < defaultColumnSize; ++j) {
            m_data[i][j] = nullptr; // Allocate memory for a T object and store its address
        }
    }
}


// template <typename T>
// Matrix<T>::Matrix(int row, int column) : rowSize(row), columnSize(column) {
//     m_data = new T*[rowSize];
//     for (int i = 0; i < rowSize; ++i) {
//         m_data[i] = new T[columnSize];
//     }
// }

// template <typename T>
// Matrix<T>::Matrix(int rows, int columns) : rowSize(rows), columnSize(columns), m_data(rows) {
//     for (int i = 0; i < rows; ++i) {
//         m_data[i].resize(columns);
//         for (int j = 0; j < columns; ++j) {
//             m_data[i][j] = new T(); // Initialize each element to point to a new T object
//         }
//     }
// }

template <typename T>
Matrix<T>::Matrix(int rows, int columns) : rowSize(rows), columnSize(columns) {
    m_data.resize(rows); // Resize the outer vector to hold 'rows' number of vectors
    for (int i = 0; i < rows; ++i) {
        m_data[i].resize(columns); // Resize each inner vector to hold 'columns' number of T* pointers
        for (int j = 0; j < columns; ++j) {
            m_data[i][j] = nullptr; // Allocate memory for a T object and store its address
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& mtx) : rowSize(mtx.rowSize), columnSize(mtx.columnSize) {
    m_data.resize(mtx.rowSize); // Resize the outer vector to hold 'rows' number of vectors
    for (int i = 0; i < rowSize; ++i) {
        // Initialize each element to a default-constructed T
        for (int j = 0; j < mtx.columnSize; ++j) {
            m_data[i][j] = mtx.m_data[i][j];
        }
    }
}

// template <typename T>
// Matrix<T>::~Matrix() {
//     // No need to manually delete if m_data is a std::vector of std::vector
// }

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < columnSize; ++j) {
            delete m_data[i][j]; // Delete each T object
        }
    }
}

template <typename T>
int Matrix<T>::RowSize() const {
    return rowSize;
}

template <typename T>
int Matrix<T>::ColumnSize() const {
    return columnSize;
}

template <typename T>
void Matrix<T>::SetElement(int row, int column, const T& value) {
    // Delete the old value if it exists
    delete m_data[row][column];

    // Allocate memory for the new value and assign it
    // m_data[row][column] = new T(value);
    m_data[row][column] = new T(value);
}

template <typename T>
T* Matrix<T>::GetElement(int row, int column) const {
    // Return a reference to the value pointed by the pointer in the matrix
    return m_data[row][column];
}

// template <typename T>
// T* Matrix<T>::operator[](int index) {
//     if (index < 0 || index >= rowSize) {
//         throw std::out_of_range("Index out of bounds");
//     }
//     return m_data[index];
// }

template <typename T>
std::vector<T*>& Matrix<T>::operator[](int rowIndex) {
    return m_data[rowIndex];
}

template <typename T>
const std::vector<T*>& Matrix<T>::operator[](int index) const {
    if (index < 0 || index >= rowSize) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[index];
}


template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& source) {
    if (this == &source) {
        return *this;
    }

    delete[] m_data;
    rowSize = source.rowSize;
    columnSize = source.columnSize;
    m_data = new T[rowSize][columnSize];
    for (int i = 0; i < rowSize; ++i) {
        // Initialize each element to a default-constructed T
        for (int j = 0; j < columnSize; ++j) {
            m_data[i][j] = source.m_data[i][j];
        }
    }
    return *this;
}

#endif
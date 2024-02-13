#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <type_traits>

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

// template <typename T>
// Matrix<T>::~Matrix() {
//     for (int i = 0; i < rowSize; ++i) {
//         for (int j = 0; j < columnSize; ++j) {
//             delete m_data[i][j]; // Delete each T object
//         }
//     }
// }

template <typename T>
Matrix<T>::~Matrix() {
    for (auto& row : m_data) {
        for (auto& elem : row) {
            delete elem;
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


// template <typename T>
// Matrix<T>& Matrix<T>::operator=(const Matrix<T>& source) {
//     if (this == &source) {
//         return *this;
//     }
//     rowSize = source.rowSize;
//     columnSize = source.columnSize;
//     
//     // Resize the vector to match the source dimensions
//     for (int i = 0; i < rowSize; ++i) {
//         for (int j = 0; j < columnSize; ++j) {
//             // If T is a pointer type, you need to clone or copy the object
//             // If T is a value type (e.g., double or int), you can directly assign
// 
//             // C++ 17
//             // if constexpr (std::is_pointer_v<T>) {
//             //     // Assuming T is a pointer type and the pointed type has a clone method or copy constructor
//             //     m_data[i][j] = new typename std::remove_pointer<T>::type(*source.m_data[i][j]);
//             // } else {
//             //     // For non-pointer types, a simple assignment is sufficient
//             //     m_data[i][j] = source.m_data[i][j];
//             // }
// 
//             // C++ 14
//             if (std::is_pointer<T>::value) {
//                 // T is a pointer type
//                 // Perform deep copy
//                 m_data[i][j] = new typename std::remove_pointer<T>::type(*source.m_data[i][j]);
//             } else {
//                 // T is not a pointer type
//                 // Perform shallow copy
//                 m_data[i][j] = source.m_data[i][j];
//             }
//         }
//     }
//     return *this;
// }

//template <typename T>
// Matrix<T>& Matrix<T>::operator=(const Matrix<T>& source) {
//     if (this == &source) {
//         return *this;
//     }
// 
//     // Clear existing data to prevent memory leaks
//     for (auto& row : m_data) {
//         for (auto& elem : row) {
//             delete elem;  // This assumes T is a pointer type with dynamic allocation
//         }
//     }
// 
//     rowSize = source.rowSize;
//     columnSize = source.columnSize;
// 
//     // Resize the vector to match the source dimensions
//     m_data.resize(rowSize);
//     for (int i = 0; i < rowSize; ++i) {
//         m_data[i].resize(columnSize);
//         for (int j = 0; j < columnSize; ++j) {
//             // If T is a pointer type, you need to clone or copy the object
//             // If T is a value type (e.g., double or int), you can directly assign
//             if (std::is_pointer<T>::value) {
//                 // T is a pointer type
//                 // Perform deep copy (assuming a proper copy constructor or clone method exists)
//                 // Replace 'T(*source.m_data[i][j])' with your actual clone/copy method as needed
//                 m_data[i][j] = source.m_data[i][j] ? new T(*source.m_data[i][j]) : nullptr;
//                 SetElement(i, j, &m_data[i][j]);
//             } else {
//                 // T is not a pointer type
//                 // Perform shallow copy
//                 SetElement(i, j, &source.m_data[i][j]);
//             }
//         }
//     }
//     return *this;
// }

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& source) {
    if (this == &source) {
        return *this;
    }

    // Clear existing data to prevent memory leaks
    for (auto& row : m_data) {
        for (auto& elem : row) {
            delete elem; // Assuming T is a dynamically allocated object
        }
    }

    rowSize = source.rowSize;
    columnSize = source.columnSize;

    // Resize the vector to match the source dimensions
    m_data.resize(rowSize);
    for (int i = 0; i < rowSize; ++i) {
        m_data[i].resize(columnSize);
        for (int j = 0; j < columnSize; ++j) {
            // Since m_data is a vector of vector of T*, we need to allocate new memory for each T
            if (source.m_data[i][j] != nullptr) {
                // Perform deep copy (assuming T has a copy constructor or clone method)
                m_data[i][j] = new T(*(source.m_data[i][j]));
            } else {
                // If the source pointer is null, just set the destination to null
                m_data[i][j] = nullptr;
            }
        }
    }
    return *this;
}


#endif
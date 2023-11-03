// vector_operations.h
#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <cassert>

#include "operations.h"
#include "vector_operations.h"
#include "../structures/vector.h"
#include "../structures/matrix.h"


template <typename T>
Matrix<T> elementWiseOperation(const Matrix<T>& matrix1, const Matrix<T>& matrix2, T (*operation)(const T&, const T&)) {

    if (matrix1.n_rows == 1 && matrix1.n_cols == matrix2.n_cols) {
        Matrix<T> result;

        for (size_t i = 0; i < matrix2.n_rows; ++i) {
            Vector<T> rowResult = elementWiseOperation(matrix1.row_vectors[0], matrix2.row_vectors[i], operation);
            result.appendVectorToRow(rowResult);
        }

        result.computeColVectors();
        return result;
    } 
    
    if (matrix2.n_rows == 1 && matrix2.n_cols == matrix1.n_cols) {
        Matrix<T> result;

        for (size_t i = 0; i < matrix1.n_rows; ++i) {
            Vector<T> rowResult = elementWiseOperation(matrix1.row_vectors[i], matrix2.row_vectors[0], operation);
            result.appendVectorToRow(rowResult);
        }

        result.computeColVectors();
        return result;
    }

    assert(matrix1.n_rows == matrix2.n_rows && matrix1.n_cols == matrix2.n_cols);

    Matrix<T> result;

    for (size_t i = 0; i < matrix1.n_rows; ++i) {
        Vector<T> rowResult = elementWiseOperation(matrix1.row_vectors[i], matrix2.row_vectors[i], operation);
        result.appendVectorToRow(rowResult);
    }

    result.computeColVectors();
    return result;
}


template <typename T>
Matrix<T> add(const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    return elementWiseOperation(matrix1, matrix2, addition);
}

template <typename T>
Matrix<T> subtract(const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    return elementWiseOperation(matrix1, matrix2, subtraction);
}

template <typename T>
Matrix<T> multiply(const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    return elementWiseOperation(matrix1, matrix2, multiplication);
}

template <typename T>
Matrix<T> divide(const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
    return elementWiseOperation(matrix1, matrix2, division);
}


template <typename T>
Matrix<T> dot(const Matrix<T>& matrix1, const Matrix<T>& matrix2) {

    assert(matrix1.n_cols == matrix2.n_rows);

    Matrix<T> result;

    for (size_t i = 0; i < matrix1.n_rows; ++i) {
        Vector<T> tempVector;
        for (size_t j = 0; j < matrix2.n_cols; ++j) {
            tempVector.append(dot(matrix1.row_vectors[i], matrix2.col_vectors[j]));
        }
        result.appendVectorToRow(tempVector);
    }

    result.computeColVectors();
    return result;
}


#endif // MATRIX_OPERATIONS_H

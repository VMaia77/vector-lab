#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cassert>
#include <vector>

#include "vector.h"
#include "../math/vector_operations.h"

// Declaration

template <typename T>
class Matrix {
public:

    Matrix();
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    Matrix(std::initializer_list<Vector<T>> list);
    Matrix(const std::vector<Vector<T>> vectorList);
    ~Matrix();

    size_t n_rows;
    size_t n_cols;

    std::vector<Vector<T>> row_vectors;
    std::vector<Vector<T>> col_vectors;

    void computeRowVectors();
    void computeColVectors();
    void transpose();

    void appendVectorToRow(const Vector<T> vector);
    void appendVectorToCol(const Vector<T> vector);

};


// Definition

template <typename T>
Matrix<T>::Matrix() : n_rows{0}, n_cols{0} {}


template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list) {
    size_t commonSize = 0;
    n_rows = list.size();

    for (const std::initializer_list<T>& values_list : list) {
        Vector<T> VectorI(values_list);
        row_vectors.push_back(VectorI);

        if (commonSize == 0) {
            commonSize = VectorI.size;
        } else {
            assert(VectorI.size == commonSize);
        }
    }

    n_cols = commonSize;
    computeColVectors();
}


template <typename T>
Matrix<T>::Matrix(std::initializer_list<Vector<T>> list) {
    size_t commonSize = 0;
    n_rows = list.size();

    for (const Vector<T>& vector : list) {
        row_vectors.push_back(vector);

        if (commonSize == 0) {
            commonSize = vector.size;
        } else {
            assert(vector.size == commonSize);
        }
    }

    n_cols = commonSize;
    computeColVectors();
}


template <typename T>
Matrix<T>::Matrix(const std::vector<Vector<T>> vectorList) {
    size_t commonSize = 0;
    n_rows = vectorList.size();

    // Set the row_vectors directly to the input vectorList
    row_vectors = vectorList;

    // Calculate the number of columns and check for common sizes
    for (const Vector<T>& vector : vectorList) {
        if (commonSize == 0) {
            commonSize = vector.size;
        } else {
            assert(vector.size == commonSize);
        }
    }

    n_cols = commonSize;
    computeColVectors();
}


template <typename T>
void Matrix<T>::computeRowVectors() {

    row_vectors.clear();

    for (int i = 0; i < col_vectors[0].size; ++i) {

        Vector<T> vectorInitialization;

        for (const Vector<T>& vector : col_vectors) {
            
            vectorInitialization.append(vector[i]);
        }

        row_vectors.push_back(vectorInitialization);
    }
}


template <typename T>
void Matrix<T>::computeColVectors() {

    col_vectors.clear();

    for (int i = 0; i < row_vectors[0].size; ++i) {

        Vector<T> vectorInitialization;

        for (const Vector<T>& vector : row_vectors) {
            
            vectorInitialization.append(vector[i]);
        }

        col_vectors.push_back(vectorInitialization);
    }
}


template <typename T>
void Matrix<T>::transpose() {
    // Swap the row_vectors with col_vectors
    std::swap(row_vectors, col_vectors);
}


template <typename T>
void Matrix<T>::appendVectorToRow(const Vector<T> vector) {
    assert(vector.size == n_cols || n_rows == 0);
    row_vectors.push_back(vector);
    n_rows++;
    if (n_cols == 0) {
        n_cols = vector.size;
    }
}

template <typename T>
void Matrix<T>::appendVectorToCol(const Vector<T> vector) {
    assert(vector.size == n_rows || n_cols == 0);
    col_vectors.push_back(vector);
    n_cols++;
    if (n_rows == 0) {
        n_rows = vector.size;
    }
}


template <typename T>
Matrix<T>::~Matrix() {}


#endif // MATRIX_H

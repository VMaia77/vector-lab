#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <cassert>
#include "vector.h"
#include "../math/vector_operations.h"

// Declaration

template <typename T>
class Matrix {
public:

    Matrix();
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    Matrix(std::initializer_list<Vector<T>> list);
    ~Matrix();

    std::vector<Vector<T>> row_vectors;
    std::vector<Vector<T>> col_vectors;

    void computeColVectors();
    void transpose();

};


// Definition

template <typename T>
Matrix<T>::Matrix() {}


template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list) {

    size_t commonSize = 0;

    for (const std::initializer_list<T>& values_list : list) {
        Vector<T> VectorI(values_list);
        row_vectors.push_back(VectorI);

        if (commonSize == 0) {
            commonSize = VectorI.size;
        } else {
            assert(VectorI.size == commonSize);
        }
    }

    computeColVectors();
}


template <typename T>
Matrix<T>::Matrix(std::initializer_list<Vector<T>> list) {
    
    size_t commonSize = 0;

    for (const Vector<T>& vector : list) {
        row_vectors.push_back(vector);

        if (commonSize == 0) {
            commonSize = vector.size;
        } else {
            assert(vector.size == commonSize);
        }
    }

    computeColVectors();
}


template <typename T>
void Matrix<T>::computeColVectors() {

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
Matrix<T>::~Matrix() {}


#endif // MATRIX_H

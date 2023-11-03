// vector_operations.h
#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

#include <cassert>

#include "../structures/vector.h"
#include "operations.h"


template <typename T>
Vector<T> elementWiseOperation(const Vector<T>& vector1, const Vector<T>& vector2, T (*operation)(const T&, const T&)) {
    assert(vector1.size == vector2.size);

    Vector<T> result(vector1.size);

    for (int i = 0; i < vector1.size; ++i) {
        result[i] = operation(vector1[i], vector2[i]);
    }

    return result;
}

template <typename T>
Vector<T> vectorInitialization(int size, const T& value) {
    Vector<T> result(size);
    result.setAll(value);
    return result;
}

template <typename T>
Vector<T> add(const Vector<T>& vector1, const Vector<T>& vector2) {
    return elementWiseOperation(vector1, vector2, addition);
}

template <typename T>
Vector<T> add(const T& scalar, const Vector<T>& vector) {
    Vector<T> scalarVector = vectorInitialization(vector.size, scalar);
    return elementWiseOperation(scalarVector, vector, addition);
}

template <typename T>
Vector<T> add(const Vector<T>& vector, const T& scalar) {
    Vector<T> scalarVector = vectorInitialization(vector.size, scalar);
    return elementWiseOperation(vector, scalarVector, addition);
}

template <typename T>
Vector<T> subtract(const Vector<T>& vector1, const Vector<T>& vector2) {
    return elementWiseOperation(vector1, vector2, subtraction);
}

template <typename T>
Vector<T> subtract(const T& scalar, const Vector<T>& vector) {
    Vector<T> scalarVector = vectorInitialization(vector.size, scalar);
    return elementWiseOperation(scalarVector, vector, subtraction);
}

template <typename T>
Vector<T> subtract(const Vector<T>& vector, const T& scalar) {
    Vector<T> scalarVector = vectorInitialization(vector.size, scalar);
    return elementWiseOperation(vector, scalarVector, subtraction);
}

template <typename T>
Vector<T> multiply(const Vector<T>& vector1, const Vector<T>& vector2) {
    return elementWiseOperation(vector1, vector2, multiplication);
}

template <typename T>
Vector<T> multiply(const T& scalar, const Vector<T>& vector) {
    Vector<T> scalarVector = vectorInitialization(vector.size, scalar);
    return elementWiseOperation(scalarVector, vector, multiplication);
}

template <typename T>
Vector<T> multiply(const Vector<T>& vector, const T& scalar) {
    Vector<T> scalarVector = vectorInitialization(vector.size, scalar);
    return elementWiseOperation(vector, scalarVector, multiplication);
}

template <typename T>
Vector<T> divide(const Vector<T>& vector1, const Vector<T>& vector2) {
    return elementWiseOperation(vector1, vector2, division);
}

template <typename T>
Vector<T> divide(const T& scalar, const Vector<T>& vector) {
    Vector<T> scalarVector = vectorInitialization(vector.size, scalar);
    return elementWiseOperation(scalarVector, vector, division);
}

template <typename T>
Vector<T> divide(const Vector<T>& vector, const T& scalar) {
    Vector<T> scalarVector = vectorInitialization(vector.size, scalar);
    return elementWiseOperation(vector, scalarVector, division);
}


template <typename T>
T dot(const Vector<T>& vector1, const Vector<T>& vector2) {
    assert(vector1.size == vector2.size);

    T result = T(0);

    for (int i = 0; i < vector1.size; ++i) {
        result += vector1[i] * vector2[i];
    }

    return result;
}


#endif // VECTOR_OPERATIONS_H

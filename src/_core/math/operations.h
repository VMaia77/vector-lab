#ifndef OPERATIONS_H
#define OPERATIONS_H


template <typename T>
T addition(const T& a, const T& b) {
    return a + b;
}

template <typename T>
T subtraction(const T& a, const T& b) {
    return a - b;
}

template <typename T>
T multiplication(const T& a, const T& b) {
    return a * b;
}

template <typename T>
T division(const T& a, const T& b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0;
    }
}


#endif // OPERATIONS_H
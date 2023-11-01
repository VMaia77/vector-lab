#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
#include <vector>


// Declaration

template <typename T>
class Vector {
public:

    Vector();
    Vector(int size);
    Vector(std::initializer_list<T> list);
    Vector(const std::vector<T> vec);
    ~Vector();

    int size{0};
    std::vector<T> data;

    T& operator[](int index);
    const T& operator[](int index) const;

    void setValues(std::initializer_list<T> list);
    void setAll(T value);

    void append(const T& value);

};


// Definition

template <typename T>
Vector<T>::Vector() {
    data = std::vector<T>(size);
}

template <typename T>
Vector<T>::Vector(int size) : size{size} {
    data = std::vector<T>(size);
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : data{list}, size{static_cast<int>(list.size())} {
}

template <typename T>
Vector<T>::Vector(const std::vector<T> vec) {
    data = vec;
    size = static_cast<int>(vec.size());
}

template <typename T>
Vector<T>::~Vector() {}

template <typename T>
T& Vector<T>::operator[](int index) {
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    return data[index];
}

template <typename T>
void Vector<T>::setValues(std::initializer_list<T> list) {
    if (list.size() <= size) {
        std::copy(list.begin(), list.end(), data.begin());
    } else {
        std::cerr << "Initializer list size exceeds the vector's size. Values not set." << std::endl;
    }
}

template <typename T>
void Vector<T>::setAll(T value) {
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
}

template <typename T>
void Vector<T>::append(const T& value) {
    data.push_back(value);
    size = static_cast<int>(data.size());
}


#endif // VECTOR_H

#include "test.h"

void test() {

    Vector<int> vectorInt(5); 
    Vector<double> vectorDouble(5);

    std::cout << "vectorInt types" << std::endl;
    for (const auto& element : vectorInt.data) {
        std::cout << typeid(element).name() << ' ';
    }
    std::cout << std::endl;

    std::cout << "vectorDouble types" << std::endl;
    for (const auto& element : vectorDouble.data) {
        std::cout << typeid(element).name() << ' ';
    }
    std::cout << std::endl;

    std::cout << "List initialization" << std::endl;
    Vector<int> myVector({1, 2, 3, 4, 5});
    for (const auto& element : myVector.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    
    std::cout << "Set values initialization" << std::endl;
    myVector.setValues({10, 20, 30, 40, 50});
    for (const auto& element : myVector.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    
    std::cout << "SetAll to 10" << std::endl;
    myVector.setAll(10);

    int firstElement = myVector[0]; 
    std::cout << "first element: " << firstElement << std::endl;
    std::cout << std::endl;

    double dotproduct = dotProduct(myVector, myVector);
    std::cout << "dot product: " << dotproduct << std::endl;

    Vector<int> v = add(myVector, myVector);
    std::cout << "Add vectors" << std::endl;
    for (const auto& element : v.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

}
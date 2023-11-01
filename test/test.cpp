#include "test.h"
#include <list>


void test() {

    // Vectors
    // Vector initialization
    Vector<double> vectorInitialization;
    std::cout << "Empty vector size: " << vectorInitialization.data.size();
    std::cout << std::endl;
    // test append
    vectorInitialization.append(77);
    std::cout << "Empty vector size after appeding: " << vectorInitialization.data.size();
    std::cout << std::endl;
    std::cout << "Vector after append: ";
    for (const auto& element : vectorInitialization.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    Vector<double> vectorInitialization2(7);
    std::cout << "Vector initialized with size: " << vectorInitialization2.data.size();
    std::cout << std::endl;   

    // 
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

    Vector<int> vAdd = add(myVector, myVector);
    std::cout << "Add vectors" << std::endl;
    for (const auto& element : vAdd.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    Vector<int> vSub = subtract(myVector, myVector);
    std::cout << "Subtract vectors" << std::endl;
    for (const auto& element : vSub.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    Vector<int> vMult = multiply(myVector, myVector);
    std::cout << "Multiply vectors" << std::endl;
    for (const auto& element : vMult.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    Vector<int> vDiv = divide(myVector, myVector);
    std::cout << "Divide vectors" << std::endl;
    for (const auto& element : vDiv.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    // Matrix
    Matrix<int> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    std::cout << "Print matrix (list initialization)" << std::endl;
    for (const Vector<int>& vector : matrix.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    Vector<int> vec1({1, 2, 3, 4, 5});
    Vector<int> vec2({7, 77, 13, 43, 17});
    Vector<int> vec3({37, 2, 1, 1, 1});

    Matrix<int> matrixV = {{vec1, vec2, vec3}};

    std::cout << "Print matrix (Vector initialization)" << std::endl;
    for (const Vector<int>& vector : matrixV.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "Print matrix col vectors" << std::endl;
    for (const Vector<int>& vector : matrixV.col_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    matrixV.transpose();
    std::cout << "Print matrix row vectors after transpose" << std::endl;
    for (const Vector<int>& vector : matrixV.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
}
#include "test.h"
#include <list>


void test() {

    // Vectors
    // Vector initialization
    Vector<double> vectorInitialization;
    std::cout << "Empty vector size: " << vectorInitialization.data.size() << std::endl;
    std::cout << std::endl;

    // test append
    vectorInitialization.append(77);
    std::cout << "Empty vector size after appeding: " << vectorInitialization.data.size() << std::endl;;
    std::cout << std::endl;

    std::cout << "Vector after append: " << std::endl;
    for (const auto& element : vectorInitialization.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    Vector<double> vectorInitialization2(7);
    std::cout << "Vector initialized with size: " << vectorInitialization2.data.size() << std::endl;
    std::cout << std::endl;   

    // 
    Vector<int> vectorInt(5); 
    Vector<double> vectorDouble(5);
    
    std::cout << "vectorInt types" << std::endl;
    for (const auto& element : vectorInt.data) {
        std::cout << typeid(element).name() << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "vectorDouble types" << std::endl;
    for (const auto& element : vectorDouble.data) {
        std::cout << typeid(element).name() << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "List initialization" << std::endl;
    Vector<int> myVector({1, 2, 3, 4, 5});
    for (const auto& element : myVector.data) {
        std::cout << element << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "std::vector initialization" << std::endl;
    std::vector<int> originalData = {111, 2222, 33333, 444444};
    Vector<int> vectorFromvec(originalData); // Constructor is called to set 'data' by copying 'originalData'
    for (const auto& element : vectorFromvec.data) {
        std::cout << element << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Set values initialization" << std::endl;
    myVector.setValues({10, 20, 30, 40, 50});
    for (const auto& element : myVector.data) {
        std::cout << element << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "SetAll to 10" << std::endl;
    myVector.setAll(10);
    std::cout << std::endl;

    int firstElement = myVector[0]; 
    std::cout << "first element: " << firstElement << std::endl;
    std::cout << std::endl;

    double dot = dot(myVector, myVector);
    std::cout << "dot product: " << dot << std::endl;
    std::cout << std::endl;

    Vector<int> vAdd = add(myVector, myVector);
    std::cout << "Add vectors" << std::endl;
    for (const auto& element : vAdd.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl;

    Vector<int> vSub = subtract(myVector, myVector);
    std::cout << "Subtract vectors" << std::endl;
    for (const auto& element : vSub.data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl;

    Vector<int> vMult = multiply(myVector, myVector);
    std::cout << "Multiply vectors" << std::endl;
    for (const auto& element : vMult.data) {
        std::cout << element << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;

    Vector<int> vDiv = divide(myVector, myVector);
    std::cout << "Divide vectors" << std::endl;
    for (const auto& element : vDiv.data) {
        std::cout << element << ' ';
    }

    std::cout << std::endl;
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
    
    std::cout << std::endl;

    Vector<int> vec1({1, 2, 3, 4, 5});
    Vector<int> vec2({7, 77, 13, 43, 17});
    Vector<int> vec3({37, 2, 1, 1, 1});

    Matrix<int> matrixV = {{vec1, vec2, vec3}};

    std::cout << "Print matrix (list of Vector initialization)" << std::endl;
    for (const Vector<int>& vector : matrixV.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    Vector<int> vvec1({147, 2453, 3455, 4445, 52});
    Vector<int> vvec2({27, 747, 143, 434, 14257});
    Vector<int> vvec3({371, 23, 112, 112, 121});
    std::vector<Vector<int>> rows = {vvec1, vvec2, vvec3};

    Matrix<int> matrixvV(rows);

    std::cout << "Print matrix (vector of Vectors initialization)" << std::endl;
    for (const Vector<int>& vector : matrixvV.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Print matrix col vectors" << std::endl;
    for (const Vector<int>& vector : matrixV.col_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    matrixV.transpose();
    std::cout << "Print matrix row vectors after transpose" << std::endl;
    for (const Vector<int>& vector : matrixV.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;


    matrixV.computeRowVectors();
    std::cout << "Print matrix row vectors after computeRowVectors" << std::endl;
    for (const Vector<int>& vector : matrixV.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    Matrix<double> matrixApp;
    Vector<double> vec_to_append1({1.7, 2.3, 3.7, 7.1});
    Vector<double> vec_to_append2({2.1, 20.0, 68.2, 2.21});
    Vector<double> vec_to_append3({0.1, 7.7, 11.2, 9.2});

    matrixApp.appendVectorToRow(vec_to_append1);
    matrixApp.appendVectorToRow(vec_to_append2);
    matrixApp.appendVectorToRow(vec_to_append3);
    matrixApp.computeColVectors();

    std::cout << "Print matrix from appended row Vectors" << std::endl;
    for (const Vector<double>& vector : matrixApp.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "n_rows: " << matrixApp.n_rows << std::endl;
    std::cout << "n_cols: " << matrixApp.n_cols << std::endl;

    std::cout << std::endl;


    Matrix<double> matrixAppC;
    matrixAppC.appendVectorToCol(vec_to_append1);
    matrixAppC.appendVectorToCol(vec_to_append2);
    matrixAppC.appendVectorToCol(vec_to_append3);
    matrixAppC.computeRowVectors();

    std::cout << "Print matrix from appended col Vectors" << std::endl;
    for (const Vector<double>& vector : matrixAppC.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "n_rows: " << matrixAppC.n_rows << std::endl;
    std::cout << "n_cols: " << matrixAppC.n_cols << std::endl;

    std::cout << std::endl;


    Matrix<double> matrixAdd = add(matrixAppC, matrixAppC);
    std::cout << "Print matrix after addition" << std::endl;
    for (const Vector<double>& vector : matrixAdd.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    Matrix<double> matrixSubtract = subtract(matrixAppC, matrixAppC);
    std::cout << "Print matrix after subtraction" << std::endl;
    for (const Vector<double>& vector : matrixSubtract.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    Matrix<double> matrixMultiply = multiply(matrixAppC, matrixAppC);
    std::cout << "Print matrix after multiplication" << std::endl;
    for (const Vector<double>& vector : matrixMultiply.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    Matrix<double> matrixDivide = divide(matrixAppC, matrixAppC);
    std::cout << "Print matrix after division" << std::endl;
    for (const Vector<double>& vector : matrixDivide.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    Matrix<double> matrix1D;
    matrix1D.appendVectorToRow(vec_to_append1);
    matrix1D.computeColVectors();

    Matrix<double> MMult = add(matrix1D, matrixApp);
    std::cout << "Print matrix after addition with 1D matrix" << std::endl;
    for (const Vector<double>& vector : MMult.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;


    Matrix<double> MDot1D({{10.0, 20.0, 30.0}});

    Matrix<double> DotProd1D = dot(MDot1D, matrixApp);
    std::cout << "Dot product matrix 1x3 vs matrix 3x4" << std::endl;
    for (const Vector<double>& vector : DotProd1D.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "DotProd1D n_rows: " << DotProd1D.n_rows << std::endl;
    std::cout << "DotProd1D n_cols: " << DotProd1D.n_cols << std::endl;

    
    Matrix<double> matrix4x5{
        {1, 2, 3, 4, 7},
        {4, 5, 6, 7, 9},
        {7, 8, 9, 11, 2},
        {7, 8, 9, 11, 2}
        };

    Matrix<double> DotProd1Dcase2 = dot(matrixApp, matrix4x5);
    std::cout << "Dot product matrix 3x4 vs matrix 4x5" << std::endl;
    for (const Vector<double>& vector : DotProd1Dcase2.row_vectors) {
        for (const auto& element : vector.data) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "DotProd1Dcase2 n_rows: " << DotProd1Dcase2.n_rows << std::endl;
    std::cout << "DotProd1Dcase2 n_cols: " << DotProd1Dcase2.n_cols << std::endl;

    std::cout << std::endl;

}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
/* Task 7 –Strassen’s Matrix Multiplication 

Implement Strassen’s Algorithm for multiplying two square matrices (size
2n×2n
2
n
×
2
n
 
). Compare the result with the standard matrix multiplication algorithm. 

Test cases: 

2×2 matrix multiplication. 

4×4 matrix multiplication. 

Random values compared with naive multiplication.  */

// using namespace std i didnt import becasue its not a good habit (naming conflict)


// method to add two matrices
std::vector<std::vector<int>> Add(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B
) {

    int size = A.size();

    std::vector<std::vector<int>> result(
        size, std::vector<int>(size)
    );

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}


// method to subtract two matrices
std::vector<std::vector<int>> Subtract(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B
) {

    int size = A.size();

    std::vector<std::vector<int>> result(
        size, std::vector<int>(size)
    );

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}


// method to split a matrix into four smaller matrices
void Split(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>>& A11,
    std::vector<std::vector<int>>& A12,
    std::vector<std::vector<int>>& A21,
    std::vector<std::vector<int>>& A22
) {

    int size = A.size();
    int half = size / 2;

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            A11[i][j] = A[i][j];

            A12[i][j] = A[i][j + half];

            A21[i][j] = A[i + half][j];

            A22[i][j] = A[i + half][j + half];
        }
    }
}


// method to combine four smaller matrices
// into one large matrix
std::vector<std::vector<int>> Combine(
    std::vector<std::vector<int>> C11,
    std::vector<std::vector<int>> C12,
    std::vector<std::vector<int>> C21,
    std::vector<std::vector<int>> C22
) {

    int half = C11.size();
    int size = half * 2;

    std::vector<std::vector<int>> result(
        size, std::vector<int>(size)
    );

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            result[i][j] = C11[i][j];

            result[i][j + half] = C12[i][j];

            result[i + half][j] = C21[i][j];

            result[i + half][j + half] = C22[i][j];
        }
    }

    return result;
}


// Strassen's recursive matrix multiplication
std::vector<std::vector<int>> Strassen(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B
) {

    int size = A.size();

    // base case for recursion
    // when matrix becomes 1 x 1
    if (size == 1) {

        std::vector<std::vector<int>> result(1, std::vector<int>(1));

        result[0][0] = A[0][0] * B[0][0];

        return result;
    }


    int half = size / 2;


    // create four parts for matrix A
    std::vector<std::vector<int>> A11(
        half, std::vector<int>(half)
    );

    std::vector<std::vector<int>> A12(
        half, std::vector<int>(half)
    );

    std::vector<std::vector<int>> A21(
        half, std::vector<int>(half)
    );

    std::vector<std::vector<int>> A22(
        half, std::vector<int>(half)
    );


    // create four parts for matrix B
    std::vector<std::vector<int>> B11(
        half, std::vector<int>(half)
    );

    std::vector<std::vector<int>> B12(
        half, std::vector<int>(half)
    );

    std::vector<std::vector<int>> B21(
        half, std::vector<int>(half)
    );

    std::vector<std::vector<int>> B22(
        half, std::vector<int>(half)
    );


    // split both matrices into four parts
    Split(A, A11, A12, A21, A22);
    Split(B, B11, B12, B21, B22);


    // calculate the seven Strassen products

    // M1 = (A11 + A22) * (B11 + B22)
    std::vector<std::vector<int>> M1 =
        Strassen(
            Add(A11, A22),
            Add(B11, B22)
        );


    // M2 = (A21 + A22) * B11
    std::vector<std::vector<int>> M2 =
        Strassen(
            Add(A21, A22),
            B11
        );


    // M3 = A11 * (B12 - B22)
    std::vector<std::vector<int>> M3 =
        Strassen(
            A11,
            Subtract(B12, B22)
        );


    // M4 = A22 * (B21 - B11)
    std::vector<std::vector<int>> M4 =
        Strassen(
            A22,
            Subtract(B21, B11)
        );


    // M5 = (A11 + A12) * B22
    std::vector<std::vector<int>> M5 =
        Strassen(
            Add(A11, A12),
            B22
        );


    // M6 = (A21 - A11) * (B11 + B12)
    std::vector<std::vector<int>> M6 =
        Strassen(
            Subtract(A21, A11),
            Add(B11, B12)
        );


    // M7 = (A12 - A22) * (B21 + B22)
    std::vector<std::vector<int>> M7 =
        Strassen(
            Subtract(A12, A22),
            Add(B21, B22)
        );


    // calculate the four parts of result

    // C11 = M1 + M4 - M5 + M7
    std::vector<std::vector<int>> C11 =
        Add(
            Subtract(
                Add(M1, M4),
                M5
            ),
            M7
        );


    // C12 = M3 + M5
    std::vector<std::vector<int>> C12 =
        Add(M3, M5);


    // C21 = M2 + M4
    std::vector<std::vector<int>> C21 =
        Add(M2, M4);


    // C22 = M1 - M2 + M3 + M6
    std::vector<std::vector<int>> C22 =
        Add(
            Add(
                Subtract(M1, M2),
                M3
            ),
            M6
        );


    // combine the four parts into the final matrix
    return Combine(C11, C12, C21, C22);
}


// standard matrix multiplication
std::vector<std::vector<int>> NaiveMultiply(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B
) {

    int size = A.size();

    std::vector<std::vector<int>> result(
        size, std::vector<int>(size, 0)
    );

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            for (int k = 0; k < size; k++) {

                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}


// print a matrix
void Print(std::vector<std::vector<int>> matrix) {

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {

            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}


// compare two matrices
bool Compare(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B
) {

    if (A.size() != B.size()) {
        return false;
    }

    for (int i = 0; i < A.size(); i++) {

        for (int j = 0; j < A[i].size(); j++) {

            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }

    return true;
}


// generate a random matrix
std::vector<std::vector<int>> RandomMatrix(int size) {

    std::vector<std::vector<int>> matrix(
        size, std::vector<int>(size)
    );

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            matrix[i][j] = rand() % 10;
        }
    }

    return matrix;
}


int main() {

    srand(time(0));


    // case 1
    // 2 x 2 matrix multiplication

    std::cout << "CASE 1 : 2 x 2" << std::endl;

    std::vector<std::vector<int>> A2 = {
        {1, 2},
        {3, 4}
    };

    std::vector<std::vector<int>> B2 = {
        {5, 6},
        {7, 8}
    };

    std::vector<std::vector<int>> Strassen2 =
        Strassen(A2, B2);

    std::vector<std::vector<int>> Naive2 =
        NaiveMultiply(A2, B2);

    std::cout << "Strassen result :" << std::endl;
    Print(Strassen2);

    std::cout << "Naive result :" << std::endl;
    Print(Naive2);

    std::cout << "Same result : "
              << (Compare(Strassen2, Naive2) ? "Yes" : "No")
              << std::endl << std::endl;


    // case 2
    // 4 x 4 matrix multiplication

    std::cout << "CASE 2 : 4 x 4" << std::endl;

    std::vector<std::vector<int>> A4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}
    };

    std::vector<std::vector<int>> B4 = {
        {8, 7, 6, 5},
        {4, 3, 2, 1},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    std::vector<std::vector<int>> Strassen4 =
        Strassen(A4, B4);

    std::vector<std::vector<int>> Naive4 =
        NaiveMultiply(A4, B4);

    std::cout << "Strassen result :" << std::endl;
    Print(Strassen4);

    std::cout << "Naive result :" << std::endl;
    Print(Naive4);

    std::cout << "Same result : "
              << (Compare(Strassen4, Naive4) ? "Yes" : "No")
              << std::endl << std::endl;


    // case 3
    // random values compared with naive multiplication

    std::cout << "CASE 3 : Random values" << std::endl;

    int size = 4;

    std::vector<std::vector<int>> RandomA =
        RandomMatrix(size);

    std::vector<std::vector<int>> RandomB =
        RandomMatrix(size);

    std::cout << "Matrix A :" << std::endl;
    Print(RandomA);

    std::cout << "Matrix B :" << std::endl;
    Print(RandomB);

    std::vector<std::vector<int>> RandomStrassen =
        Strassen(RandomA, RandomB);

    std::vector<std::vector<int>> RandomNaive =
        NaiveMultiply(RandomA, RandomB);

    std::cout << "Strassen result :" << std::endl;
    Print(RandomStrassen);

    std::cout << "Naive result :" << std::endl;
    Print(RandomNaive);

    std::cout << "Same result : "
              << (Compare(RandomStrassen, RandomNaive) ? "Yes" : "No")
              << std::endl;


    return 0;
}

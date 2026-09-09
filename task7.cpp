#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<vector<int>> Matrix;

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        for (int val : row) cout << val << "\t";
        cout << endl;
    }
}

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix naiveMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) return {{A[0][0] * B[0][0]}};

    int k = n / 2;
    Matrix a11(k, vector<int>(k)), a12(k, vector<int>(k)), a21(k, vector<int>(k)), a22(k, vector<int>(k));
    Matrix b11(k, vector<int>(k)), b12(k, vector<int>(k)), b21(k, vector<int>(k)), b22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = A[i][j];            a12[i][j] = A[i][j + k];
            a21[i][j] = A[i + k][j];        a22[i][j] = A[i + k][j + k];
            b11[i][j] = B[i][j];            b12[i][j] = B[i][j + k];
            b21[i][j] = B[i + k][j];        b22[i][j] = B[i + k][j + k];
        }
    }

    Matrix p1 = strassen(a11, subtract(b12, b22));
    Matrix p2 = strassen(add(a11, a12), b22);
    Matrix p3 = strassen(add(a21, a22), b11);
    Matrix p4 = strassen(a22, subtract(b21, b11));
    Matrix p5 = strassen(add(a11, a22), add(b11, b22));
    Matrix p6 = strassen(subtract(a12, a22), add(b21, b22));
    Matrix p7 = strassen(subtract(a11, a21), add(b11, b12));

    Matrix c11 = subtract(add(add(p5, p4), p6), p2);
    Matrix c12 = add(p1, p2);
    Matrix c21 = add(p3, p4);
    Matrix c22 = subtract(subtract(add(p5, p1), p3), p7);

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = c11[i][j];        C[i][j + k] = c12[i][j];
            C[i + k][j] = c21[i][j];    C[i + k][j + k] = c22[i][j];
        }
    }
    return C;
}

Matrix generateRandomMatrix(int n) {
    Matrix M(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            M[i][j] = rand() % 10;
    return M;
}

int main() {
    srand(time(0));
    
    cout << "--- 2x2 Matrix Multiplication ---" << endl;
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};
    cout << "Strassen Result:" << endl; printMatrix(strassen(A2, B2));
    
    cout << "\n--- 4x4 Matrix Multiplication ---" << endl;
    Matrix A4 = generateRandomMatrix(4);
    Matrix B4 = generateRandomMatrix(4);
    cout << "Naive Result:" << endl; printMatrix(naiveMultiply(A4, B4));
    cout << "Strassen Result:" << endl; printMatrix(strassen(A4, B4));

    cout << "\n--- Random Values Comparison (8x8) ---" << endl;
    Matrix A8 = generateRandomMatrix(8);
    Matrix B8 = generateRandomMatrix(8);
    Matrix naive8 = naiveMultiply(A8, B8);
    Matrix strassen8 = strassen(A8, B8);
    
    bool match = true;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (naive8[i][j] != strassen8[i][j]) match = false;
            
    if (match) cout << "SUCCESS: Strassen matches Naive multiplication for random 8x8 matrices." << endl;
    else cout << "ERROR: Mismatch detected." << endl;

    return 0;
}
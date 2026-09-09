#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generatePascal(int n) {
    vector<vector<int>> triangle;
    if (n <= 0) return triangle;
    
    for (int i = 0; i < n; ++i) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}

void printTriangle(int n) {
    cout << "n = " << n << ":" << endl;
    vector<vector<int>> tri = generatePascal(n);
    if (tri.empty()) cout << "[]" << endl;
    for (const auto& row : tri) {
        cout << "{ ";
        for (int val : row) cout << val << " ";
        cout << "}" << endl;
    }
    cout << "----------------" << endl;
}

int main() {
    printTriangle(0);
    printTriangle(1);
    printTriangle(5);
    return 0;
}
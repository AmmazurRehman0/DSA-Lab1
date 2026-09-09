#include <iostream>
#include <vector>

using namespace std;

vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}

void printResult(const string& testName, const vector<int>& result) {
    cout << testName << ": [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
   
    vector<int> arr1 = {10, 20, 30, 20, 40, 20};
    vector<int> result1 = findAllIndices(arr1, 20);
    printResult("Multiple occurrences (Key 20)", result1);

   
    vector<int> result2 = findAllIndices(arr1, 99);
    printResult("Key not present (Key 99)", result2);

    
    vector<int> arr3 = {};
    vector<int> result3 = findAllIndices(arr3, 20);
    printResult("Empty array", result3);

    return 0;
}
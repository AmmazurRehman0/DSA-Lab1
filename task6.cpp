#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findMode(const vector<int>& arr) {
    if (arr.empty()) return {};
    
    unordered_map<int, int> freq;
    int max_count = 0;
    
    for (int num : arr) {
        freq[num]++;
        if (freq[num] > max_count) {
            max_count = freq[num];
        }
    }
    
    vector<int> modes;
    for (const auto& pair : freq) {
        if (pair.second == max_count) {
            modes.push_back(pair.first);
        }
    }
    return modes;
}

void printModes(const string& testName, const vector<int>& arr) {
    vector<int> modes = findMode(arr);
    cout << testName << ": [";
    for (int i = 0; i < modes.size(); ++i) {
        cout << modes[i] << (i < modes.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    printModes("Unique mode", {4, 1, 2, 2, 3});
    printModes("Multiple modes", {1, 1, 2, 2, 3});
    printModes("Empty array", {});
    return 0;
}
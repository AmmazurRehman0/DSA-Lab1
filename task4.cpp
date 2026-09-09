#include <iostream>
#include <string>

using namespace std;


int naivePatternMatch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    
    if (m == 0) return 0; 
    

    if (n < m) return -1;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        
        if (j == m) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    string text = "artificial intelligence";


    cout << "Pattern at the beginning ('art'): " 
         << naivePatternMatch(text, "art") << endl;

   
    cout << "Pattern at the end ('ence'): " 
         << naivePatternMatch(text, "ence") << endl;

    cout << "Pattern not present ('xyz'): " 
         << naivePatternMatch(text, "xyz") << endl;


    cout << "Empty pattern (''): " 
         << naivePatternMatch(text, "") << endl;

    return 0;
}
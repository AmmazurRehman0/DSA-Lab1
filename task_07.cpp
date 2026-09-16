#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter initial number of marks (1-10): ";
	cin >> n;
	if (n < 1 || n > 10) {
		cout << "Invalid input. Must be between 1 and 10.\n";
		return 1;
	}
	int* marks = new int[n];

	cout << "Enter " << n << " marks: ";
	for (int i = 0; i < n; i++) {
		cin >> *(marks + i); 
	}
int newMark;
	cout << "Enter the additional mark: ";
	cin >> newMark;
	int* tempMarks = new int[n + 1];
	for (int i = 0; i < n; i++) {
		*(tempMarks + i) = *(marks + i);
	}
	*(tempMarks + n) = newMark;
	delete[] marks;
	marks = tempMarks;
	n++;
	cout << "Updated array: ";
	for (int i = 0; i < n; i++) {
		cout << *(marks + i) << " ";
	}
	cout << "\n";
	delete[] marks;
	marks = nullptr;
	tempMarks = nullptr; 
	return 0;
}

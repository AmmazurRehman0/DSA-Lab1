#include <iostream>
using namespace std;

int main() {
	int rows, cols;
	cout << "Enter number of students (rows): ";
	cin >> rows;
	cout << "Enter number of subjects (cols): ";
	cin >> cols;

	if (rows <= 0 || cols <= 0) {
		cout << "Invalid input. Must be greater than 0." << endl;
		return 1;
	}
	int** marks = new int*[rows];
	for (int r = 0; r < rows; r++) {
		marks[r] = new int[cols];
	}
	for (int r = 0; r < rows; r++) {
		cout << "Enter " << cols << " marks for Student " << (r + 1) << ": ";
		for (int c = 0; c < cols; c++) {
			cin >> *(*(marks + r) + c);
		}
	}
	int bestTotal = -1;
	int bestStudent = -1;

	cout << "Results\n";
	for (int r = 0; r < rows; r++) {
		int currentTotal = 0;
		for (int c = 0; c < cols; c++) {
			cout << marks[r][c] << " ";
			currentTotal += marks[r][c];
		}
		cout << "| Total: " << currentTotal << "\n";
		if (currentTotal > bestTotal) {
			bestTotal = currentTotal;
			bestStudent = r + 1;
		}
	}
	cout << "Top student: " << bestStudent << " with total: " << bestTotal << "\n";
	for (int r = 0; r < rows; r++) {
		delete[] marks[r];
	}
	delete[] marks;
	marks = nullptr;

	return 0;
}

#include <iostream>
using namespace std;

void swapDouble(int **pptrA, int **pptrB) {
	int temp = **pptrA; 
	**pptrA = **pptrB;  
	**pptrB = temp;     
}

int main() {
	int a = 5, b = 10;
	int *pa = &a;
	int *pb = &b;
	int **ppa = &pa;
	int **ppb = &pb;

	cout << "Before swap: a = " << a << ", b = " << b << endl;

	swapDouble(ppa, ppb);

	cout << "After swap: a = " << a << ", b = " << b << endl;

	return 0;
}


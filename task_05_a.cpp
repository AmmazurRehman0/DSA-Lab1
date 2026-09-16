 #include <iostream>
using namespace std;

void swapSingle(int *ptrA, int *ptrB) {
	int temp = *ptrA;
}
int main() {
	int a = 5, b = 10;
	int *pa = &a;
	int *pb = &b;

	cout << "Before swap: a = " << a << ", b = " << b << endl;

	swapSingle(pa, pb);

	cout << "After swap: a = " << a << ", b = " << b << endl;

	return 0;
}

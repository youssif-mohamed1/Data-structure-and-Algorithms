#include<iostream>
using namespace std;

const int N = 9;
int arr[N] = { 8,4,2,6,9,1,3,5,7 };

void swap(int& a, int& b) { // swaping 2 elements using bitwise XOR
	a ^= b;
	b ^= a;
	a ^= b;
}

bool compare(int a, int b, bool _comp) {
	if (_comp) // if _comp is true, then sort ascending
		return a < b;
	return a > b; // if _comp is false, then sort descending
}

int* bubble_sort(int* v, int n, int _comp = 1) {
	for (int i = 0; i < n - 1; i++) {
		bool swaped = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (compare(v[j + 1], v[j], _comp)) {
				swap(v[j], v[j + 1]);
				swaped = 1;
			}
		}
		if (!swaped) {
			break;
		}
	}
	return v;
}

void print(int* arr, int n) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int* p = bubble_sort(arr,N);
	print(p,N);
}
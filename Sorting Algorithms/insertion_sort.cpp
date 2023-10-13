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


int* insertion_sort(int* v, int n,bool _comp=1) { // insertion sort
	for (int i = 1; i < n; i++) {
		for (int j = i; j >= 0 && compare(v[j], v[j - 1], _comp); j--) {
			swap(v[j], v[j - 1]);
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
	int* p = insertion_sort(arr,N);
	print(p,N);
}
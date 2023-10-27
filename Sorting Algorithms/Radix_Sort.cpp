#include <iostream>

using namespace std;

const int N = 10;

// sorting array of numbers using Radix sort based on Counting sort
int arr[N] = { 901,221,900,112,90,501,981,0,91,7 };

// initialized by 10 as we has only 10 digits 0-->9
int prefix[10];

int max(int a, int b) { // max function
	if (a >= b)
		return a;
	return b;
}

//sorting in another array 
int* counting_sort(int* arr, int l, int r,int digit) { // O(n)
	for (int i = l; i < r; i++) {
		prefix[(arr[i]/digit)%10]++; // initializing the frequency of each digit 
	}
	for (int i = l + 1; i < r; i++) {
		prefix[i] += prefix[i - 1]; // prefix sum of the frequency array for each digit
	}
	// iterating for putting elements in their correct posistion according to the place of the current digit
	int* res = new int[N];
	for (int i = r-1; i >= l; i--) {
		res[--prefix[(arr[i] / digit) % 10]] = arr[i];
	}
	return res;
}

int* radix_sort(int* arr, int size) {
	int* p = arr;
	// test counting sort in another array
	int mx = 0;
	for (int i = 0; i < N; i++) {
		mx = max(mx, arr[i]);
	}
	int digit = 1;
	while (mx > 0) {
		for (int i = 0; i < 10; i++) {
			prefix[i] = 0;
		}
		p = counting_sort(p, 0, N, digit);
		digit *= 10;
		mx /= 10;
	}
	return p;
}

void print(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

signed main() {
	int* p = radix_sort(arr, N);
	print(p, N);
}

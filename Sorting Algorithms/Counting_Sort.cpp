#include <iostream>

using namespace std;

const int N = 10, MAX_INT = 1e6;

// sorting array of numbers using counting sort
int arr[N] = { 9,2,9,1,9,5,9,2,9,7 };

// should be initialized by the maximum number of the array, but I initialized it by MAX_INT to be easier
int prefix[MAX_INT];

//sorting in another array 
int* counting_sort(int* arr, int l, int r) { // O(n)
	for (int i = l; i < r; i++) {
		prefix[arr[i]]++; // initializing the frequency of each element
	}
	for (int i = l + 1; i < r; i++) {
		prefix[i] += prefix[i - 1]; // prefix sum of the frequency array
	}
	// iterating for putting elements in their correct posistion
	int* res = new int[N];
	for (int i = r; i >= l; i--) {
		res[--prefix[arr[i]]] = arr[i];
	}
	return res;
}

// sorting in the same array 
void _counting_sort(int* arr, int l, int r) { // O(n)
	for (int i = l; i < r; i++) {
		prefix[arr[i]]++; // initializing the frequency of each element
	}
	for (int i = l + 1; i < r; i++) {
		prefix[i] += prefix[i - 1]; // prefix sum of the frequency array
	}
	// iterating for putting elements in their correct posistion
	for (int i = r; i >= l; i--) {
		if (i > l) {
			while (prefix[i] > prefix[i - 1]) {
				arr[--prefix[i]] = i;
			}
			continue;
		}
		while (prefix[i] > 0) {
			arr[--prefix[i]] = i;
		}
	}
}

signed main() {
	// test counting sort in the same array
	_counting_sort(arr, 0, N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// reset prefix array
	for (int i = 0; i < MAX_INT; i++) {
		prefix[i] = 0;
	}

	// test counting sort in another array
	int* p = counting_sort(arr, 0, N);
	for (int i = 0; i < N; i++) {
		cout << p[i] << " ";
	}
}

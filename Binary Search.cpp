#include<iostream>

using namespace std;

const int N = 10;

int arr[N];

int binarySearch(int key) {
	int left = -1, right = N, mid;
	while (left < right - 1) {
		mid = left + right >> 1;
		if (arr[mid] == key) {
			return mid + 1;
		}
		else if (arr[mid] < key) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	return -1;
}


int binary_search_find_first(int key) {
	int left = -1, right = N, mid,ans=-1;
	while (left < right - 1) {
		mid = left + right >> 1;
		if (arr[mid] == key) {
			right = mid;
			ans = mid;
		}
		else {
			left = mid;
		}
	}
	return ++ans;
}

int binary_search_find_last(int key) {
	int left = -1, right = N, mid, ans = -1;
	while (left < right - 1) {
		mid = left + right >> 1;
		if (arr[mid] == key) {
			left = mid;
			ans = mid;
		}
		else {
			right = mid;
		}
	}
	return ++ans;
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	cout << upper_bound(arr, arr + N, 2) - arr;
}

// lower bound --> first element greater than or equal to the key
// upper bound --> first elemetn greater than the key
// log(N)

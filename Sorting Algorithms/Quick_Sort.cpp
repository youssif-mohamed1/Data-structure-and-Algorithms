#include <iostream>

using namespace std;
const int N = 10;
int arr[N] = { 2,1,6,3,8,1,9,2,7,5 };

void swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int partition(int* arr, int start, int end) {
	int i = start, j = end, p = i;
	while (i <= j) {
		while (arr[i] <= arr[p] && i <= end) {
			i++;
		}
		while (arr[j] > arr[p] && start <= j) {
			j--;
		}
		if (i > j) break;
		swap(arr[i], arr[j]);
	}
	swap(arr[j], arr[p]);
	return j;
}

void quick_sort(int* arr, int l, int h) {
	if (l >= h) {
		return;
	}
	int p = partition(arr, l, h);
	quick_sort(arr, l, p-1);
	quick_sort(arr, p+1, h);
}

signed main() {
	quick_sort(arr, 0, N - 1);
	for (auto it : arr) {
		cout << it << " ";
	}
}

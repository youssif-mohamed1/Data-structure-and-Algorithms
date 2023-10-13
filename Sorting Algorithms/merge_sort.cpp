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

int* merge(int* left, int l_size, int* right, int r_size, bool _comp) {
	int* res = new int[l_size + r_size], l = 0, r = 0;
	for (int i = 0; i < l_size + r_size; i++) {
		if (l == l_size || (compare(right[r], left[l], _comp) && r < r_size)) {
			res[i] = right[r];
			r++;
			continue;
		}
		res[i] = left[l];
		l++;
	}
	return res;
}

int* merge_sort(int* v, int start, int end, bool _comp = 1) {
	if (start == end) {
		int* leave = &v[start];
		return leave;
	}
	int mid = start + end >> 1;
	int* left = merge_sort(v, start, mid, _comp);
	int* right = merge_sort(v, mid + 1, end, _comp);
	return merge(left, mid - start + 1, right, end - mid, _comp);
}


void print(int* arr, int n) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int* p = merge_sort(arr,0,N-1);
	print(p,N);
}
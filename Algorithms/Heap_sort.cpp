#include<iostream>

using namespace std;

const int N = 6;
int arr[N] = { 60, 20, 40, 70, 30, 10 };

void heapify_node(int i,int n) {
	int parent = i, l = 2 * i + 1, r = 2 * i + 2;
	if (l < n && arr[parent] < arr[l]) {
		parent = l;
	}
	if (r < n && arr[parent] < arr[r]) {
		parent = r;
	}
	if (parent != i) {
		int temp = arr[parent];
		arr[parent] = arr[i];
		arr[i] = temp;
		heapify_node(parent,n);
	}
}

void heapify_tree(int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify_node(i,n);
	}
}

void heap_sort(int* arr,int n) {
	heapify_tree(N);
	for (int i = n - 1; i >= 0; i--) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}cout << endl;
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify_tree(i);
	}

}

int main() {
	cout << "array before heap sort: ";
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	heap_sort(arr, N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
#include<iostream>
#define dim 7
using namespace std;
int weight[dim][dim];

void all_to_all_shortest_path(int weight[][dim], int n) {
	bool flag = 0;
	do {
		flag = 0;
		for (int src = 0; src < n; src++) {
			for (int dest = 0; dest < n; dest++) {
				for (int via = 0; via < n; via++) {
					if (weight[src][dest] > weight[src][via] + weight[via][dest]) {
						weight[src][dest] = weight[src][via] + weight[via][dest];
						flag = 1;
					}
				}
			}
		}
	} while (flag);
}
int main() {
	all_to_all_shortest_path(weight,dim);
}
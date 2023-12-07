#include<iostream>

using namespace std;

#define INF 99
#define dim 7

int weight[dim][dim] = { { 0, 1, INF, INF, INF, 2, INF },
			{ 1, 0, 8, INF, INF, INF, INF },
			{ INF, 8, 0, 4, INF, 3, INF },
			{ INF, INF, 4, 0, 6, INF, INF },
			{ INF, INF, INF, 6, 0, 5, INF },
			{ 2, INF, 3, INF, 5, 0, 2 },
			{ INF, INF, INF, INF, INF, 2, 0 }
};

void shortest_path_between_2_nodes(int source, int dest) {
	int z[dim][3];
	for (int i = 0; i < dim; i++) {
		z[i][0] = -1; z[i][1] = INF; z[i][2] = 0;
	}
	int mini = 0, rmin = source;
	z[source][0] = source; z[source][1] = 0; z[source][2] = 1;
	do {
		for (int i = 0; i < dim; i++) {
			if (z[i][2] == 0 && z[i][1] > weight[rmin][i] + mini) {
				z[i][0] = rmin;
				z[i][1] = weight[rmin][i] + mini;
			}
		}
		rmin = -1; mini = INF;
		for (int i = 0; i < dim; i++) {
			if (z[i][2]==0 && z[i][1] < mini) {
				mini = z[i][1];
				rmin = i;
			}
		}
		z[rmin][2] = 1;
	} while (rmin!=dest);
	int r = dest;
	while (r != source) {
		cout << r << " ";
		r = z[r][0];
	}
}

int main() {
	int source, destination;
	int testcases = 1;
	cin >> testcases;
	while (testcases--) {
		cin >> source >> destination;
		shortest_path_between_2_nodes(source, destination);
		cout << endl;
	}
}
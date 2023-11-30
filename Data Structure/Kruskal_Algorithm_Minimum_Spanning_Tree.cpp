#include<iostream>
using namespace std;
#define dim 7
#define INF 1e9

int weight[dim][dim] =
{ { 0, 3, INF, INF, INF, INF, 2 },
  { 3, 0, 2, INF, INF, INF, 5 },
  { INF, 2, 0, 7, 1, 1, 3 },
  { INF, INF, 7, 0, 6, 7, INF },
  { INF, INF, 1, 6, 0, 4, INF },
  { INF, INF, 1, 7, 4, 0, 8 },
  { 2, 5, 3, INF, INF, 8, 0 }
}, min_span[dim][dim] = { {-1 }};

int kruskal_min_spanning_tree() {
	int z[dim];
	int mini=INF, row_min=INF, col_min=INF, total_weight=0, group=0;

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			min_span[i][j] = INF;
			if (i == j) {
				min_span[i][j] = 0;
			}
		}
		z[i] = -1;
	}

	while (1) {
		mini = INF;
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < i; j++) {
				if (weight[i][j] < mini) {
					row_min = i;
					col_min = j;
					mini = weight[i][j];
				}
			}
		}
		if (mini == INF) {
			return total_weight;
		}
		if (z[row_min] != z[col_min] || z[row_min] == -1 || z[col_min] == -1) {
			min_span[row_min][col_min] = min_span[col_min][row_min] = mini;
			total_weight += mini;
			if (z[row_min] == -1 && z[col_min] == -1) {
				group++;
				z[row_min] = z[col_min] = group;
			}
			else if (z[row_min] == -1 && z[col_min] != -1) {
				z[row_min] = z[col_min];
			}
			else if (z[row_min] != -1 && z[col_min] == -1) {
				z[col_min] = z[row_min];
			}
			else{
				int temp = z[col_min];
				for (int i = 0; i < dim; i++) {
					if (z[i] == temp) {
						z[i] = z[row_min];
					}
				}
			}
		}
		weight[row_min][col_min] = INF;
	}
}

void print_matrix(int row, int col,int mat[][dim]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mat[i][j] != INF) {
				cout << mat[i][j] << " ";
			}
			else {
				cout << "# ";
			}
		}
		cout << endl;
	}
}

void test() {
	cout << "weighted graph before min spanning tree: \n\n";
	print_matrix(dim, dim, weight);
	cout<<"\n\ntotall weight: "<<kruskal_min_spanning_tree();
	cout << "\n\n\nweighted graph after min spanning tree: \n\n";
	print_matrix(dim, dim, min_span);
}

int main() {
	test();
	return 0;
}
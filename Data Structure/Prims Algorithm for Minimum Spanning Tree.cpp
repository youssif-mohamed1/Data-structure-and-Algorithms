#include<iostream>
using namespace std;

#define dim 7
#define INF 99

int weight[dim][dim] =
{ { 0, 3, INF, INF, INF, INF, 2 },
  { 3, 0, 2, INF, INF, INF, 5 },
  { INF, 2, 0, 7, 1, 1, 3 },
  { INF, INF, 7, 0, 6, 7, INF },
  { INF, INF, 1, 6, 0, 4, INF },
  { INF, INF, 1, 7, 4, 0, 8 },
  { 2, 5, 3, INF, INF, 8, 0 }
},min_span[dim][dim];

int prims_mst() {
	int z[dim][3];
	int mini = INF,row_min = INF, col_min = -1, totall_weight=0;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			min_span[i][j] = INF;
			if (i == j) {
				min_span[i][j] = 0;
			}
		}
		z[i][0] = -1;
		z[i][1] = INF;
		z[i][2] = 0;
	}
	row_min = 0;
	z[row_min][0] = 0; z[row_min][1] = 0;	z[row_min][2] = 1;
	do {
		for (int i = 0; i < dim; i++) {
			if (z[i][2] == 0 && z[i][1] > weight[row_min][i]) {
				z[i][0] = row_min;  z[i][1] = weight[row_min][i];
			}
		}
		mini = INF;  col_min = -1;
		for (int i = 0; i < dim; i++) {
			if (z[i][2] == 0 && z[i][1] < mini) {
				mini = z[i][1]; row_min = z[row_min][0];  col_min = i;
			}
		}
		if (mini == INF)
			return totall_weight;
		min_span[row_min][col_min] = min_span[col_min][row_min] = mini;
		totall_weight +=mini;
		row_min = col_min;
		z[row_min][2] = 1;
	} while (row_min!=-1);
}

void print_matrix(int row, int col, int mat[][dim]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mat[i][j] != INF)cout << mat[i][j]<<" ";
			else cout << "# ";
		}
		cout << endl;
	}
}

int main(void)
{
	cout << "OLD Graph: \n";
	print_matrix(dim, dim, weight);
	cout << prims_mst();
	cout << "\nAfter mst: \n";
	print_matrix(dim, dim, min_span);
}

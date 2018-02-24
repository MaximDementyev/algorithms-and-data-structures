//Дана матрица размера N × N, состоящая из нулей и единиц.
//Найти наибольшую квадратную подматрицу, состоящую из единиц.

//Input format
//N
//A11 A12 A13 ... A1N
//A21 A22 A23 ... A2N
//...
//AN1 AN2 AN3 ... ANN
//N < 10000

//Output format    GreatestSubmatrixSize

#include<stdio.h>
#include<algorithm>

int main() {
	int N;
	scanf("%d", &N);
	int **mas = new int*[N];
	int **solve = new int*[N];
	for (int i = 0; i < N; ++i) {
		mas[i] = new int[N];
		solve[i] = new int[N];
		for (int j = 0; j < N; ++j) {
			scanf("%d", &mas[i][j]);
		}
	}
	for (int i = 0; i < N; ++i) {
		solve[N-1][i] = mas[N-1][i];
		solve[i][N-1] = mas[i][N-1];
	}
	for (int i = N - 2; i >= 0; --i) {
		for (int j = N - 2; j >= 0; --j) {
			if (mas[i][j] == 0) solve[i][j] = 0;
			else {
				int tmp_min = std::min(solve[i + 1][j], solve[i][j + 1]);
				if (tmp_min == 0) solve[i][j] = 1;
				else {
					if (solve[i + tmp_min][j + tmp_min] > 0) solve[i][j] = tmp_min + 1;
					else solve[i][j] = tmp_min;
				}
			}
		}
	}
	int tmp_max = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (solve[i][j] > tmp_max) tmp_max = solve[i][j];
		}
	}
	printf("%d", tmp_max);
	for (int i = 0; i < N; ++i) {
		delete[] mas[i];
		delete[] solve[i];
	}
	return 0;
}
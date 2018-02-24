//На вход подаётся описание ориентированного графа — необходимо найти число его компонент сильной связности.
//Компонентой сильной связности называется максимальное по включению множество вершин, каждые две вершины которого достижимы друг из друга.

//Input format
//N ≤ 1000 – число вершин
//N строк вида
//ai, 1 ai, 2 ... ai, N, где ai, j  = 1, если в графе есть ребро из вершины i в вершину j.
//Output format    M – число компонент сильной связности

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

void full_DFS(int **graf, int *Ver, int *time, int pos, int &q, int N) {
	Ver[pos] = 1;
	time[q] = pos;
	++q;
	for (int i = 0; i < N; ++i) {
		if (graf[pos][i] == 1 && Ver[i] == 0) {
			full_DFS(graf, Ver, time, i, q, N);
		}
	}
	Ver[pos] = 2;
	time[q] = pos;
	++q;
}

void DFS_short(int **graf, int *Ver, int pos, int N) {
	Ver[pos] = 1;
	for (int i = 0;i<N;++i) {
		if (graf[i][pos] == 1 && Ver[i] == 0) {
			DFS_short(graf, Ver, i, N);
		}
	}
}


int main() {
	int N;
	scanf("%d", &N);
	int q = 0, k1 = 0, k2 = 0;
	int **graf = new int*[N];
	for (int i = 0; i < N; ++i) {
		graf[i] = new int[N];
	}
	int *Ver = new int[N];
	memset(Ver, 0, N * sizeof(int));
	int *time = new int[2 * N];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &graf[i][j]);
		}
	}

	for (int i = 0; i < N; ++i) {
		if (Ver[i] == 0) {
			full_DFS(graf, Ver, time, i, q, N);
			++k1;
		}
	}
	memset(Ver, 0, N * sizeof(int));
	for (int i = 2 * N - 1;i >= 0;i--) {
		if (Ver[time[i]] == 0) {
			DFS_short(graf, Ver, time[i], N);
			++k2;
		}
	}
	printf("%d", std::max(k1, k2));
	delete[] Ver;
	delete[] time;
	for (int i = 0; i < N; ++i) {
		delete[] graf[i];
	}
	return 0;
}
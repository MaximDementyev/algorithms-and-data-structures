//Имеется ориентированный взвешенный граф из N вершин, представленный матрицей смежности C[N][N], положительные элементы которой Cij представляют веса связей i-й и j-й вершин.
//Найти наибольшее из кратчайших расстояний между всеми достижимыми парами вершин.
//Гарантируется, что ответ не превышает 109.

//Input format
//N
//C11 C12 ... C1N
//C21 C22 ... C2N
//...
//CN1 CN2 ... CNN

//Output format    MaximumShortestPath


#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

struct edge {
	int next;
	int length;
};

int max(const vector<vector<edge>> &graf, const int N, const int pos) {
	int *way = new int[N];
	memset(way, 1, N * sizeof(int));
	way[pos] = 0;
	for (int k = 0; k < N; ++k) {
		int size1 = graf.size();
		bool flag = false;
		for (int j = 0; j < size1; ++j) {
			int size2 = graf[j].size();
			for (int i = 0; i < size2; ++i) {
				if (way[j] + graf[j][i].length < way[graf[j][i].next]) {
					way[graf[j][i].next] = way[j] + graf[j][i].length;
					flag = true;
				}
			}
		}
		if (flag == false) break;
	}
	int max_way = 0;
	for (int i = 0; i < N; ++i) {
		if (max_way < way[i] && way[i] != 16843009) max_way = way[i];
	}
	delete[] way;
	return max_way;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<edge>> graf;
	for (int i = 0; i < N; ++i) {
		vector<edge> tmp;
		graf.push_back(tmp);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int w;
			scanf("%d", &w);
			if (i != j && w != 0) {
				edge tmp;
				tmp.next = j;
				tmp.length = w;
				graf[i].push_back(tmp);
			}
		}
	}
	int max_way = 0;
	for (int i = 0; i < N; ++i) {
		int tmp = max(graf, N, i);
		if (max_way < tmp) max_way = tmp;
	}
	printf("%d", max_way);
	return 0;
}
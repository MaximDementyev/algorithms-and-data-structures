//Двудольный граф — неориентированный граф, множество вершин которого можно разбить на два непустых подмножества таких, что не существует рёбер,
//соединяющих пару вершин, принадлежащих одному подмножеству.
//Задан неориентированный граф с N вершинами и M рёбрами.Требуется определить, является ли он двудольным.

//Input format
//N M
//U1 V1
//U2 V2
//...
//UN VN
//Вершины нумеруются с 0.

//Output format  YES или NO



#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void svaz(vector<vector<int>> &graf, int *sv_mas, const int pos, const bool set, bool *flag) {
	sv_mas[pos] = set;
	int size = graf[pos].size();
	for (int i = 0; i < size; ++i) {
		if (*flag == 1) {
			if (sv_mas[graf[pos][i]] == -1)
				svaz(graf, sv_mas, graf[pos][i], set ^ 1, flag);
			else if (sv_mas[graf[pos][i]] == set) *flag = false;
		}
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	auto pow = new int[N];
	memset(pow, 0, sizeof(int)*N);
	vector<vector<int>> graf;
	for (auto i = 0; i < N; ++i) {
		vector<int> tmp;
		graf.push_back(tmp);
	}
	for (auto i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
		++pow[a];
		++pow[b];
	}
	auto flag = true;
	auto sv_mas = new int[N];
	for (auto i = 0; i < N; ++i) {
		sv_mas[i] = -1;
	}

	for (auto i = 0; i < N; ++i) {
		if (pow[i] > 0) {
			svaz(graf, sv_mas, i, 0, &flag);
			break;
		}
	}
	if (flag == true) printf("YES");
	else printf("NO");
	delete[] pow;
	delete[] sv_mas;
	return 0;
}
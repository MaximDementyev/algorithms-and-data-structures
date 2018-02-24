//определить, существует ли в графе, содержащем N вершин, путь, содержащий все M рЮбер, который проходит по каждому из них ровно один раз.
//Input format         Output format
//N M                  YES или NO
//S1 D1
//S2 D2
//...
//SN DN

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>
using namespace std;

void svaz(vector<vector<int>> &graf, int *sv_mas, const int pos) {
	sv_mas[pos] = 1;
	int size = graf[pos].size();
	for (int i = 0; i < size; ++i) {
		if (sv_mas[graf[pos][i]] == 0)
			svaz(graf, sv_mas, graf[pos][i]);
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int *pow = new int[N];
	memset(pow, 0, sizeof(int)*N);
	vector<vector<int>> graf;
	for (int i = 0; i < N; ++i) {
		vector<int> tmp;
		graf.push_back(tmp);
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a;--b;
		graf[a].push_back(b);
		graf[b].push_back(a);
		++pow[a];
		++pow[b];
	}

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if (graf[i].size() % 2 == 1) ++sum;
		if (sum > 2) break;
	}
	if (sum > 2) {
		printf("NO");
		delete[] pow;
		return 0;
	}
	int *sv_mas = new int[N];
	memset(sv_mas, 0, sizeof(int)*N);
	for (int i = 0; i < N; ++i) {
		if (pow[i] > 0) {
			svaz(graf,sv_mas,i);
			break;
		}
	}
	bool flag = true;
	for (int i = 0; i < N; ++i) {
		if (sv_mas[i] == 0 && pow[i] != 0) {
			flag = false;
			break;
		}
	}
	if (flag == true) printf("YES");
	else printf("NO");

	delete[] pow;
	delete[] sv_mas;
	return 0;
}
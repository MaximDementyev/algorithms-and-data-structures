//Имеются N городов.Каждые два города соединены не более, чем одной двунаправленной дорогой, всего дорог M.
//Имеется C компаний, пронумерованных от 1 до C.Каждая из дорог либо принадлежит одной из компаний, либо принадлежит государству, тогда владелец равен нулю.
//Два города являются столицами — северной CN и южной CS.По законам страны на ЛЮБОМ из возможных путей между столицами должна иметься дорога, принадлежащая КАЖДОЙ из компаний.
//Нужно вывести список всех компаний, для которых между столицами существует путь, на котором у этой компании нет ни одной дороги.
//Input format
//N M C
//a1 b1 c1
//a2 b2 c2
//...
//aN bN cN
//CN CS
//Output format
//K
//c1 c2 ... cK
//      Examples
//Input	       Output
//4 5 2        2
//1 2 1        1 2 
//1 3 2
//2 4 2
//3 4 1
//2 3 0
//1 4

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct edge {
	int next;
	int comp;
};

void svaz(vector<vector<edge>> &graf, int *sv_mas, const int pos, const int comp) {
	sv_mas[pos] = 1;
	const int size = graf[pos].size();
	for (auto i = 0; i < size; ++i) {
		if (graf[pos][i].comp != comp)
			if (sv_mas[graf[pos][i].next] == 0)
				svaz(graf, sv_mas, graf[pos][i].next, comp);
	}
}

int main() {
	int N, M, C, CN, CS;
	scanf("%d %d %d", &N, &M, &C);
	vector<vector<edge>> graf;
	for (auto i = 0; i < N; ++i) {
		vector<edge> tmp;
		graf.push_back(tmp);
	}
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a;--b;
		edge tmp;
		tmp.next = b;
		tmp.comp = c;
		graf[a].push_back(tmp);
		tmp.next = a;
		graf[b].push_back(tmp);
	}
	scanf("%d %d", &CN, &CS);
	--CN;--CS;
	vector<int> injustice;
	auto sv_mas = new int[N];
	for (auto i = 1; i <= C; ++i) {
		memset(sv_mas, 0, sizeof(int)*N);
		svaz(graf, sv_mas, CN, i);
		if (sv_mas[CS] == 1) injustice.push_back(i);
	}

	const int size = injustice.size();
	printf("%d\n", size);
	for (auto i = 0; i < size; ++i) {
		printf("%d ", injustice[i]);
	}
	delete[] sv_mas;
	return 0;
}
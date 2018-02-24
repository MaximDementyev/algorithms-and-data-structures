//Гора состоит из N пещер и M тоннелей между ними. Каждый тоннель имеет определённую длину.
//Спелеологи, исследующие гору, находятся в пещере S, выход наружу находится в пещере F.
//Продвигаясь по пещерам, спелеологи оставили K не очень хорошо затушенных костров, и вот в какой-то момент времени произошёл толчок и все костры стали дымить. 
//Дым распространяется по всем тоннелям, ведущим от пещеры, одновременно со скоростью 1 метр в секунду. 
//Как только дым доходит до какой-либо пещеры, он начинает распространяться по всем тоннелям, ведущим из неё. Сами спелеологи, почувствовав толчок, стали пробираться к выходу со скоростью 1 метр в секунду. 
//Вопрос состоит в том, успеют ли они добраться до выхода прежде чем столкнутся с дымом.
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>
using namespace std;

struct edge {
	int next;
	int length;
};

int f(const vector<vector<edge>> &graf, const int N, const int pos, const int F) {
	auto way = new int[N];
	memset(way, 1, N * sizeof(int));
	way[pos] = 0;
	for (auto k = 0; k < N; ++k) {
		const int size1 = graf.size();
		auto flag = false;
		for (auto j = 0; j < size1; ++j) {
			const int size2 = graf[j].size();
			for (auto i = 0; i < size2; ++i) {
				if (way[j] + graf[j][i].length < way[graf[j][i].next]) {
					way[graf[j][i].next] = way[j] + graf[j][i].length;
					flag = true;
				}
			}
		}
		if (flag == false) break;
	}
	return way[F];
}

void svaz(vector<vector<edge>> &graf, int *sv_mas, const int pos, const int F) {
	sv_mas[pos] = 1;
	const int size = graf[pos].size();
	for (auto i = 0; i < size; ++i) {
		if (sv_mas[F] == 0)
			if (sv_mas[graf[pos][i].next] == 0)
				svaz(graf, sv_mas, graf[pos][i].next,F);
	}
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	auto bonfire = new int[K];
	for (auto i = 0; i < K; ++i) {
		scanf("%d", &bonfire[i]);
		--bonfire[i];
	}
	vector<vector<edge>> graf;
	for (auto i = 0; i < N; ++i) {
		vector<edge> tmp;
		graf.push_back(tmp);
	}
	for (auto i = 0; i < M; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a;--b;
		edge tmp;
		tmp.next = b;
		tmp.length = c;
		graf[a].push_back(tmp);
		tmp.next = a;
		graf[b].push_back(tmp);
	}
	int S, F;
	scanf("%d %d", &S, &F);
	--S; --F;

	//_____________________
	auto sv_mas = new int[N];
	memset(sv_mas, 0, sizeof(int)*N);
	svaz(graf, sv_mas, S, F);
	if (sv_mas[F] == 0) {
		printf("-1");
		delete[] bonfire;
		delete[] sv_mas;
		return 0;
	}

	auto time = f(graf, N, S, F);
	auto flag = true;
	for (auto i = 0; i < K; ++i) {
		memset(sv_mas, 0, sizeof(int)*N);
		svaz(graf, sv_mas, bonfire[i], F);
		if (sv_mas[F] != 0) {
			if (time > f(graf, N, bonfire[i], F)) {
				flag = false;
				break;
			}
		}
	}
	if (flag == true) printf("%d", time);
	else printf("-1");

	delete[] bonfire;
	return 0;
}

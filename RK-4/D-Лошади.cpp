//В скачках участвует 3 < N < 500 лошадей, пронумерованных, начиная с 1. Паниковский хочет знать, выиграет ли в забеге лошадь под номером 1 <  = M <  = N. 
//Известно, что у всех лошадей различные скорости. Паниковский выяснил взаимное соотношение нескольких пар.
//Первая строка содержит число лошадей и выбранную лошадь. Каждая последующая строка, кроме последней, содержит пару чисел P и Q, которая означает, что лошадь P быстрее лошади Q.
//Последняя строка содержит ограничитель входных данных 0. Все пары различны и корректны.
//Требуется вывести Yes, если полученной информации достаточно для того, чтобы точно определить, может ли выиграть выбранная лошадь или нет. No, если приведённой информации недостаточно.

//Input format
//N M
//P1 Q1
//P2 Q2
//...
//PN QN
//0

//Output format
//Yes | No

#include <stdio.h>
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
	int N, pos;
	scanf("%d %d", &N, &pos);--pos;
	int a, b;
	bool solve = true;
	vector<vector<int>> graf;
	for (int i = 0; i < N; ++i) {
		vector<int> tmp;
		graf.push_back(tmp);
	}
	scanf("%d", &a);
	while (a != 0) {
		scanf("%d", &b);
		--a;--b;
		if (b == pos) {
			printf("Yes");
			return 0;
			solve = false;
			break;
		}
		graf[a].push_back(b);
		scanf("%d", &a);
	}
	if (solve == true) {
		int *sv_mas = new int[N];
		memset(sv_mas, 0, sizeof(int)*N);
		svaz(graf, sv_mas, pos);
		for (int i = 0; i < N; ++i) {
			if (sv_mas[i] == 0) {
				solve = false;
				break;
			}
		}
		delete[] sv_mas;
	}
	if (solve == true) printf("Yes");
	else printf("No");
	return 0;
}

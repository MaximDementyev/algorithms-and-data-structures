//Имеется прямоугольный лабиринт размерами N × M. В лабиринте имеется вход, помеченный знаком @, выход, помеченный знаком #,
//стены, обозначенные знаком +. Свободные клетки обозначаются точкой.
//Требуется определить наименьшее число ходов для того, чтобы, двигаясь по свободным клеткам, попасть из входа в выход.
//Движение возможно только по горизонтали и вертикали(до 4 - х ходов из клетки, не находящейся на границе).

//Input format          Output format
//N M                   NumberOfMoves
//+ @+ +
//+.++
//+ ...
//++ + #

//       Examples
//Input	           Output
//4 5              8
//+ .++ +
//@....
//..++.
//. + #..


#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct point {
	int x;
	int y;
};

void insert(int ** lab, point prev, vector<point>&curr, const int N, const int M) {
	auto tmp = prev;
	if (prev.y > 0 && lab[prev.x][prev.y - 1] != -1) {
		--tmp.y;
		curr.push_back(tmp);
	}
	tmp = prev;
	if (prev.y < M-1 && lab[prev.x][prev.y + 1] != -1) {
		++tmp.y;
		curr.push_back(tmp);
	}
	tmp = prev;
	if (prev.x > 0 && lab[prev.x - 1][prev.y] != -1) {
		--tmp.x;
		curr.push_back(tmp);
	}
	tmp = prev;
	if (prev.x < N - 1 && lab[prev.x + 1][prev.y] != -1) {
		++tmp.x;
		curr.push_back(tmp);
	}
}

void rang(int **lab, vector<point> &curr, vector<point> &prev, const int rg, const int N, const int M) {
	curr.erase(curr.begin(), curr.end());
	const int size = prev.size();
	for (auto i = 0; i < size; ++i) {
		if (lab[prev[i].x][prev[i].y] == 0) {
			lab[prev[i].x][prev[i].y] = rg;
			insert(lab, prev[i], curr, N, M);
		}
	}
}

int main() {
	int N, M;
	scanf("%d", &N); scanf("%d", &M);
	int **lab = new int*[N];
	for (auto i = 0; i < N; ++i) {
		lab[i] = new int[M];
	}
	point entrance, exit;
	int c = getchar();
	for (auto i = 0; i < N; ++i) {
		int j = 0;
		for (c = getchar(); c != '\n' && c != EOF; c=getchar()) {
			switch (c) {
				case '+': {
					lab[i][j++] = -1;
					break;
				}
				case '.': {
					lab[i][j++] = 0;
					break;
				}
				case '@': {					
					entrance.x = i;
					entrance.y = j;
					lab[i][j++] = 0;
					break;
				}
				case '#': {
					exit.x = i;
					exit.y = j;
					lab[i][j++] = 0;
					break;
				}
				default:
					break;
			}
		}
	}
	vector<point> curr, prev;
	prev.push_back(exit);

	int rg = 0;
	while (lab[entrance.x][entrance.y] == 0) {
		rang(lab, curr, prev, rg, N, M);
		if (lab[entrance.x][entrance.y] == 0) {
			++rg;
			rang(lab, prev, curr, rg, N, M);
		}
		++rg;
	}
	printf("%d", lab[entrance.x][entrance.y]);
	for (auto i = 0; i < N; ++i) {
		delete[] lab[i];
	}
	return 0;
}

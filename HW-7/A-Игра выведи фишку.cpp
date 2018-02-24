//Два игрока играют в следующую игру. На поле из N + 1 × N + 1 клетки (нумерация клеток от 0 до N) в клетке (0, 0) стоит фишка.
//Её разрешено разрешено двигать из клетки (x, y) в клетку с координатами (x + ai, y + bi), где пары (ai, bi) обговорены перед началом игры.
//Выигрывает тот игрок, который вывел фишку первым в клетку, которая находится на расстоянии не менее чем R от (0, 0).
//Необходимо определить кто из игроков выигрывает, при безошибочных действиях соперника. Игроки ходят по очереди, пропускать ход нельзя.
//Input format
//N ≤ 300 – граница поля
//R ≤ 300 – минимальное расстояние на которое нужно вывести фишку
//M ≤ 30 – число допустимых ходов
//a1 b1
//a2 b2
//...
//aM bM
//0 ≤ ai, bi ≤ 1000

//Output format     1 или 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

struct point {
	int x = 0;
	int y = 0;
};

point operator+ (point a, point b) {
	a.x += b.x;
	a.y += b.y;
	return a;
}

double norm(point a) {
	return sqrt((a.x)*(a.x) + (a.y)*(a.y));
}

int solve(int **field, point pos, point *run, int R, int M) {
	if (norm(pos) > R) return -1;
	if (field[pos.x][pos.y] != 0) return field[pos.x][pos.y];
	for (int i = 0; i < M; ++i) {
		if (solve(field, pos + run[i], run, R, M) == -1) {
			field[pos.x][pos.y] = 1;
			return 1;
		}
	}
	field[pos.x][pos.y] = -1;
	return -1;
}

void print(int **field, int size) {
	for (int i = size; i >= 0; --i) {
		for (int j = 0; j <= size; ++j) {
			printf("%2d ", field[j][i]);
		}
		printf("\n");
	}
}


int main() {
	int N, R, M;
	scanf("%d", &N);
	scanf("%d", &R);
	scanf("%d", &M);
	point *run = new point[M];
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &run[i].x, &run[i].y);
	}
	++N;
	int **field = new int*[N];
	for (int i = 0; i < N; ++i) {
		field[i] = new int[N];
		memset(field[i], 0, sizeof(int)*N);
	}--N;
	point pos;
	int res = solve(field, pos, run, R, M);
	if (res == 1) printf("1");
	else printf("2");
	delete[] run;
	return 0;
}
﻿//Имеется лестница, в которой N ступенек.Кузнечик находится перед лестницей. Он прыгает только вверх и способен прыгнуть вверх не более, чем на M ступенек.
//Определить, сколькими способами кузнечик может допрыгать да самой верхней ступеньки.
//1≤M≤N≤30

//Input format   N M - количество ступенек в лестнице и наибольший размер прыжка кузнечика.
//Output format  R - число способов, которыми кузнечик может допрыгать до самой верхней ступеньки.
//   Examples
//Input  Output
//5 2    8

#include <stdio.h>
#include <memory.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	auto mas = new int[++N];
	memset(mas, 0, sizeof(int)*N);
	mas[0] = 1;
	for (int i = 0; i < N; ++i) {
		int j = 1;
		while (j <= M && i - j >= 0) {
			mas[i] += mas[i - j];
			++j;
		}
	}
	printf("%d", mas[N - 1]);
	delete[] mas;
	return 0;
}
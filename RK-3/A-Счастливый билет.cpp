//Билет состоит из чётного числа N цифр в M-ричной системе счисления. Счастливым билетом называется билет, сумма первой половины цифр которого равна сумме второй половины цифр.
//Найти количество счастливых билетов. Так как их число может быть велико, вывести остаток от деления результата на MOD.

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int main() {
	size_t N, M, MOD;
	scanf("%d %d %d", &N, &M, &MOD);
	size_t sum = 0;
	auto mas = new size_t*[N / 2 * sizeof(size_t)];
	for (auto i = 0; i < N / 2; ++i) {
		mas[i] = new size_t[N * M / 2 * sizeof(size_t)];
		memset(mas[i], 0, N * M / 2 * sizeof(size_t));
	}
	for (auto i = 0; i < N * M / 2; ++i) {
		if (i < M) mas[0][i] = 1;
		else mas[0][i] = 0;
	}
	for (auto i = 1; i < N / 2; ++i) {
		for (auto j = 0; j < N * M / 2; ++j) {
			for (auto k = j; k > j - M && k >= 0; --k) {
				mas[i][j] += mas[i - 1][k];
				mas[i][j] = mas[i][j] % MOD;
			}
		}
	}
	for (auto i = 0; i < N * M / 2; ++i) {
		sum += mas[N / 2 - 1][i] * mas[N / 2 - 1][i];
		if (sum > MOD) sum = sum % MOD;
	}
	printf("%lu", sum);
	return 0;
}

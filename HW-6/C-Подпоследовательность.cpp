//На вход подаются числа N, M ≤ 105 и последовательности целых чисел x и y длины N и M соотвествтенно.
//Необходимо проверить, является ли последовательность y подпоследовательностью последовательности x.

#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	if (M > N) {
		printf("no");
		return 0;
	}
	int *mas = new int[N];
	for (int i = 0; i < N; ++i) {
		scanf("%d", &mas[i]);
	}
	int pos = 0;
	for (int i = 0; i < M; ++i) {
		int tmp;
		scanf("%d", &tmp);
		while (tmp != mas[pos]) {
			++pos;
			if (pos == N) {
				printf("no");
				delete[] mas;
				return 0;
			}
		}
		++pos;
		if (M - pos > N - i || (pos == N && i < M-1)) {
			printf("no");
			delete[] mas;
			return 0;
		}
	}
	printf("yes");
	delete[] mas;
	return 0;
}
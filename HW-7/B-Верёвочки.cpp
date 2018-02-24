//В ось X вбито N гвоздей.Требуется соединить эти гвозди верёвочками так, чтобы у каждого гвоздя была хотя бы одна верёвочка и чтобы сумма всех верёвочек была минимальной.
//2 < = N < = 10000 - 40000 < = Xi < = 40000
//Пример: для данных
//4
//5 3 8 9
//ответом будет 3, так как соединяются 5 и 3 а также 8 и 9.

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main() {
	int N;
	scanf("%d", &N);
	int *mas = new int[N];
	int *ans = new int[N - 1];
	for (int i = 0; i < N; ++i) {
		scanf("%d", &mas[i]);
	}
	std::sort(mas, mas + N);
	ans[0] = mas[1] - mas[0];
	ans[1] = mas[2] - mas[1] + ans[0];
	for (int i = 2; i < N - 1; ++i) {
		ans[i] = std::min(ans[i - 1], ans[i - 2]) + mas[i + 1] - mas[i];
	}
	printf("%d", ans[N - 2]);
	delete[] mas;
	delete[] ans;
	return 0;
}
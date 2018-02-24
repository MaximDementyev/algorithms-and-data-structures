//На вход подаётся число N — необходимо вывести число слов длины N над алфавитом{ 0, 1 }, в которых нет двух единиц подряд.Например все такие строки длины 3:
//000, 001, 010, 100, 101
//Input format    N – длина строки
//Output format   M – число слов длины N без двух единиц подряд
//    Examples
//Input   	Output
//3         5


#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned N;
	scanf("%d", &N);
	unsigned long long *mas = new unsigned long long[N];
	mas[0] = 2;
	mas[1] = 3;
	for (unsigned i = 2; i < N; ++i) {
		mas[i] = mas[i - 1] + mas[i - 2];
	}
	printf("%llu", mas[N - 1]);
	delete[] mas;
	return 0;
}
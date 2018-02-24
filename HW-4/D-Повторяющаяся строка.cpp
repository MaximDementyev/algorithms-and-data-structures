//Была исходная строка длины 2 ≤ L ≤ 150000. К ней многократно приписали её же справа и из полученной строки в произвольном месте вырезали фрагмент.
//Нужно найти наименьшую из возможных длину исходной строки.

#include<stdlib.h>
#include<stdio.h>
#include<memory.h>


int main() {
	int mas[150000];
	memset(mas, 0, sizeof mas);
	++mas[0];
	register char first = getchar();
	register int size = 0;
	for (char c = getchar(); c != '\n' && c != EOF; c = getchar()) {
		if (c == first)	mas[++size]++;
		else ++mas[size];
	}
	++size;
	int pos = 0;
	while (mas[0] != mas[pos++] && pos<size) {
		;
	}
	int i = pos, j = 0;
	while (j + i < size - 1) {
		if (mas[j] != mas[j + i]) {
			i = j + i + 1;
			j = -1;
		}
		++j;
	}
	if (mas[j] < mas[j + i]) i = j + i + 1;
	register int sum = 0;
	for (register int n = 0;n < i;++n) {
		sum += mas[n];
	}
	printf("%d\n", sum);
	return 0;
}
//Натуральные числа от 1 до N упорядочены лексикографически.
//Например, для N=25 результат этого упорядочения будет таким: 1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 20, 21, 22, 23, 24, 25, 3, 4, 5, 6, 7, 8, 9.
//Требуется написать программу, которая определит, на каком месте оказалось число K.
//Input format
//Вход содержит два натуральных числа N и K, записанных через пробел(1 ≤ K ≤ N ≤ 3·107).
//Output format
//Выход должен содержать одно натуральное число – номер места, на котором оказалось число K.
//Examples
//Input	  Output
//25 11   3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>

int main()
{
	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);
	N++;
	int k[8];
	for (int i = 0; i < 8; i++) {
		int dec = 10000000;
		int j = 7, pos = K;
		while (pos % dec == pos) {
			k[j--] = -1;
			dec /= 10;
		}
		while (j >= 0) {
			k[j--] = pos % 10;
			pos = pos / 10;
		}
	}
	time_t start = clock();
	//сортируем по первому символу
	int sort_mas[11];
	memset(sort_mas, 0, 11 * sizeof(int));
	/*for (int i = 0; i < 11; i++) {
		sort_mas[i] = 0;
	}*/
	int dec = 10;
	for (int i = 1; i < N; i++) {
		if (i == dec) dec *= 10;
		sort_mas[i/(dec/10)+1] += 1;
	}
	//суммируем все числа что начинаются  с меньшей цифры
	int res = 0;
	for (int i = 0;i <= k[0];i++) {
		res += sort_mas[i];
	}
	int size = sort_mas[k[0] + 1];

	//создаём массив чисел которые начинаются с заданной цифры
	int *mas = new int[size];
	int j = 0;
	for (int i = 1;i < N;i++) {
		int tmp = i;
		while (tmp >= 10) {
			tmp /= 10;
		}
		if (tmp == k[0]) {
			mas[j++] = i;
		}
	}

	//выравниваем числа по левому краю
	int *mas2 = new int[size];
	for (int i = 0;i < size;i++) {
		int dec = 10000000;
		if (mas[i] != 0) {
			while (mas[i] / dec == 0) {
				mas[i] *= 10;
			}
		}
	}
	std::sort(mas, mas + size);
	dec = 10000000;
	auto left_K = K;
	while (left_K / dec == 0) {
		left_K *= 10;
	}
	//ищем наше число
	for (int i = 0;i < size;i++) {
		if (left_K == mas[i]) {
			res += i;
			break;
		}
	}
	//осталось учесть нули в конце числа
	while (K % 10 == 0) {
		K /= 10;
		++res;
	}
	res++;
	delete[] mas;
	printf("%d", res);
	return 0;
}

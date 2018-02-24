//Поиск числа в таблице
//На вход задачи подаётся число N, числовой двумерный массив a размера N × N и число x.
//Массив a обладает следующим свойством : a[i, j] ≤ a[i  + 1, j], a[i, j] ≤ a[i, j  + 1].
//Необходимо проверить, встречается ли элемент x в массиве a.

#include <stdio.h>

bool find(int **mas, unsigned i, unsigned left, unsigned right, int x) {
	if (right - left <= 1) {
		if (x == mas[i][left] || x == mas[i][right]) return true;
		else return false;
	}
	unsigned mid = (right + left) / 2;
	if (mas[i][mid] == x) return true;
	bool solve = false;
	if (mas[i][(right - left) / 2] > x) 
		solve = find(mas, i, left, mid -1, x);
	else 
		solve = find(mas, i, mid +1,right, x);
	return solve;
}

int main() {
	unsigned size;
	scanf("%d", &size);
	int **mas = new int*[size];
	for (unsigned i = 0; i < size; i++) {
		mas[i] = new int[size+2];
	}
	for (unsigned i = 0; i < size;i++) {
		for (unsigned j = 0; j < size; j++) {
			scanf("%d", &mas[i][j]);
		}
	}
	int x;
	scanf("%d", &x);
	bool solve = false;
	for (unsigned i = 0; i < size; i++) {
		if (x < mas[i][0]) break;
		if (x <= mas[i][size - 1]) {
			solve = find(mas, i, 0, size-1, x);
			if (solve == true) break;
		}
	}
	if (solve == true) printf("yes");
	else printf("no");
	for (unsigned i = 0; i < size; i++) {
		delete[] mas[i];
	}
	delete[] mas;
	return 0;
}
//На вход подаётся строка, состоящая из букв A-Z. Необходимо вывести все буквы, которые встречаются в строке в порядке убывания частот вместе с частотой.
//В случае равенства частот первой должна идти буква, которая встречается в алфавите раньше.

#include<stdio.h>
#include<stdlib.h>

template <typename T>
void swap(T *arr, const int a, const int b) {
	T tmp;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int main()
{
	int mas[26];
	char alf[26];
	alf[0] = 'A';alf[1] = 'B';alf[2] = 'C';alf[3] = 'D';alf[4] = 'E';alf[5] = 'F';alf[6] = 'G';alf[7] = 'H';alf[8] = 'I';alf[9] = 'J';
	alf[10] = 'K';	alf[11] = 'L';alf[12] = 'M';alf[13] = 'N';alf[14] = 'O';alf[15] = 'P';alf[16] = 'Q';alf[17] = 'R';alf[18] = 'S';alf[19] = 'T';
	alf[20] = 'U';	alf[21] = 'V';alf[22] = 'W';alf[23] = 'X';alf[24] = 'Y';alf[25] = 'Z';
	for (int i = 0;i < 26;i++) {
		mas[i] = 0;
	}
	for (int c = getchar(); c != '\n' && c != EOF; c = getchar()) {
		mas[c - 'A']++;
	}
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 25; i++) {
			if (mas[i] < mas[i + 1]) {
				swap(mas, i, i + 1);
				swap(alf, i, i + 1);
				sorted = false;
			}
		}
	}
	for (int i = 0;i < 26;i++) {
		if (mas[i] == 0) break;
		printf("%c %d\n", alf[i], mas[i]);
	}
    return 0;
}


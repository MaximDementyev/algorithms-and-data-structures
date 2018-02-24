//На вход подаются два слова длины не более 1000, необходимо найти расстояние редактирования между ними. Расстояние редактирования определяется следующим образом: 
//два слова записывают одно под другим и добиваются их выравнивания путём добавления разделителя использование разделителя и несовпадение двух букв в одной позиции считается за штраф,
//— таким образом, расстояние редактирования — это минимальная величина штрафа.

//Input format     первое слово второе слово
//Output format    расстояние редактирования

#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include <algorithm>
#include <string>
using namespace std;


int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	const auto size1 = s1.size(), size2 = s2.size();
	auto mas = new int*[size1];
	for (auto i = 0; i < size1; ++i) {
		mas[i] = new int[size2];
		mas[i][0] = i;
	}
	for (auto i = 1; i < size2; ++i) {
		mas[0][i] = i;
	}
    for (auto i = 1; i < size1; ++i) {
	    for (auto j = 1; j < size2; ++j) {
		    if (s1[i] != s2[j])
				mas[i][j] = min(mas[i][j - 1], min(mas[i - 1][j], mas[i - 1][j - 1])) + 1;
			else mas[i][j] = mas[i - 1][j - 1];
	    }
    }
	printf("%d", mas[size1 - 1][size2 - 1]);
	for (auto i = 0; i < size1; ++i) {
		delete[] mas[i];
	}
	delete[] mas;
	return 0;
}
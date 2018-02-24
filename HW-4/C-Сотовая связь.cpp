//В городе имеется несколько операторов мобильной связи, каждый из которых располагает несколькими вышками. У каждой вышки свои координаты и своя зона уверенного приёма.
//Абонент находится в точке с заданными координатами. Требуется определить количество операторов мобильной связи в городе и определить, для скольких вышек у абонента, находящегося в данной точке, имеется устойчивая связь.
//В первой строке входного файла содержится целое число N(1 ≤ N ≤ 10000 — количество базовых станций.
//Далее следует N пар строк, в первой строке содержится имя оператора, во второй — два целых числа с координатами станции Xi и Yi(-10000 ≤ Xi, YI ≤ 10000), за которыми следует целочисленный радиус уверенного приёма Ri(1 ≤ Ri ≤ 10000).
//В последней строке — координаты абонента Xa и Ya.
//Названия операторов — строки, не содержащие пробелов и состоящие из букв латинского алфавита и цифр.
//В первой строке выходного файла нужно вывести количество операторов K, K ≤ 1000.
//В следующих K строках требуется вывести название оператора(в порядке их появления во входном файле) и через пробел количество базовых станций, доступных для абонента.
/*	Input format
 N
 name1
 X1 Y1 R1
 ...
 namen
 Xn Yn Zn
 Xa Ya
	Output format
 K
 name1 c1
 name2 c2
 ...
 nameK cK
	            Examples
 Input		                    Output
 8                              6
 Merizon                        Merizon 1
 -7 -5 2                        K-Mobile 0
 K-Mobile                       BTT 0
 -3 -5 4                        WarpLine 0
 BTT                            Telephone 0
 -2 -4 2                        Near2 0
 WarpLine
 -1 -4 5
 Telephone
 -4 -6 2
 BTT
 -1 -6 4
 Near2
 -6 -2 4
 Merizon
 7 7 6
 3 5*/

#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

struct coord {
	int x;
	int y;
};

struct tower {
	string name;
	coord point;
	int R;
	int pos;
};

bool norm(tower tow, coord point) {
	if ((tow.point.x - point.x)*(tow.point.x - point.x) + (tow.point.y - point.y)*(tow.point.y - point.y) < tow.R*tow.R)
		return true;
	else return false;
}

int main() {
	unsigned N;
	scanf("%d", &N);
	string *name = new string[N];
	tower *tow = new tower[N];
	unsigned pos=0;
	for (unsigned i = 0; i < N;++i) {
		cin >> tow[i].name;
		scanf("%d %d %d", &tow[i].point.x, &tow[i].point.y, &tow[i].R);
		bool flag = false;
		if (pos > 0) {
			for (unsigned j = 0;j < pos;++j) {
				if (tow[i].name == name[j]) {
					flag = true;
					tow[i].pos = j;
					break;
				}
			}
			if (flag == false) {
				name[pos] = tow[i].name;
				tow[i].pos = pos++;
			}
		}else{
			name[pos] = tow[i].name;
			tow[i].pos = pos++;
		}
	}
	coord find;
	scanf("%d %d", &find.x, &find.y);
	unsigned *kol = new unsigned[pos];
	for (unsigned i = 0; i < pos;++i) {
		kol[i] = 0;
	}
	for (unsigned i = 0; i < N; ++i) {
		if (norm(tow[i], find) == true) {
			kol[tow[i].pos]++;
		}
	}
	printf("%d\n", pos);
	for (unsigned i = 0; i < pos; ++i) {
		printf("%s ", name[i].c_str());
		printf("%d\n", kol[i]);
	}
	delete[] tow;
	delete[] name;
	delete[] kol;
	return 0;
}
//Имеется массив из N целочисленных точек на плоскости.
//Требуется найти периметр наименьшего охватывающего многоугольника, содержащего все точки.
//Input format
//5 ≤ N ≤ 500000
//- 10000 ≤ xi, yi ≤ 10000
//Output format
//Одно вещественное число — периметр требуемого многоугольника с двумя знаками после запятой.
//Examples
//Input	Output
//5     5.66
//2 1
//2 2
//2 3
//3 2
//1 2


#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct point {
	int x;
	int y;
};

bool sort_function(point a, point b) {
	if (a.x != b.x)  return (a.x<b.x);
	else return (a.y<b.y);
}

double norm(point a, point b) {
	return(sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

double calc_a(point z1, point z2) {
	return  (double)(z1.y - z2.y) / (z1.x - z2.x);
}
double calc_b(point z1, double a) {
	return z1.y - z1.x*a;
}

int main() {
	int size;
	scanf("%d", &size);
	point *mas = new point[size];
	point *help_mas_top = new point[size];
	point *help_mas_bottom = new point[size];
	point max, min;
	for (int i = 0;i < size;i++) {
		scanf("%d %d", &mas[i].x, &mas[i].y);
		if (i != 0) {
			if (mas[i].y > max.y) max = mas[i];
			if (mas[i].y < min.y) min = mas[i];
		}
		else {
			max = mas[i];
			min = mas[i];
		}
	}
	sort(mas, mas + size, sort_function);

	point top, bottom;
	point left = mas[0], right = mas[size - 1];

	int k = 0;
	bool flag_top = false;
	for (int i = 0; i < size; i++) {
		if (mas[i].y == max.y) {
			if (flag_top == false) {
				top = mas[i];
				flag_top = true;
			}
		}
		if (mas[i].y == min.y) bottom = mas[i];
	}

	double a, b;

	//1
	k = 0;
	point pos = left;
	help_mas_bottom[0] = left;
	int j = 1;
	if (pos.x - bottom.x != 0) {
		a = calc_a(pos, bottom);
		b = calc_b(pos, a);
		while (mas[k].x < bottom.x) {
			if (mas[k].y < a * mas[k].x + b) {
				pos = mas[k];
				help_mas_bottom[j++] = mas[k];
				a = calc_a(pos, bottom);
				b = calc_b(pos, a);
			}
			k++;
		}
	}

	//2
	pos = bottom;
	if (left.x != bottom.x || left.y != bottom.y) help_mas_bottom[j++] = bottom;
	if (pos.x - right.x != 0) {
		a = calc_a(pos, right);
		b = calc_b(pos, a);
		while (mas[k].x < right.x) {
			if (mas[k].y < a * mas[k].x + b) {
				pos = mas[k];
				help_mas_bottom[j++] = mas[k];
				a = calc_a(pos, right);
				b = calc_b(pos, a);
			}
			k++;
		}
		if (mas[k].y != right.y) help_mas_bottom[j++] = mas[k];
	}
	help_mas_bottom[j++] = right;
	int size_bottom = j;

	//3
	k = size - 1;
	j = 0;
	pos = right;
	help_mas_top[j++] = right;
	if (pos.x - top.x != 0) {
		a = calc_a(pos, top);
		b = calc_b(pos, a);
		while (mas[k].x > top.x) {
			if (mas[k].y > a * mas[k].x + b) {
				pos = mas[k];
				help_mas_top[j++] = mas[k];
				a = calc_a(pos, top);
				b = calc_b(pos, a);
			}
			k--;
		}
	}

	//4
	pos = top;
	if (right.x != top.x || right.y != top.y) help_mas_top[j++] = top;
	if (pos.x - left.x != 0) {
		a = calc_a(pos, left);
		b = calc_b(pos, a);
		while (mas[k].x > left.x) {
			if (mas[k].y > a * mas[k].x + b) {
				pos = mas[k];
				help_mas_top[j++] = mas[k];
				a = calc_a(pos, left);
				b = calc_b(pos, a);
			}
			k--;
		}
		if (mas[k].y != left.y) help_mas_top[j++] = mas[k];
	}
	help_mas_top[j++] = left;
	int size_top = j;


	double res = 0;
	bool solve;

	//1
	pos = left;
	k = 1;
	point find = help_mas_bottom[k];
	if (size_bottom > 0) {
		a = calc_a(pos, find);
		b = calc_b(pos, a);
		while (pos.x < right.x) {
			solve = true;
			j = k + 1;
			while (j < size_bottom) {
				if (help_mas_bottom[j].y < a * help_mas_bottom[j].x + b) {
					solve = false;
					break;
				}
				j++;
			}
			if (solve == false) {
				find = help_mas_bottom[k + 1];
				a = calc_a(pos, find);
				b = calc_b(pos, a);
			} else {
				res += norm(pos, find);
				pos = find;
				find = help_mas_bottom[k + 1];
				a = calc_a(pos, find);
				b = calc_b(pos, a);
			}
			k++;
		}
		res += norm(pos, right);
	}


	//3
	pos = right;
	k = 1;
	find = help_mas_top[k];
	if (size_top > 0) {
		a = calc_a(pos, find);
		b = calc_b(pos, a);
		while (pos.x > left.x) {
			solve = true;
			j = k + 1;
			while (j < size_top) {
				if (help_mas_top[j].y > a * help_mas_top[j].x + b) {
					solve = false;
					break;
				}
				j++;
			}
			if (solve == false) {
				find = help_mas_top[k + 1];
				a = calc_a(pos, find);
				b = calc_b(pos, a);
			} else {
				res += norm(pos, find);
				pos = find;
				find = help_mas_top[k + 1];
				a = calc_a(pos, find);
				b = calc_b(pos, a);
			}
			k++;
		}
		res += norm(pos, left);
	}

	printf("%.2lf", res);
	delete[] mas;
	delete[] help_mas_bottom;
	delete[] help_mas_top;
	return 0;
}
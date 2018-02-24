//У покупателя имеется набор N монет A1 ≤ A2 ≤ ... ≤ AN, каждой монеты ровно по одной штуке.
//Найти наименьшую стоимость предмета, который нельзя купить, используя только эти монеты.

#include "stdio.h"
int main() {
	int N, res = 1, tmp, i;
	scanf("%d", &N);
	for (scanf("%d", &tmp), i = 0; i < N && tmp <= res; scanf("%d", &tmp), ++i) res += tmp;
	printf("%d", res);
	return 0;
}
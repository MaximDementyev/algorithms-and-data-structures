//В стране начали строить железную дорогу, но в процессе постройки деньги внезапно кончились, из-за чего строительство было прервано,
//а через пару лет опять внезапно появились, из-за чего строительство решили возобновить, но с меньшим размахом.
//Успели построить только одноколейные дороги (дороги в одну сторону из пункта A в пункт B), при этом если из города A можно попасть в город B,
//то обратно по системе железных дорог попасть нельзя. Необходимо добавить минимальное число дорог так, чтобы из любого города можно было добраться до другого.

//Input format
//N ≤ 1000 – число городов
//N строк вида
//ai, 1 ai, 2 ... ai, N, где ai, j  = 1, если из города i есть дорога в город j, иначе ai, j  = 0
//Output format
//M – число дорог, которое необходимо добавить.

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class SET {
public:
	SET(unsigned size) {
		N_ = (size + 31u)>>5;
		body_ = new unsigned[N_];
		memset(body_, 0, N_ * sizeof(unsigned));
	}
	~SET() {
		delete[] body_;
	}
	int getbit(unsigned n) const {
		return(body_[n>>5]>>(n & 31)) & 1;
	}
	void setbit(unsigned n, bool val) const {
		if (val != 0) {
			body_[n>>5] |= (1<<(n % 31));
		}
		else body_[n>>5] &= ~(1<<(n % 31));
	}
private:
	unsigned N_;
	unsigned int* body_;
};


int main() {
	int N;
	scanf("%d", &N);
	int sum_str = 0, sum_stlb = 0;
	SET stlb(N);
	for (auto i = 0; i < N; ++i) {
		auto sum = false;
		for (auto j = 0; j < N; ++j) {
			int tmp;
			scanf("%d", &tmp);
			stlb.setbit(j, stlb.getbit(j) | tmp);
			sum = sum | tmp;
		}
		sum_str += sum;
	}
	for (auto i = 0; i < N; ++i) {
		sum_stlb += stlb.getbit(i);
	}
	printf("%d", std::max(N - sum_stlb, N - sum_str));
	return 0;
}
//сортировка RADIX

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>


const unsigned char mask = 255;
const int sdv = 8;


inline void clear_solve(int *solve, const int size) {
	memset(solve, 0, sizeof(solve[0])*size);
}

inline void filling_mas(const unsigned *mas, int *solve, int *put, const int N) {
	for (register int i = 0; i < N; ++i) {
		++solve[4*((mas[i])&mask)];
		++solve[(4*((mas[i] >> 8)&mask))+1];
		++solve[(4*((mas[i] >> 16)&mask))+2];
		++solve[(4*((mas[i] >> 24)&mask))+3];
	}
	put[0] = 0;
	put[1] = 0;
	put[2] = 0;
	put[3] = 0;
	for (register int i = 1; i < mask + 1; ++i) {
		put[4*i] = put[4*(i-1)] + solve[4 * (i - 1)];
		put[4*i + 1] = put[4*(i - 1)+1] + solve[4 * (i - 1) + 1];
		put[4*i + 2] = put[4*(i - 1)+2] + solve[4 * (i - 1) + 2];
		put[4*i + 3] = put[4*(i - 1)+3] + solve[4 * (i - 1) + 3];
	}
}
inline void radix(const unsigned *mas, unsigned *mas_help, int *put, const int j, const int N) {
	for (register int i = 0; i < N; ++i) {
		mas_help[put[4*((mas[i] >> (j*8)) & mask)+j]++] = mas[i];
	}
}



int main() {
	register unsigned N;
	unsigned K, L;
	unsigned long long M;
	scanf("%d %d %lld %d", &N, &K, &M, &L);
	unsigned *mas = (unsigned*)malloc(N * sizeof(unsigned));
	unsigned *mas_help = (unsigned*)malloc(N * sizeof(unsigned));
	
	
	mas[0] = K;
	for (register unsigned i = 1; i < N; ++i) {
		mas[i] = (unsigned)((mas[i - 1] * (unsigned long long)M)&0xFFFFFFFFU) % L;
	}

	int *solve, *put;
	solve = (int*)malloc((4 * (mask + 1)) * sizeof(int));
	put = (int*)malloc((4 * (mask + 1)) * sizeof(int));
	clear_solve(solve, 4*(mask + 1));
	filling_mas(mas, solve, put, N);
	for (register int j = 0;j <4;++j) {
		radix(mas, mas_help, put, j, N);
		unsigned *tmp = mas;
		mas = mas_help;
		mas_help = tmp;
	}
	free(solve);
	free(put);

	register unsigned sum = 0;
	for (register unsigned i = 0;i < N;i += 2) {
		sum = (sum + mas[i]);
		if (sum > L)sum %= L;
	}
	printf("%d", sum);
	free(mas);
	free(mas_help);
	return 0;
}

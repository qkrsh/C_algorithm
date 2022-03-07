#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void select_pq(int* p, int* q) {          // 1~100������ �Ҽ� 2���� ����
	int i, j;
	srand((unsigned)time(NULL));

	i = (rand() % 100) + 1;               //(0+1)~(99+1)���� ������ �ϳ� ����
	for (i; 1; i++) {
		for (j = 2; j <= i; j++) {
			if (i % j == 0)
				break;
		}
		if (j == i) {
			*p = i;
			break;
		}
	}
	i = (rand() % 100) + 1;
	for (i; 1; i++) {
		for (j = 2; j <= i; j++) {
			if (i % j == 0)
				break;
		}
		if (j == i) {
			*q = i;
			break;
		}
	}

}

int main() {
	int p, q;   //�Ҽ� 2��
	int n;      //n=p*q
	int Euler;
	int e;      //����Űe
	int d = 1;  //���Űd
	select_pq(&p, &q);
	//printf("%d, %d", p, q);
	n = p * q;
	Euler = (p - 1) * (q - 1);

	for (d; 1; d++) {
		e = (rand() % (Euler - 2)) + 2;  // 1 < e < Euler(n)
		int result;
		result = (d * e) % Euler;
		if (result == 1) {
			break;
		}
	}
	//printf("%d %d", e, d);
	printf("����Ű(%d, %d)\n���Ű(%d, %d)", e, n, d, n);

	return 0;
}

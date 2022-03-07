#include <stdio.h>

void EEA(int a, int b) {
	int ap = a, bp = b, x1 = 1, x2 = 0, y1 = 0, y2 = 1;
	int r, x, y;

	while (bp!=0) {
		(ap / bp)

		// gcd 계산
		r = ap % bp;
		ap = bp;
		bp = r;

		// x 계산
		x = x1 - (ap / bp) * x2;
		x1 = x2;
		x2 = x;

		// y 계산
		y = y1 - (ap / bp) * y2;
		y1 = y2;
		y2 = y;
	}

	r = ap, x = x1, y = y1;
	printf("%d  %d  %d\n", x, y, r);	
}

int main() {

	int a, b;
	scanf_s("%d %d", &a, &b);
	EEA(a,b);
}

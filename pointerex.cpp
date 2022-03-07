#include <stdio.h>

void calculate(int *n1, int *n2, int* re1, int* re2, int* re3, int* re4)
{
	*re1 = *n1 * *n2;
	*re2 = (double)(*n1) / *n2;
	*re3 = *n1 % *n2;
	*re4 = *n1 + *n2;
}

void main(void) {
		int N1 = 10;
		int	N2 = 12;
		int R1, R2, R3, R4;

		calculate(&N1, &N2, &R1, &R2, &R3, &R4);

		printf("%d*%d= %d\n%d/%d= %d\n%d%\%%d= %d \n%d+%d= %d\n\n", N1, N2, R1, N1, N2, R2, N1, N2, R3, N1, N2, R4);

		int N3 = 12000;
		int	N4 = 133;
		int T1, T2, T3, T4;

		calculate(&N3, &N4, &T1, &T2, &T3, &T4);

		printf("%d*%d= %d\n%d/%d= %d\n%d%\%%d= %d \n%d+%d= %d\n\n", N3, N4, T1, N3, N4, T2, N3, N4, T3, N3, N4, T4);

		int N5= -550;
		int	N6 = 12;
		int Q1, Q2, Q3, Q4=0;

		calculate(&N5, &N6, &Q1, &Q2, &Q3, &Q4);

		printf("%d*%d= %d\n%d/%d= %d\n%d%\%%d= %d \n%d+%d= %d\n\n", N5, N6, Q1, N5, N6, Q2, N5, N6, Q3, N5, N6, Q4);

	
}


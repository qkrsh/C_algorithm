#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 100

void merge(int* arr, int start, int mid, int end) {

	int i = start, j = mid + 1, k = 0;
	int* tmp = (int*)malloc(sizeof(int) * (end - start + 1));

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		}
		else {
			tmp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		tmp[k++] = arr[i++];
		}
	while (j <= end) {
	tmp[k++] = arr[j++];
	}

	for (int p = start; p <= end; p++) {
		arr[p] = tmp[p - start];
	}

	free(tmp);
	return;
}

void merge_sort(int* arr, int start, int end) { // T(N)
	if (start >= end) {  // (1)
		return;
	}
	merge_sort(arr, start, (start + end) / 2);  // T(N/2)
	merge_sort(arr, (start + end) / 2 + 1, end); // T(N/2)
	merge(arr, start, (start + end) / 2, end);  // cN

	return;
}

int main() {
	int a[N], i, j, t;

	for (i = 0; i < N; i++)
		a[i] = rand() % 32767;
	merge_sort(a, 0, N - 1);

	for (i = 0; i < N; i++) {
		printf("%8d", a[i]);
		if (i % 10 == 9)
			printf("\n");
	}

	return 0;
}

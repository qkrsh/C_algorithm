#include <stdio.h>
#define count 6

int main() {
	int arr[count] = { 7, 10, 2, 9, 4, 6 };

	for (int i = 1; i < count - 1; i++) {
		int a = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > a) {
			if (arr[j] > arr[j + 1]) {
				arr[j + 1] = arr[j];
				j--;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}
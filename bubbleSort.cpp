#include <stdio.h>
#define count 6

int main() {
	int arr[count] = { 7, 10, 2, 9, 4, 6 };
	int temp = 0;

	for (int i = 0; i<count-1; i++) {
		for (int j = 0; j < count-1-i; j++) {
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	
	}
	for (int i = 0; i < count; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}
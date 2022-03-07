#include <stdio.h>

void main() {
    while (1) {
      
        int i;
        int b = 0;
        int c = 0;
        int d = 0;
        printf("Type the number of students (End:'0'):");
        scanf_s("%d", &i);
        if (i == 0) break;
        int arr[100];
        int t = 0;

        for (int a = 1; a < i + 1; a++) {
            printf("%d-th money spent: ", a);
            scanf_s("%d", &b);
            arr[a - 1] = b;
            c = c + b;
        }
        int q = c / i;
        int p = 0;
        for (int k = 0; k < i; k++) {
            if (arr[k] > q) {
                p = arr[k] - q;
                t = t + p;
            }
        }
        printf("The money exchange is %d(Won)\n\n", t);
    }
}
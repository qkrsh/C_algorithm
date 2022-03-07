#include <string>
#include<iostream>
#include <stdio.h>
using namespace std;

int MaxIndex(int arr[], int endIndex) {
    int mi = 0;
    for (int i = 1; i <= endIndex; i++) {
        if (arr[i] > arr[mi]) {
            mi = i;
        }
    }
    return mi;
}

void flip(int arr[], int i, int end, int p) {
    int t = 0;
    int start = 0;
    if (start < i) {
        int z = 5 - i;
        printf("%d ", z);
    }

    while (start < i)
    {
        t = arr[start];
        arr[start] = arr[i];
        arr[i] = t;
        ++start;
        --i;
    }

    if (i < end) {
        int k = i + p + 1;
        printf("%d ", k);
        p++;
    }

    while (i < end)
    {
        t = arr[end];
        arr[end] = arr[i];
        arr[i] = t;
        --end;
        ++i;
    }
}

void Sort(int arr[]) {
    int endIndex = 4;
    int end = 4;
    int c = 1;
    int p = 0;
    while ((((arr[0] == 1) == true) & ((arr[1] == 2) == true) & ((arr[2] == 3) == true) & ((arr[3] == 4) == true) & ((arr[4] == 5) == true)) == false) {
        int mi = MaxIndex(arr, endIndex);
        if (mi != endIndex) {
            flip(arr, mi, end, p);
            endIndex = endIndex - 1;
            end = end - 1;
            p++;
        }
    }
    printf("%d", 0);
}

int main() {
    int arr[5];
    int count;
    int q;
    int a;
    count = sizeof(arr) / sizeof(arr[0]);
    while (1) {
        for (q = 0; q < count; q++) {
            scanf_s("%d", &arr[q]);
        }

        for (a = 0; a < count; a++) {
            printf("%d ", arr[a]);
        }
        printf("(%d %d %d %d %d)", 1, 2, 3, 4, 5);
        printf("\n");
        Sort(arr);
    }
}
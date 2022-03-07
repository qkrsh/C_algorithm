#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 


int subsequenceCount(char S[], char T[])
{
    int m = strlen(S);
    int n = strlen(T);

    int mat[20][20];

    for (int z = 0; z < m; z++) {
        mat[0][z] = 0;
    }

    for (int q = 0; q < m; q++) {
        mat[q][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j =1; j <= n; j++) {
            if (S[i - 1] == T[j - 1]) {
                mat[i][j] = mat[i-1][j] + mat[i - 1][j - 1];
            }
            else
                mat[i][j] = mat[i-1][j];
        }
    }
    return mat[m][n];
}

int main()
{
    int n;

    char T[10];
    char S[10];
    printf("Type the number of test sets: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Type sequence: ");
        scanf("%s", S);
        printf("Type sub-sequence: ");
        scanf("%s", T);
        printf("Result: %d\n", subsequenceCount(S, T));
    }
    return 0;
}
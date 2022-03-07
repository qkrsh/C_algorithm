#include<stdio.h>
#include<limits.h>
#define R 5
#define C 6

int min(int x, int y, int z);

int minCost(int cost[R][C], int m, int n)
{
    int a = m;
    int b = n;
    int i, j;
    int tc[R][C];

    tc[0][0] = cost[0][0];

    for (i = 0; i < m; i++)
        tc[i][0] = cost[i][0];

    for (j = 1; j < n; j++) {
        for (i = 0; i < m; i++) {
            if (i - 1 < 0) {
                tc[i][j] = min(tc[m - 1][j - 1],
                    tc[i][j - 1],
                    tc[i + 1][j - 1]) + cost[i][j];
            }
            else if (i + 1 > m - 1) {
                tc[i][j] = min(tc[i - 1][j - 1],
                    tc[i][j - 1],
                    tc[0][j - 1]) + cost[i][j];
            }
            else {
                tc[i][j] = min(tc[i - 1][j - 1],
                    tc[i][j - 1],
                    tc[i + 1][j - 1]) + cost[i][j];
            }
        }
    }

    return min(min(tc[0][n - 1], tc[1][n - 1], tc[2][n - 1]), min(tc[3][n - 1], tc[4][n - 1], 100), 100);

}


int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

int main()
{
    int m,n;
    scanf_s("%d %d",&m,&n);

    int cost[R][C];
    for (int i = 0; i < R;i++) {
        scanf_s("%d %d %d %d %d %d",&cost[i][0],&cost[i][1],&cost[i][2],&cost[i][3],&cost[i][4],&cost[i][5]);
    }

    printf("\n%d\n\n", minCost(cost, m, n));
    return 0;
}
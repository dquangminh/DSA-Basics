#include <stdio.h>
#define MAX 13

int n, m, mtx[MAX][MAX], count = 0;
bool x[MAX], mark[MAX], d1[2*MAX+1], d2[2*MAX+1];

void TRY(int k)
{
    int v;
    for (v = 1; v <=n; v++)
    if (mtx[k][v] == -1)
    if (!mark[v] && !d1[k-v+MAX] && !d2[k+v])
    {
        x[k] = v;
        mark[v] = true;
        d1[k-v + MAX] = true;
        d2[k+v] = true;
        if (k == n)
            count++;
        else
            TRY(k+1);
        d1[k-v+ MAX] = false;
        d2[k+v] = false;
        mark[v] = false;
    }
}

int main()
{
    int x, y;
    do
    {
        count = 0;
        scanf("%d %d", &n, &m);
        if (n == 0)
            return 0;
        for (int i = 1; i <= MAX; i++)
            mark[i] = false;
        for (int i = 1; i <= 2*MAX; i++)
        {
            d1[i] = false;
            d2[i] = false;
        }
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mtx[i][j] = -1;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            mtx[x][y] = 0;
        }
        TRY(1);
        printf("%d\n", count);
    } while (true);
}

#include <stdio.h>
#define MAX 4001
#define MAXM 200000
int main()
{
    bool **a = new bool*[MAX];
    for (int i = 0; i < MAX; i++)
    {
        a[i] = new bool[MAX];
        for (int j = 0; j < MAX; j++)
            a[i][j] = false;
    }

    int N, M;
    int u[MAXM];
    int v[MAXM];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u[i], &v[i]);
        a[u[i]][v[i]] = true;
    }
    int x, y;
    int res = 0;
    for (int i = 0; i < M; i++)
    {
        x = u[i];
        y = v[i];
        for (int j = y+1; j <= N; j++)
        if (a[x][j] == true && a[y][j]== true)
            res++;
    }
    printf("%d\n", res);
}

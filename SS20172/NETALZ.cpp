#include <stdio.h>
#include <queue>
#define MAXN 5001
#define MAXM 500000

using namespace std;

int N, M;
int head[MAXN];
int *adj = new int[2*MAXM];
int *u = new int[2*MAXM];
int *v = new int[2*MAXM];

int BFS_VISIT(int s)
{
    int d[MAXN];
    bool mark[MAXN];
    for (int i = 1; i <= N; i++)
    {
        mark[i] = false;
        d[i] = 0;
    }
    mark[s] = true;
    queue<int> Q;
    Q.push(s);
    int x, y;
    while (!Q.empty())
    {
        x = Q.front();
        Q.pop();
        for (int i = head[x]; i < head[x+1]; i++)
        {
            y = adj[i];
            if (!mark[y])
            {
                mark[y] = true;
                d[y] = d[x] + 1;
                Q.push(y);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= N; i++)
    if (res < d[i])
        res = d[i];
    return res;
}
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < 2*M; i+= 2)
    {
        scanf("%d %d", &u[i], &v[i]);
        u[i+1] = v[i];
        v[i+1] = u[i];
    }

    for (int i = 0; i < 2*M; i++)
        head[u[i]]++;

    for (int i = 2; i <= N; i++)
        head[i] = head[i-1]+head[i];
    head[N+1] = 2*M;

    for (int i = 0; i < 2*M; i++)
        adj[--head[u[i]]] = v[i];

    int e, result = N;
    for (int i = 1; i <= N; i++)
    {
        e = BFS_VISIT(i);
        if (e < result)
            result = e;
        if (result == 2) // nho nhat co the
            break;
    }

    printf("%d\n", result);
}

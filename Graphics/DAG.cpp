#include<stdio.h>
#include<queue>
#include<vector>
#define MAX 1000
using namespace std;

int N, m, mark[MAX];
vector<int> A[MAX];
int idx;
int L[MAX];
int deg[MAX];

void readInput()
{
    scanf("%d", &N);
    scanf("%d", &m);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        A[u].push_back(v);
    }

    for (u = 1; u <= N; u++)
    for (vector<int>::iterator it = A[u].begin();
            it != A[u].end(); it++)
        {
            v = *it;
            deg[v]++;
        }
}

void TOPO_SORT()
{
    queue<int> Q;
    for (int i = 1; i <= N; i++)
    if (deg[i] == 0)
        Q.push(i);
    int u, v;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        L[idx++] = u;
        for (vector<int>::iterator it = A[u].begin();
            it != A[u].end(); it++)
            {
                v = *it;
                deg[v]--;
                if (deg[v] == 0)
                    Q.push(v);
            }
    }
    if (idx == N)
    {
        printf("YES\n");
        for (int i = 0; i < N; i++)
            printf("%d ", L[i]);
    }
    else
        printf("NO\n");

}

int main()
{
    readInput();
    idx = 0;
    TOPO_SORT();
}

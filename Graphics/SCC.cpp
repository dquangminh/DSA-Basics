#include <stdio.h>
#define MAXN 10004
#define MAXM 100005

bool mark[MAXN];
int scc[MAXN];
int u[MAXN], v[MAXN], adj[MAXM];
int n, m, k;
int head[MAXN];
int num_scc = 0;


void DFS(int u) {
    int t;
    for (int j = head[u]; j < head[u+1]; j++) {
        t = adj[j];
        if (!mark[t]) {
            mark[t] = true;
            scc[t] = num_scc;
            DFS(t);
        }
    }
}
int main() {

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u[i], &v[i]);
        head[u[i]]++;
    }
    for (int i = 2; i <= n; i++)
        head[i] = head[i-1] + head[i];
    for (int i = 0; i < m; i++)
        adj[--head[u[i]]] = v[i];
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            num_scc++;
            scc[i] = num_scc;
            mark[i] = true;
            DFS(i);
        }
    }
    printf("%d\n", num_scc);
    for (int i = 1; i <= n; i++) {
        printf("%d ",scc[i]);
    }
}

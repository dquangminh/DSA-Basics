#include <stdio.h>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX 100002


using namespace std;

int n, m, k;
int u[MAX], v[MAX], w[MAX];
int head[MAX], head2[MAX];

void swap(int a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void qsort(int a[], int start, int end)
{
    if (start >= end)
        return;
    int index = rand() % (start-end) + start;
    int pivot = a[index];
    int k = start - 1;
    swap(a, index, end);
    for (int i = start; i < end; i++)
    if (a[i] < pivot)
    {
        k++;
        swap(a, i, k);

    }
    k++;
    swap(a, k, end);
    qsort(a, start, k-1);
    qsort(a, k+1, end);
}

int main () {
    int *adj = new int[MAX];
    int *adj2 = new int[MAX];
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u[i], &v[i]);
        head[u[i]]++;
        head2[v[i]]++;
    }
    for (int i = 0; i < k; i++)
        scanf("%d", &w[i]);
    for (int i = 2; i <= n; i++) {
        head[i] = head[i-1] + head[i];
        head2[i] = head2[i-1] + head2[i];
    }
    for (int i = 0; i < m; i++) {
        adj[--head[u[i]]] = v[i];
        adj2[--head2[v[i]]] = u[i];
    }
    head[n+1] = m;
    head2[n+1] = m;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++)
        printf("%d ", head[i]+1);
    printf("\n");
    for (int i = 1; i <= n; i++) {
        qsort(adj, head[i], head[i+1]-1);
        for (int j = head[i]; j < head[i+1]; j++)
            printf("%d ", adj[j]);
    }
    int t;
    for (int i = 0; i < k; i++) {
        t = w[i];
        printf("\n");
        qsort(adj2, head2[t], head2[t+1]-1);
        for (int j = head2[t]; j < head2[t+1]; j++)
            printf("%d ", adj2[j]);
    }
    return 0;
}


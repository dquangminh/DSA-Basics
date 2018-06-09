#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b

#define MAX 1000001

using namespace std;

int N, e[MAX], s[MAX];
long dp[2][MAX];

void swap(int i, int j)
{
    int tmp = e[i];
    e[i] = e[j];
    e[j] = tmp;
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void qsort(int a[], int start, int end)
{
    if (start >= end)
        return;
    int index = (start + end)/2;
    int pivot = a[index];
    int k = start - 1;
    swap(index, end);
    for (int i = start; i < end; i++)
    if (a[i] < pivot)
    {
        k++;
        swap(i, k);
    }
    k++;
    swap(k, end);
    qsort(a, start, k-1);
    qsort(a, k+1, end);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &s[i], &e[i]);
    qsort(e, 0, N-1);
    int e_t = e[N-1];
    for (int i = 0; i < 2; i++)
    for (int j = 0; j <= e_t; j++)
        dp[i][j] = 0;
    int index = 0;
    for (int i = 1; i <= e_t; i++) {
        if (i < e[index])
            dp[0][i] = dp[0][i-1];
        else {
            dp[0][i] = max(e[index] - s[index], dp[0][i-1]);
            index++;
        }
    }
    index = 1;
    for (int i = 1; i <= e_t; i++) {
        if (i < e[index])
            dp[1][i] = dp[1][i-1];
        else {
            if (dp[0][s[index]] > 0)
                dp[1][i] = max(dp[0][s[index]] + e[index] - s[index], dp[1][i-1]);
            index++;
        }
    }
    if (dp[1][e_t])
        printf("%ld\n", dp[1][e_t]);
    else
        printf("-1\n");
}

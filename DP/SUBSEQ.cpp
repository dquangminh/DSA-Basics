#include <stdio.h>
#define MAX 100001

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int a[MAX];
    long long sum[MAX];
    sum[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    int ans = 1, index = 0;

    for (int i = 2; i <= N; i++)
    if (a[i] <= M)
    {
        while (sum[i] - sum[index] > M)
            index++;
        ans += i - index;
    }
    else
        index = i;
    printf("%d\n", ans);
}

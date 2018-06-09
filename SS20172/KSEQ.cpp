#include <stdio.h>
#define MAX 1000000

int main()
{
    int N, K;
    int* a = new int[MAX];
    long *sum = new long[MAX];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    sum[0] = 0;
    for (int i = 0; i < K; i++)
        sum[0] += a[i];
    for (int i = 1; i < N-K; i++)
        sum[i] = sum[i-1] + a[i+K -1] - a[i-1];
    long result = 0;
    for (int i = 0; i < N-K; i++)
    if (result < sum[i])
        result = sum[i];
    printf("%ld\n", result);
}

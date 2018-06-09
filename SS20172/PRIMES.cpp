#include <stdio.h>
#define MAX 4001

int N, K;
int c = 0;
int p[MAX];
int x[11];
int sum = 0;
int result = 0;

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    for (int i = 2; i*i <= n; i++)
        if (n%i == 0)
            return false;
    return true;
}
void TRY(int k)
{
    int i;
    for (i = x[k-1]+1; i < c; i++)
    {
        x[k] = i;
        sum = sum + p[x[k]];
        if (sum == N)
            result++;

        if (k < K && sum < N)
                TRY(k+1);
        sum = sum - p[x[k]];
    }
}
int main()
{

    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++)
    if (isPrime(i))
        p[c++] = i;
    x[0] = -1;
    TRY(1);
    printf("%d\n", result);
}

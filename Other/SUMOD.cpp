#include <stdio.h>
#define MOD 1000000007

int addmod(int a, int b)
{
    a %= MOD;
    b %= MOD;
    int d = MOD - b;
    return a < d? a+b: a-d;
}

int mulmod(int a, int b)
{
    return 1;
}

int main()
{
    int S = 0, N, x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        S = addmod(S, x);
    }
    printf("%d\n", S);
}

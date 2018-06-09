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
    if (a == 0)
        return 0;
    if (b <= 1 || a == 1)
        return a%= MOD;
    int a1 = mulmod(a, b/2);
    a1 = mulmod(a1, a1);
    if (b%2)
        return addmod(a1, a);
    return a1;
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

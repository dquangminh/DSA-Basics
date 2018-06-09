#include <stdio.h>
#define MAX 1005
const long MOD = 1000000007;
int main ()
{
    long F[MAX];
    int N, K1, K2;
    scanf("%d %d %d", &N, &K1, &K2);
    F[0] = F[1] = 1;
    for (int i = 2; i <= K1; i++)
        F[i] = 0;
    for (int i = K1+1; i <= N+1; i++)
    {
        F[i] = 0;
        for (int j = K1; j <= K2 && i > j; j++)
        {
            F[i] += F[i-j-1];
            F[i] = F[i]%MOD;
        }
    }
    int res = (F[N] + F[N+1])% MOD;
    printf("%d\n", res);
}

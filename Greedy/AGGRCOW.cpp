#include <stdio.h>
#include <algorithm>
#define MAXN 100000
#define MAX 1000000001
int N, C;
int x[MAXN];

using namespace std;

bool check(int res, int N, int C)
{
    int tmp = x[0];
    int j = 1;
    if (tmp + (C-j)*res > x[N-1])
        return false;
    for (int i = 1; i < N; i++)
    {
        
        if (x[i] - tmp >= res)
        {
            j++;
            tmp = x[i];
            if (tmp + (C-j)*res > x[N-1])
                return false;
            if (j == C)
            return true;
        }
    }
    return false;
}
void proc(int N, int C, int minL, int maxL)
{
    int res;
    while (minL <= maxL)
    {
        res = (minL + maxL)/2;
        if (check(res, N, C))
                minL = res+1;
        else
            maxL = res-1;
    }
    res = maxL;
    if (check(minL, N, C))
        res = minL;
    printf("%d\n", res);
}

int main()
{
    int test;
    scanf("%d", &test);
    while(test-- > 0)
    {
        scanf("%d %d", &N, &C);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &x[i]);
        }
        sort(x, x+N);
        proc(N, C, 1, x[N-1] - x[0] + 1);
    }
}

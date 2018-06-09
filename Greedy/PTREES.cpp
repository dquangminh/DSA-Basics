#include <stdio.h>
#include <algorithm>
#define MAX 100000

using namespace std;
int main()
{
    int n, a[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int res = 1, j = 1;
    for (int i = n-1; i >= 0; i--)
    {
        a[i] += j++;
        if (res < a[i])
            res = a[i];
    }
    res++;
    printf("%d\n", res);
    return 0;

}

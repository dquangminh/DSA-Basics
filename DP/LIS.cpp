#include <stdio.h>
#define max(a, b) a>b?a:b

int main()
{
    int a[] = {3, 5, 1, 9, 2, 3, 4, 6, 10, 8};
    int l[50];
    int n = 10, ans = 0;
    l[n-1] = 1;
    for (int i = n-2; i >= 0; i--)
    {
        l[i] = 1;
        for (int j = i+1; j < n; j++)
        if (a[i] < a[j])
            l[i] = max(l[i], l[j]+1);
        if (l[i] > ans)
            ans = l[i];
    }
    printf("%d", ans);
    return 0;
}

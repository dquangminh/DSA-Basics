#include<stdio.h>
#define MAX 125250
int main()
{
    int **a = new int*[501];
    a[1] = new int[2*MAX+1];
    a[1][MAX + 1] = 1;
    for (int i = 2; i <= 500; i++)
    {
        a[i] = new int[2*MAX+1];
        for (int j = 0; j < 2*MAX + 1; j++)
        {
            a[i][j] = 0;
            if (j-i >= 0 && a[i-1][j-i])
                a[i][j] = 1;
            if (j+i <= 2*MAX && a[i-1][j+i])
                a[i][j] = 1;
        }
    }
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", a[x][y+MAX]);
    }
}

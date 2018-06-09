#include<stdio.h>
#define MAX 30
#define max(a, b) a>b?a:b

int x[3*MAX], y[3*MAX], z[3*MAX];
int n, m;

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int get_height_tower()
{
    int h[3*MAX], res = 0;
    for (int i = 0; i < m-1; i++)
    for (int j = i+1; j < m; j++)
    if (x[i] > x[j])
    {
        swap(x[i], x[j]);
        swap(y[i], y[j]);
        swap(z[i], z[j]);
    }
    for (int i = 0; i < m; i++)
    {
        h[i] = z[i];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        if (x[j] < x[i] && y[j] < y[i])
            h[i] = max(h[i], h[j] + z[i]);

        if (h[i] > res)
            res = h[i];
    }
    return res;
}

int main()
{
    int tmp, height, count = 0, a, b, c;
    do
    {
        scanf("%d", &n);
        if (n == 0)
            return 0;
        m = 0; count++;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (a > b)
                swap(a, b);
            if (a > c)
                swap(a, c);
            if (b > c)
                swap(b, c);

            z[m] = c; x[m] = a; y[m] = b;
            m++;
            z[m] = b; x[m] = a; y[m] = c;
            m++;
            z[m] = a; x[m] = b; y[m] = c;
            m++;
        }
        height = get_height_tower();
        printf("Case %d: maximum height = %d\n", count, height);

    } while (true);
    return 0;
}

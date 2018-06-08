#include <stdio.h>
#define MAX_M 11
#define MAX_N 31

int n, m;
bool mark1[MAX_M][MAX_N], mark2[MAX_N][MAX_N];
int max_loads, res;
int box[MAX_M][MAX_N];
int count[MAX_M];

bool check(int v, int k)
{
    if (!mark1[v][k]) // box[v] ko the chua k
        return false;
    int j;
    for (int i = 0; i < count[v]; i++)
    {
        j = box[v][i];
        if (mark2[j][k])
            return false;
    }

    return true;
}

void TRY(int k)
{
    int v;
    for (v = 0; v < m; v++)
    {
        if (check(v, k))
        {
            box[v][count[v]] = k;
            count[v]++;
            if (k == n)
            {
                max_loads = 0;
                for (int i = 0; i < m; i++)
                    if (count[i] > max_loads)
                        max_loads = count[i];
                if (max_loads < res)
                    res = max_loads;
            }
            else if (count[v] < res)
                TRY(k+1);
            count[v] --;
        }
    }
}
int main()
{
    int k, c_i;
    int x, y;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
    for (int j = 0; j <= n; j++)
        mark1[i][j] = false;

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &k);
        while (k-- > 0)
        {
            scanf("%d", &x);
            mark1[i][x] = true;
        }
    }

    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
        mark2[i][j] = false;

    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &x , &y);
        mark2[x][y] = true;
        mark2[y][x] = true;
    }

    for (int i = 0; i < m; i++)
        count[i] = 0;
    res = MAX_N;
    TRY(1);
    printf("%d\n", res);
    return 0;
}

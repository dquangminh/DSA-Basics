#include <stdio.h>
#define MAX 12
#define MAX_H 30
int H, W, n;
int h[MAX], w[MAX];
int M[MAX_H][MAX_H];
bool flag = false;
int xh[MAX_H];
int xw[MAX_H];

bool check(int k, int vh, int vw)
{
    if (vh+ h[k] > H)
        return false;
    if (vw+ w[k] > W)
        return false;
    for (int i =vh; i <vh+h[k]; i++)
    for (int j =vw; j <vw+w[k]; j++)
    if (M[i][j] == 1)
        return false;
    return true;
}

void mark(int k, int vh, int vw)
{
    for (int i =vh; i <vh+h[k]; i++)
    for (int j =vw; j <vw+w[k]; j++)
    {
        M[i][j] = 1;
    }
}

void unmark(int k, int vh, int vw)
{
    for (int i =vh; i <vh+h[k]; i++)
    for (int j =vw; j <vw+w[k]; j++)
    {
        M[i][j] = 0;
    }
}

void TRY(int k)
{
    if (flag == true)
        return;
    int vh, vw;
    for (vh = 0; vh < H; vh++)
    for (vw = 0; vw < W; vw++)
    if (check(k, vh, vw))
    {
        xh[k] = vh;
        xw[k] = vw;
        mark(k, vh, vw);
        if (k == n-1)
        {
            flag = true;
        }
        else
            TRY(k+1);
        unmark(k, vh, vw);
    }
}

int main()
{
    scanf("%d %d", &H, &W);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &h[i], &w[i]);
    }
    for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
        M[i][j] = 0;
    TRY(0);
    if (flag == true)
        printf("1\n");
    else
        printf("0\n");
}

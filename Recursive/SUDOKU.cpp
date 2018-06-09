#include <stdio.h>
#define MAX 10

int x[MAX][MAX], count = 0;

bool found = false;

void printSolution()
{
    printf("SUDOKU %d: \n", count);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", x[i][j]);
        printf("\n");
    }
}
bool check(int v, int r, int c)
{
    for (int i = 0; i < r; i++)
    if (x[i][c] == v)
        return false;
    for (int j = 0; j < c; j++)
    if (x[r][j] == v)
        return false;
    int I = r/3;
    int J = c/3;
    int i = r-3*I;
    int j = c-3*J;
    for (int i1 = 0; i1 < i; i1++)
    for (int j1 = 0; j1 < 3; j1++)
    if (x[3*I+i1][3*J + j1] == v)
        return false;

    for (int j1 = 0; j1 < j; j1++)
    if (x[3*I+i][3*J + j1] == v)
        return false;
    return true;
}

void TRY(int r, int c)
{
    if (found == true)
        return;

    int v;
    for (v = 1;  v <= 9; v++)
    {
        if (check(v, r, c))
        {
            x[r][c] = v;
            if (r == 8 && c == 8)
            {
                printSolution();
                count ++;
                found = true;
            }
            else if (c == 8)
                TRY(r+1, 0);
            else
                TRY(r, c+1);
        }
    }
}
int main()
{
    TRY(0,0);
}

#include <stdio.h>

int x[9][9];
bool mr[9][9];
bool mc[9][9];
int m[2][2][9];

int found, c_test = 1;

void printSolution()
{
    printf("Test case #%d: YES\n", c_test);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            printf("%d ", x[i][j]);
        printf("\n");
    }
}

int check_blocks(int X, int Y)
{
    int m[9];
    int v;
    for(int i=0; i<9; i++)
        m[i] = 0;
    for(int i=X*4; i<X*4+4; i++)
    for(int j=Y*4; j<Y*4+4; j++)
    {
        v = x[i][j];
        if(v == 0)
            continue;
        m[v]++;
        if(m[v]>2 && v!=0)
            return false;
    }
    return true;
}
bool check_col(int col)
{
    bool mc[9];
    for (int i = 0; i < 9; i++)
        mc[i] = false;
    int v;
    for(int i=0; i<8; i++)
    {
        v = x[i][col];
        if(v == 0)
            continue;
        if(mc[v] == true)
            return false;
        mc[v] = true;
    }
    return true;
}
bool check_row(int row)
{
    bool mr[9];
    for (int i = 0; i < 9; i++)
        mr[i] = false;
    int v;
    for (int i=0; i<8; i++)
    {
        v = x[row][i];
        if (v == 0)
            continue;
        if(mr[v] == true)
            return false;
        mr[v] = true;
    }
    return true;
}

bool checkSudoku()
{
    for (int row = 0; row < 8; row++)
        if (!check_row(row))
            return false;
    for (int col = 0; col < 8; col++)
        if (!check_col(col))
            return false;
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
        if (!check_blocks(i, j))
            return false;
    return true;
}

bool check(int v, int r, int c)
{
    if (mr[r][v] == true)
        return false;

    if (mc[c][v] == true)
        return false;
    int I = r/4;
    int J = c/4;
    if (m[I][J][v] >= 2)
        return false;
    return true;
}
void TRY(int r, int c)
{
    if (found == true)
        return;
    if (r == 8)
    {
        printSolution();
        found = true;
        return;
    }
    int v;
    if (x[r][c] != 0)
    {
        if (c == 7)
            TRY(r+1, 0);
        else
            TRY(r, c+1);
    }
    else
    for (v = 1; v <= 8; v++)
    {
        if (check(v, r, c))
        {
            x[r][c] = v;
            mr[r][v] = true;
            mc[c][v] = true;
            m[r/4][c/4][v]++;
            if (c == 7)
                TRY(r+1, 0);
            else
                TRY(r, c+1);
            mr[r][v] = false;
            mc[c][v] = false;
            m[r/4][c/4][v]--;
            x[r][c] = 0;
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    while (test-- > 0)
    {
        found = false;
        for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            mr[i][j] = false;
            mc[i][j] = false;
            x[i][j] = 0;
        }

        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        for (int t = 0; t < 9; t++)
            m[i][j][t] = 0;
        int v;
        for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            scanf("%d", &v);
            x[i][j] = v;
            mr[i][v] = true;
            mc[j][v] = true;
            m[i/4][j/4][v]++;
        }
        if (checkSudoku())
        {
            TRY(0, 0);
            if (found == false)
                printf("Test case #%d: NO\n", c_test);
        }
        else printf("Test case #%d: NO\n", c_test);
        c_test++;
    }
    return 0;
}


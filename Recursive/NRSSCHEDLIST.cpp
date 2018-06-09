#include <stdio.h>


int x[205],N,K1,K2;
char bin[205];
bool flag = false;
void printSolution(int k)
{
    int j = 0;
    for(int i=1; i<=k; i++)
    {
        if(x[i]== 0)
        {
            bin[j++]= '0';
        }
        else
        {
            for(int v=1; v<=x[i]; v++)
                bin[j++]= '1';
        }
    }
    printf("%s\n", bin);
}

void TRY(int k,int m) // k = 0 tai vi tri k dat 0 hoac k = v tuc co v so 1 tiep sau k
{
    if(m == N)
    {
        printSolution(k);
        flag = true;
        return;
    }
    if(x[k]==0)
    {
        int v;
        for( v = K1; v <= K2 && v+m <= N; v++)
        {
            x[k+1]=v;
            TRY(k+1,m+v);
        }
    }
    else
    {
        x[k+1]=0;
        if(N == k+1 || N-k-1 >= K1)
            TRY(k+1,m+1);
    }
}

int main()
{
    scanf("%d %d %d",&N,&K1,&K2);
    x[1]= 0;
    TRY(1, 1);
    for (int i = K1; i <= K2; i++)
    {
        x[1] = i;
        TRY(1, i);
    }
    if (flag == false)
        printf("-1");
}

#include<stdio.h>


int main()
{
    int a[6] = {500, 100, 50, 10, 5, 1};
    int n;
    scanf("%d", &n);
    int pay_back = 1000 - n;
    int j = 0, res = 0;
    while (pay_back > 0)
    {
        if (pay_back - a[j] >= 0)
        {
            pay_back -= a[j];
            res ++;
        }

        else
            j++;
    }
    printf("%d", res);

}

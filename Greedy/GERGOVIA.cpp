#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n != 0) 
    {
        int a;
        long long tmp = 0, result = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &a);
            result += tmp > 0? tmp : (-1)*tmp;
            tmp += a;
        }
        cout << result << endl;
        scanf("%d", &n);
    }

}

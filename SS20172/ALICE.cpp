#include<iostream>
#define MAX 100007
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long S[MAX];
    int a[MAX];
    int b[MAX];
    long res = 0;
    S[0] = 0;
    int c_m = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S[i] = S[i-1] + a[i];
        if (a[i] <= m)
            b[++c_m] = i;
    }
    b[0] = 0;
    b[c_m+1] = n+1;
    long t;
    for (int i = 1; i <= c_m; i++)
    {
        if (a[b[i]] == m)
        {
            t = S[b[i+1]-1]-S[b[i-1]];
            if (t > res)
                res = t;
        }
    }
    cout << res << endl;
}

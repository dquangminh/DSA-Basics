#include <stdio.h>
#include <string.h>
#define max(a, b) a>b?a:b


using namespace std;

int main()
{
    int test, res = 0;
    scanf("%d ", &test);
    char s1[5000], s2[5000];
    int **l = new int*[5001];

    for (int i = 0; i <= 5000; i++)
    {
        l[i] = new int[50001];
        for (int j = 0; j <= 5000; j++)
            l[i][j] = 0;
    }
    while (test-- > 0)
    {
        scanf("%s", s1);
        scanf("%s", s2);
        int n = strlen(s1), m = strlen(s2);
        for (int i = 1; i <= n; i++)
            l[i][0] = 0;
        for (int i = 1; i <= m; i++)
            l[0][i] = 0;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        if (s1[i-1] == s2[j-1])
            l[i][j] = l[i-1][j-1] + 1;
        else
            l[i][j] = max(l[i-1][j], l[i][j-1]);

        res = l[n][m];
        printf("%d\n", res);
    }
    return 0;
}

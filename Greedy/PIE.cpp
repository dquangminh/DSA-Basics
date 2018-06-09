    #include <stdio.h>
    #define M_PI 3.14159265358979323846
    #define MAX 10000
    #define eps 1e-7
    int N, F, r;
    double S[MAX], S_max = 0.0;
    bool check(double mid)
    {
        int friends = 0;
        double f;
        for (int i = 0; i < N; i++)
            {
                f = S[i]/mid;
                friends += (int) f;
            }
        if (friends > F)
            return true;
        return false;
    }

    void proc(double S_max)
    {
        double lo = 0.0, hi = S_max, mid;
        for (int i = 0; i < 100; i++)
        {
            mid = (hi+lo)/2.0;
            if (check(mid))
                lo = mid;
            else
                hi = mid;
        }
        printf("%.6f\n", mid);
    }

    int main()
    {
        int testcase;
        scanf("%d", &testcase);

        while (testcase-- > 0)
        {
            scanf("%d %d", &N, &F);
            for (int i = 0; i < N; i++)
                {
                    scanf("%d", &r);
                    S[i] = M_PI*r*r;
                    if (S[i] > S_max)
                        S_max = S[i];
                }
            proc(S_max);
        }
    }

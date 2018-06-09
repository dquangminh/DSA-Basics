#include <stdio.h>
#include <deque>
#define MAX 100000
using namespace std;

int main()
{
    int testcase;
    testcase = 1;
    deque<int> dq;
    long gold[MAX];
    long l[MAX];
    long ans;
    int a[MAX];
    int N, L1, L2, L;
    while (testcase-- > 0)
    {
        ans = 0;
        dq.clear();
        scanf("%d %d %d", &N, &L1, &L2);
        scanf("%d", &a[0]);
        l[0] = a[0];
        gold[0] = a[0];
        L = L2-L1+1;
        dq.push_back(0);
        for (int i = 1; i < N; i++) {
            scanf("%d", &a[i]);
            if (i < L1)
                gold[i] = a[i];
            else
                gold[i] = l[i-L1] + a[i];
            while (!dq.empty() && gold[i] >= gold[dq.back()])
                dq.pop_back();
            if (!dq.empty() && dq.front() <= i-L)
                dq.pop_front();
            dq.push_back(i);
            l[i] = gold[dq.front()];
            if (gold[i] > ans)
                ans = gold[i];
        }
        printf("%ld\n", ans);
    }

}

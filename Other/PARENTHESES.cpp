#include<stdio.h>
#include<stack>
#include<string.h>
#define MAX 1000
using namespace std;

int main()
{
    stack<char> st;
    int T, res[MAX];
    char c[100000];
    scanf("%d", &T);
    for (int c_t = 0; c_t < T; c_t++)
    {
        while (!st.empty())
            st.pop();
        scanf("%s", c);
        for (int i = 0; i < strlen(c); i++)
        {
            if (c[i] == '(' || c[i] == '{' || c[i] == '[')
                st.push(c[i]);
            else if ((c[i] == ')' && st.top() == '(')||
                     (c[i] == '}' && st.top() == '{')||
                     (c[i] == ']' && st.top() == '['))
                        st.pop();
            else
            {
                res[c_t] = 0;
                break;
            }
        }
        if (st.empty())
            res[c_t] = 1;
        else
            res[c_t] = 0;
    }
    for (int i = 0; i < T; i++)
        printf("%d\n", res[i]);
    return 0;
}

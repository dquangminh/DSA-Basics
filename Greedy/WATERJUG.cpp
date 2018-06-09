#include <stdio.h>
#include <deque>
#include <utility>
#include <set>
#define min(a,b) a<b?a:b

using namespace std;

int min_steps(int a_gallon, int b_gallon, int c_gallon)
{
    // su dung a lam binh lay nuoc
    // binh b nhan nuoc
    int steps = 1; // lam day binh a
    int a = a_gallon; // so nuoc o binh a
    int b = 0; // so nuoc binh b
    int lit; // so lit nuoc dc chuyen giua 2 binh
    while (a != c_gallon && b != c_gallon)
    {
        if (a == 0) // het nuoc
        {
            a = a_gallon; // lam day
            steps++;
        }
        if (b == b_gallon) // binh b da day -> do
        {
            b = 0;
            steps++;
        }

        lit = min(a, b_gallon - b); // so nuoc co the chuyen = min (binh a va phan rong cua b)
        steps++; // chuyen nuoc
        a -= lit;
        b += lit;

    }
    return steps;
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x%y);
}

int water_jug(int a_gallon, int b_gallon, int c_gallon)
{
    if ( c_gallon > a_gallon && c_gallon > b_gallon) // khong co binh nao chua dc
        {
            return -1;
        }

    if (c_gallon % gcd(a_gallon, b_gallon) != 0) {
        return -1;
    }

    if (c_gallon == a_gallon || c_gallon == b_gallon)
        return 1;
    return min(min_steps(b_gallon, a_gallon, c_gallon),
                min_steps(a_gallon, b_gallon, c_gallon));

}

int main()
{
    int t, a, b, c, minSteps;
    scanf("%d", &t);
    while (t > 0)
    {
        t--;
        scanf("%d %d %d", &a, &b, &c);
        minSteps = water_jug(a, b, c);
        printf("%d\n", minSteps);
    }
    return 0;
}

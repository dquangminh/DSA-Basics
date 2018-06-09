#include<stdio.h>
#include<iostream>
using namespace std;

typedef long long LL;

int so_cach[]= {1,1,1,1,2,1,2,1,1,3};
int so_to[]= {0,1,1,1,2,1,2,2,2,3};

void proc(LL w, int c)
{
    LL cach=1,to=0;
    int d;
    while (c > 0 && w > 0)
    {
        c--;
        d = w%10;
        w /= 10;
        to += so_to[d];
        cach *= so_cach[d];
    }

    if (w == 0)
    {
        cout << to << " " << cach << endl;
        return;
    }
    if (w%5 == 0)
    {
        // neu so tien chia het cho 5 thi chi co 1 cach voi so to min = w/5
        to += w/5;
    }
    else if (w%5 == 1)
    {
        // w = 6 co the tach ra bang 2 cach
        // neu w = 1 thi co 1 cach con w = 1+5 (6) +k*5 thi co 2 cach voi so to = w/5+1
        to += w/5 + 1;
        if (w != 1)
            cach *= 2;
    }
    else if (w%5 == 2)
    {
        // => w = 2 hay 2+5(7) +k+5 deu co 1 cach tach voi chung so to
        to += w/5 +1;
    }
    else if (w%5 == 3)
    {
        // tuong tu co w = 3 hoac 3+5 (8) + k*5 giong nhau
        to += w/5 +1;
    }
    else if (w%5 == 4)
    {
        to += w/5 +2;
        if (w != 4)
            cach*= 3;
        else
            cach*= 2;
    }
    cout << to << " " << cach << endl;
}
int main()
{
    int T;
    scanf("%d",&T);
    LL W;
    int c;
    for(int i=1;i<=T;i++)
    {
        cin >> W >> c;
        if(W%1000)
            cout << "0" << endl;
        else
        {
            W=W/1000;
            proc(W, c);
        }
    }
    return 0;
}

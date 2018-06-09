#include <stdio.h>
#define MAX 601
#define min(a, b) a<b?a:b
     
int main() {
    int W, H, N;
    int w[MAX][MAX];
    scanf("%d %d", &W, &H);
    scanf("%d", &N);
    for (int i = 1; i <= W; i++)
    for (int j = 1; j <= H; j++)
        w[i][j] = i*j;
    int a, b, w_min, h_min;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        w[a][b] = 0;
        if (a < w_min)
            w_min = a;
        if (b < h_min)
            h_min = b;
    }
    for (int x = w_min; x <= W; x++)
    for (int y = h_min; y <= H; y++) {
        for (int i = 1; i < x; i++)
            w[x][y] = min(w[x][y], w[x-i][y] + w[i][y]);
        for (int j = 1; j < y; j++)
            w[x][y] = min(w[x][y], w[x][y-j] + w[x][j]);
    }
    printf("%d", w[W][H]);
}
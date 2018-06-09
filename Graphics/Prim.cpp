#include <iostream>
#include <set>
#define MAX 10000

using namespace std;

struct Edge{
    int x;
    int w;
};

int N, M;
set<Edge*> A[MAX];// A[v] la tap cac canh (x,w) ke voi v: canh (v,x) co trong so w
set<int> S;// tap ung cu vien, ket nap dan vao cay khung (loi giai)
int d[MAX];
int near[MAX];

void input(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;// canh (u,v) co trong so w
        Edge* e = new Edge;
        e->x = v;
        e->w = w;
        A[u].insert(e);

        e = new Edge;
        e->x = u;
        e->w = w;
        A[v].insert(e);
    }
}
int selectMin(){
    int minD = 100000000;
    int sel_v = -1;
    for(set<int>::iterator q = S.begin(); q != S.end(); q++){
        int v = *q;
        if(d[v] < minD){
            sel_v = v;
            minD = d[v];
        }
    }
    return sel_v;
}
void solve(){
    int s = 1;// chon ngau nhien
    for(int v = 1; v <= N; v++)if(v != s)
        S.insert(v);
    for(int v = 1; v <= N; v++)if( v != s)
        d[v] = 100000000;
    for(set<Edge*>::iterator q = A[s].begin(); q != A[s].end(); q++){
        Edge* e = *q;
        int v = e->x;
        int w = e->w;
        d[v] = w;
        near[v] = s;
    }
    int W = 0;
    // LOOP
    while(S.size() > 0){
        int v = selectMin();
        W += d[v];
        S.erase(v);
        cout << "chon canh (" << v << "," << near[v] << ") trong so = " << d[v] << endl;
        for(set<Edge*>::iterator q = A[v].begin(); q != A[v].end(); q++){
            Edge* e = *q;
            int u = e->x;
            if(S.find(u) != S.end()){// kiem tra u co thuoc S hay khong
                int w = e->w;
                if(d[u] > w){
                    d[u] = w;
                    near[u] = v;
                }
            }
        }
    }
    cout << W;
}

int main(){
    input();
    solve();
}

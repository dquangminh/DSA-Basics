#include <iostream>
#include <fstream>
#include <set>
#include <stack>
#define MAX 90000

using namespace std;

struct Edge{
    int x;
    int w;
};

int N, M;
int NN;
set<Edge*> A[MAX];// A[v] la tap cac canh (x,w) ke voi v: canh (v,x) co trong so w
set<int> S;// tap ung cu vien, ket nap dan vao cay khung (loi giai)
int d[MAX];
int pred[MAX];
bool found[MAX];
int s,t;
int node[MAX];
int idx[MAX];
void swap(int i, int j){
    int tmp = d[i]; d[i] = d[j]; d[j] = tmp;

    tmp = node[i]; node[i] = node[j]; node[j] = tmp;
    idx[node[i]] = i; idx[node[j]] = j;
}
void printHeap(){
    for(int i = 1; i <= N; i++)
        cout << i << ": d[" << node[i] << "] = " << d[i] << ", node[" << i << "] = " << node[i] << ", idx = " << idx[node[i]] << endl;
    for(int i = N+1; i <= NN; i++)
        cout << "FIXED: " << i << ": " << " d[" << node[i] << "] = " << d[i] << ", node[" << i << "] = " << node[i] << ", idx = " << idx[node[i]] << endl;
    cout << "--------------------------------" << endl;

}

void heapify(int i, int n){
    int L = 2*i;
    int R = 2*i+1;
    int min = i;
    if(L <= n && d[L] < d[i]) min = L;
    if(R <= n && d[R] < d[min]) min = R;
    if(min != i){
        swap(i,min);
        //cout << "swap(" << i << "," << min << ")" << endl; printHeap();
        heapify(min,n);
    }
}
void buildHeap(){
    for(int i = N/2; i >= 1; i--)
        heapify(i,N);
}
void input(){
    cin >> N >> M;NN = N;
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
    cin >> s >> t;
}
void init(){
    for(int i = 1; i <= N; i++){
        node[i] = i;
        idx[i] = i;
    }
    for(int v = 1; v <= N; v++)
        d[v] = 100000000;
    d[idx[s]] = 0;
    //cout << "init, s = " << s << ", idx = " << idx[s] << ", d[" << idx[s] << "] = " << d[idx[s]] << endl;
    for(set<Edge*>::iterator q = A[s].begin(); q != A[s].end(); q++){
        Edge* e = *q;
        int v = e->x;
        int w = e->w;
        d[idx[v]] = w;
        //cout << "init, v = " << v << ", idx = " << idx[v] << ", d[" << idx[v] << "] = " << d[idx[v]] << endl;
        pred[v] = s;
    }
    buildHeap();
    //cout << "init heap" << endl; printHeap();
}
void upHeap(int i){
    int p = i;
    while(p/2 >= 1){
        if(d[p] < d[p/2]){
            swap(p,p/2);
            p = p/2;
        }else
            break;
    }
}
int selectMin(){
    int sel_v = node[1];
    swap(1,N);
    N = N-1;
    heapify(1,N);
    return sel_v;
}

void solve(){
    for(int v = 1; v <= N; v++)if(v != s)
        found[v] = false;
    found[s] = true;
    init();
    int s = selectMin();
    //printHeap();
    //return;

    // LOOP
    while(N > 0){
        int v = selectMin();
        //cout << "chon canh (" << v << "," << pred[v] << ") trong so = " << d[idx[v]] << endl;
        //printHeap();
        found[v] = true;
        for(set<Edge*>::iterator q = A[v].begin(); q != A[v].end(); q++){
            Edge* e = *q;
            int u = e->x;
            if(found[u] == false){// kiem tra u co thuoc S hay khong
                int w = e->w;
                if(d[idx[u]] > d[idx[v]] + w){
                    d[idx[u]] = d[idx[v]] + w;
                    pred[u] = v;
                    //cout << "update for " << u << ", idx[u] = " << idx[u] << ", d = " << d[idx[u]] << endl;
                    upHeap(idx[u]);
                }
            }
        }
        //cout << "after update d" << endl;
        //printHeap();
    }
    cout << "result = " << d[idx[t]] << endl;

    return;
    stack<int> path;
    int x = t;
    while(x != s){
        path.push(x);
        x = pred[x];
    }
    cout << s;
    while(!path.empty()){
        int x = path.top(); path.pop();
        cout << " --> " << x;
    }
}



int main(){
    input();
    solve();
}

#include <iostream>
#include <set>
#define MAX 100001

using namespace std;

// data structure for input graph
int N, M;
int u[MAX];
int v[MAX];
int c[MAX];

// data structure for disjoint-set
int rank[MAX];// rank[v] la rank cua set v
int p[MAX];// p[v] la cha cua v

void link(int x, int y){
    if(rank[x] > rank[y]) p[y] = x;
    else{
        p[x] = y;
        if(rank[x] == rank[y]) rank[y] = rank[y] + 1;
    }
}
void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
}
int findSet(int x){
    if(x != p[x])
        p[x] = findSet(p[x]);
    return p[x];
}

void input(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int iu,iv,iw;
        cin >> iu >> iv >> iw;// canh (u,v) co trong so w
        u[i] = iu;
        v[i] = iv;
        c[i] = iw;
    }
}
void swap(int&a, int&b){
    int tmp = a; a = b; b = tmp;
}
void swapEdge(int i, int j){
    swap(c[i],c[j]);
    swap(u[i],u[j]);
    swap(v[i],v[j]);
}
int partition(int L, int R, int index){
    int pivot = c[index];
    swapEdge(index,R);
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        if(c[i] < pivot){
            swapEdge(storeIndex,i);
            storeIndex++;
        }
    }
    swapEdge(storeIndex,R);
    return storeIndex;
}
void quickSort(int L, int R){
    if(L < R){
        int index = (L+R)/2;
        index = partition(L,R,index);
        if(L < index) quickSort(L,index-1);
        if(index < R) quickSort(index+1,R);
    }
}
void quickSort(){
    quickSort(0,M-1);
}
void solve(){
    for(int x = 1; x <= N; x++){
        makeSet(x);
    }
    quickSort();
    int rs = 0;
    int count = 0;
    for(int i = 0;i < M; i++){
        // xem xet canh (u[i],v[i])
        int ru = findSet(u[i]);
        int rv = findSet(v[i]);
        if(ru != rv){
            link(ru,rv);
            rs += c[i];
            count++;
            if(count == N-1) break;
        }
    }
    cout << rs;
}
int main(){
    input();
    solve();
}

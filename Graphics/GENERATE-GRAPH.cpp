#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 10000

int I[MAX];// tap cac dinh da o trong do thi
int E[MAX];// tap cac dinh ben ngoai do thi
int nI;// so phan tu cua tap I
int nE;// so phan tu cua tap E

vector<int> A[MAX];// A[v] la list cac dinh ke voi v

void printSet(int* S, int n){
    for(int i = 0; i < n; i++) cout << S[i] << " "; cout << endl;
}
void remove(int idx, int* S, int& n){
    S[idx] = S[n-1];
    n = n - 1;
}

void init(int n){
    nI = 0;
    nE = n;
    for(int i = 0; i < n; i++)
        E[i] = i+1;
}

bool checkConnect(int u, int v){
    if(A[u].size() < A[v].size()){
        for(int i = 0; i < A[u].size(); i++)
            if(v == A[u][i]) return true;
    }else{
        for(int i = 0; i < A[v].size(); i++)
            if(u == A[v][i]) return true;
    }
    return false;
}

void genGraph(char* fn, int n, int m){
    init(n);
    //cout << "Khoi tao" << endl;
    //printSet(E,nE);

    ofstream fo(fn);
    fo << n << " " << m << endl;

    int idx = rand()%nE;
    int s = E[idx];// lay phan tu ngau nhien trong tap E
    remove(idx,E,nE);
    nI++;
    I[nI-1] = s;

    while(nE > 0){
        idx = rand()%nE;
        s = E[idx];// lay phan tu ngau nhien thu idx tu tap E
        remove(idx,E,nE);

        idx = rand()%nI;
        int t = I[idx];// lay phan tu ngau nhien tu tap I
        cout << "them canh (" << s << "," << t << ")" << endl;

        int w = rand()%99+1;
        fo << s << " " << t << " " <<  w << endl;
        nI++;
        I[nI-1] = s;// phan tu thu idx cua tap E

        A[s].push_back(t);
        A[t].push_back(s);

        //cout << "I = ";printSet(I,nI);
        //cout << "E = "; printSet(E,nE);
    }

    // bo sung tiep m - (n-1) canh ngau nhien con lai
    for(int k = 1; k <= m-n+1; k++){
        bool ok = true;
        do{
            ok = false;
            int iu = rand()%nI;
            int iv = rand()%nI;
            if(iv != iu){
                int u = I[iu];
                int v = I[iv];
                if(!checkConnect(u,v)){
                    ok = true;
                    int w = rand()%99+1;
                    fo << u << " " << v << " " << w << endl;
                    cout << "Them canh " << k << "/" << (m-n+1) << ": (" << u << "," << v << ")" << endl;
                    A[u].push_back(v);
                    A[v].push_back(u);
                }
            }
        }while(!ok);
    }

    fo.close();
}

int main(){
    genGraph("graph-n10-m20.txt",10000,100000);
}

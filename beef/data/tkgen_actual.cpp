#include<iostream>
#include<vector>
#include<map>
#include<cassert>
#include<utility>
#define MAXN 100005
using namespace std;
const int MAXE = 200000;
int wL, wR;
int rng(int l, int r) {
    int res=rand()%(r-l+1);
    return(res + l);
}


class Graph {
    int N,M, wt[MAXN];
    map<int,int> adj[MAXN];
public:
    void setV(int v) {
        N=v;
        M=0;
        for (int i=1; i<=N; i++) {
            adj[i].clear();
        }
    }
    void add_edge(int u, int v, int w) {
        if (u<1 || v<1 || u>N || v>N || u == v || adj[u].find(v) != adj[u].end() || M == (int) 3e5) {return;}
        adj[u][v]=adj[v][u]=w;
        M++;
    }
    void output() {
        assert(M <= (int) 2e5);
        printf("%d %d\n", N, M);
        for (int i=1; i<=N; i++) {
            printf("%d",wt[i]);
            if (i == N) {printf("\n");}
            else {printf(" ");}
        }
        for (int i=1; i<=N; i++) {
            for (auto e: adj[i]) if (i < e.first) {
               printf("%d %d %d\n", i, e.first, e.second);
            }
        }
    }
    void generate_weights(int subtask) {
        int w_limit = 0;
        if (subtask == 1) {w_limit = 1;}
        else if (subtask == 3) {w_limit = 5;}
        else {w_limit = 1000000000;}
        for (int i=1; i<=N; i++) {
            wt[i] = rng(1, w_limit);
        }
    }
} New;

int Par[MAXN], dep[MAXN], wt[MAXN], color[MAXN];

void TreeandEdges(int n, int m, int Subtask) {
    vector<int> Red, Blue;
    Red.push_back(1);
    for (int i = 2; i < n; i++) {
        int par = rng(max(1, i-10), i-1);
        color[i] = !color[par];
        if (color[i]) {
            Blue.push_back(i);
        } else {
            Red.push_back(i);
        }
        New.add_edge(i, par, rng(wL, wR));
    }
    int npar = Blue[rng(0, Blue.size() - 1)];
    Red.push_back(n);
    New.add_edge(n, npar, rng(wL, wR));

    for (int i=1; i<=m-n+1; i++) {
        int r = Red[rng(0, Red.size()-1)], b = Blue[rng(0, Blue.size()-1)], w =rng(wL, wR);
        New.add_edge(r, b, w);
    }
}

void TwoTrees(int n, int m, int Subtask) {
    //m gets overridden
    vector <int> C[2], C2[2];
   C[0].push_back(1);

    for (int i=2; i<n; i++) {
        int par = rng(max(1,i-100),i-1), wt = rng(wL, wR);
        color[i] = color[par]^1;
        dep[i] = dep[par] + wt;
        New.add_edge(par, i, wt);
        C[color[i]].push_back(i);
    }
    C[0].push_back(n);
    New.add_edge(C[1][rng(0,C[1].size()-1)], n, rng(wL, wR)); //gen n so its same parity as 1

    C2[0].push_back(1);
    for (int i=2; i<=n; i++) {
         int s1 = C2[0].size(), s2 =C2[1].size();
         int par = color[i] ? C2[0][rng(0,s1-1)] : C2[1][rng(0,s2-1)];
         New.add_edge(par, i, rng(wL, wR));
         C2[color[i]].push_back(i);
    }
}

void MegaDag(int n, int m, int Subtask) {
    assert(n <= 10000);
    vector <int> C[2];
    C[0].push_back(1);

    for (int i=2; i<n; i++) {
        int par = rng(max(1,i-10),i-1), wt = 1;
        color[i] = color[par]^1;
        dep[i] = dep[par] + wt;
        New.add_edge(par, i, wt);
        C[color[i]].push_back(i);
    }
    int npar = C[1][rng(0,C[1].size()-1)];
    dep[n] = dep[npar] + 1;
    C[0].push_back(n);
    New.add_edge(npar, n, 1);

    for (int i=n; i<=m; i++) {
        int a = C[0][rng(0,C[0].size()-1)];
        int b = C[1][rng(0,C[1].size()-1)];
        New.add_edge(a,b,abs(dep[b]-dep[a]));
    }
}

void LongDag(int n, int m, int subtask) {
    //lol m gets overrided here
    vector <int> L, mid, R;
    int len = n/5;
    for (int i=1; i<=len; i++) {
        mid.push_back(i);
    }
    for (int i=len+1; i <= 3*len; i++) {
        L.push_back(i);
    }
    for (int i=3*len+1; i <= 5*len; i++) {
        R.push_back(i);
    }
    for (int i=0; i<2*len-1;i++) {
        New.add_edge(L[i], L[i+1], 1);
        New.add_edge(R[i], R[i+1],1);
    }
    for (int i=0; i<len; i++) {
        New.add_edge(mid[i], L[2*i], 1);
        New.add_edge(mid[i], R[2*i],1);
        New.add_edge(mid[i], L[2*i-2], 1);
        New.add_edge(mid[i], R[2*i-2],1);
    }
    for (int i=5*len+1; i<=n; i++) {
        New.add_edge(R.back(), i, 1);
    }
}
/*Input Format: 1 line from stdin
n subtask gentype seed
n=Size of graph
subtask = corresponding subtask number
gentype = type of generation algorithm
Seed = random seed
*/
int main() {
    int n, m, s, type, Seed;
    scanf("%d %d %d %d %d", &n, &m, &s, &type, &Seed);
    srand(Seed);
    if (s == 4) {assert(n<=200);}
    if (s == 2) {assert(m == n-1);}
    if (type == 2) n = min(n, 10000);
    New.setV(n);
    wL=1;
    wR=(s == 4 ? 1: 10000);
    if (type == 1) {
        TwoTrees(n,m,s);
    } else if (type == 2) {
        // I don't know what this code is and I'm tired
        // I'm just gonna upper bound N to 10000 here
        MegaDag(n,m,s);
    } else if (type == 3) {
        LongDag(n,m,s);
    } else if (type == 4) {
        TreeandEdges(n,m,s);
    }
    New.generate_weights(s);
    New.output();
}

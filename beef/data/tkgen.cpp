#include<iostream>
#include<vector>
#include<map>
#include<cassert>
#include<utility>
#define MAXN 100005
using namespace std;
class Graph {
    int N,M;
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
        adj[u][v]=w;
        M++;
    }
    void output() {
        assert(M <= (int) 3e5);
        printf("%d %d\n", N, M);
        for (int i=1; i<=N; i++) {
            for (auto e: adj[i]) {
               printf("%d %d %d\n", i, e.first, e.second);
            }
        }
    }
} New;
int wL, wR;
int rng(int l, int r) {
    int res=rand()%(r-l+1);
    return(res + l);
}

void clique(int n, int Subtask) {
    int Csize=min(n, 548);
    for (int i=1; i<=Csize; i++) {
        for (int j=i+1; j<=Csize; j++) {
            if (i != j) {
                int w=rng(wL, wR);
                New.add_edge(i,j, w);
                if (Subtask == 2) {
                    New.add_edge(j,i,w);
                } else {
                    New.add_edge(j,i,rng(wL, wR));
                }
            }
        }
    }
    if (n > Csize) {
        for (int v=n; v>Csize; v--) {
            for (int rep=0; rep<4; rep++) {
                int j=rng(1, n);
                int w=rng(wL, wR);
                New.add_edge(v,j, w);
                if (Subtask == 2) {
                    New.add_edge(j, v,w);
                } else {
                    New.add_edge(j,v,rng(wL, wR));
                }
            }
        }
    }
}

void twoTrees(int n, int Subtask) {
    int Par[n + 5], Par2[n + 5], wt[n + 5], wt2[n + 5];
    for (int i=2; i<=n; i++) {
        Par[i] = rng(1, i-1);
        wt[i] = rng(wL, wR);
        if (Subtask == 2) {
            Par2[i]=Par[i];
            wt2[i]=wt[i];
        } else {
            Par2[i] = rng(1, i-1);
            wt2[i] = rng(wL, wR);
        }
    }
    for (int i=2; i<=n; i++) {
        New.add_edge(Par[i], i, wt[i]);
        New.add_edge(i, Par2[i], wt2[i]);
    }
    int other_edge=rng(0, 2*n);
    for (int e=0; e<other_edge; e++) {
        int u=rng(1,n), v=rng(1,n), w=rng(wL, wR);
        New.add_edge(u,v,w);
        if (Subtask == 2) {New.add_edge(v,u,w);}
    }
}

void randclosejoin(int n, int Subtask) {
    int D=rng(5,10);
    for (int i=1; i<=n; i++) {
        for (int rep=0; rep<min(3, 1000-i*i); rep++) {
            int v=rng(i-D, i+D), w=rng(wL, wR);
            New.add_edge(i, v, w);
            if (Subtask == 2) {
                New.add_edge(v, i, w);
            }
        }
    }
}
/*Input Format: 1 line from stdin
n subtask gentype seed
n=Size of graph
subtask = corresponding subtask number
gentype = type of generation algorithm
1 means bidirectional clique with some random edges
2 means two spanning trees with random edges
3 means random close connections with near nodes
Seed = random seed
*/
int main() {
    int n, s, type, Seed;
    scanf("%d %d %d %d", &n, &s, &type, &Seed);
    srand(Seed);
    if (s == 1) {assert(n<=200);}
    New.setV(n);
    wL=1;
    wR=(s == 3 ? 1: 10000);
    if (type == 1) {
        clique(n, s);
    } else if (type == 2) {
        twoTrees(n, s);
    } else {
        randclosejoin(n, s);
    }
    New.output();
}

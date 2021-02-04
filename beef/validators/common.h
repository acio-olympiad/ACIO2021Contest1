#ifndef H_COMMON
#define H_COMMON
#include "testlib.h"
#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

const static int MAXN = 100000, MAXE = 200000, MAXA = 1000000000, MAXV=10000;

    int A[100005];
    vector <int> adj[100005];
    map <pair<int,int> ,int> Eset;

class Checker {
public:
    Checker() {};
    //bipartite checker
    bool vis[100005], color[100005];
     bool SB1=1, SB2=1, SB3=1, SB4=1, SB5=1;
    void dfs(int u, bool b) {
        vis[u] = true, color[u] = b;
        for (int v: adj[u]) {
            if (!vis[v]) {
                dfs(v, b^1);
            } else {
                ensuref(b^color[v], "graph not bipartite");
            }
        }
    }
    void validate() {
        registerValidation();
        int N = inf.readInt(3, MAXN, "N");
        inf.readSpace();
        int M = inf.readInt(2, MAXE, "M");
        inf.readEoln();

        for (int i=1; i<=N; i++) {
            A[i] = inf.readInt(1, MAXA, "ai");
            if (i != N) {inf.readSpace();}
            else {inf.readEoln();}
        }
        for (int i=1; i<=M; i++) {
            int u = inf.readInt(1, N, "u");
            inf.readSpace();
            int v = inf.readInt(1,N, "v");
            inf.readSpace();
            int t = inf.readInt(1, MAXV, "t");
            inf.readEoln();
            ensuref(Eset.find({u,v}) == Eset.end(), "edges not unique");
            ensuref(Eset.find({v,u}) == Eset.end(), "edges not unique");
            ensuref(u != v, "found self loop");
            Eset[{u,v}] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);

            SB4 &= t == 1;
        }
        inf.readEof();
        dfs(1,0);
        for (int i=1; i<=N; i++) {
            ensuref(vis[i], "graph not connected");
        }

        ensuref(color[1] == color[N], "1 and N of different color");
        //check subtasks
        SB2 &= N == M+1;
        SB4 &= N <= 200;

        for (int i=1; i<=N; i++) {
            SB1 &= A[i] == 1;
            SB3 &= A[i] <= 5;
        }
    }
};

#endif // COMMON_H


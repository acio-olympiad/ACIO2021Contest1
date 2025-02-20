#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAXN 100005
using namespace std;

int N, M, A[MAXN];
vector <pair<int,int> > adj[MAXN];

int dist[MAXN], dp[MAXN];
vector <int> ExploreOrder;
void dijkstra() {
    for (int i=2; i<=N; i++) {
        dist[i] = 1<<30; //source = 1
    }
    priority_queue<pair<int,int> > PQ;
    PQ.push({0,1});
    while (PQ.size()) {
        int cur = PQ.top().second, d = -PQ.top().first;
        PQ.pop();
        if (d > dist[cur]) {continue;}
        ExploreOrder.push_back(cur);
        for (auto e: adj[cur]) {
            if (dist[e.first] > dist[cur] + e.second) {
                dist[e.first] = dist[cur] + e.second;
                PQ.push({-dist[e.first], e.first});
            }
        }
    }
}

bool can(int tval) {
    for (int i=2; i<=N; i++) {
        dp[i] = -(1<<30);
    }
    dp[1] = (A[1] >= tval ? 1 : -1);
    for (int i=0; i<N; i++) {
        int cur = ExploreOrder[i];
        for (auto e: adj[cur]) {
            if (dist[e.first] == dist[cur] + e.second) {
                dp[e.first] = max(dp[e.first], dp[cur] + (A[e.first] >= tval ? 1 : -1));
            }
        }
    }

    return(dp[N] >= 1);
}

int main() {
    scanf("%d %d",&N,&M);
    for (int i=1; i<=N; i++) {
        scanf("%d",&A[i]);
    }
    for (int i=0; i<M; i++) {
        int u,v,t;
        scanf("%d %d %d",&u,&v,&t);
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }

    dijkstra();
    if (ExploreOrder.size() != N) printf("FUCK\n");
    /*for (int i: ExploreOrder) {
        printf("%d\n",i);
    }
    printf("here\n"); */
    int lo = 0, hi = 1e9 + 1;
    while (lo+1 != hi) {
        int mid = (lo + hi) >> 1;
        if (can(mid)) {lo = mid;}
        else {hi = mid;}
    }

    printf("%d %d",dist[N], lo);
}

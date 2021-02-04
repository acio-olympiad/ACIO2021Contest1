#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n, m;
struct edge{
    int tgt;
    int w;
};

vector<edge> g[100005];
int val[100005];

int dist[100005];
bool explored[100005];

typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;

vector<int> children[100005];

bool seen[100005];
int ans[100005];

int dfs(int x, int tgtval){
    if (x == n){
        return val[x] >= tgtval ? 1 : -1;
    }
    if (seen[x]) return ans[x];
    seen[x] = true;

    int ret = -1e9;
    for (int tgt : children[x]){
        ret = max(ret,dfs(tgt,tgtval));
    }
    if (val[x] >= tgtval){
        ret++;
    }
    else{
        ret--;
    }
    ans[x] = ret;
    return ret;
}  

// are at least half the things on a path to node n weight x or greater?
bool decision(int x){
    for (int i = 1; i <= n; i++){
        seen[i] = false;
    }
    return dfs(1,x) >= 0;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &val[i]);
        dist[i] = 1e9+7;
    }
    for (int i = 1; i <= m; i++){
        int a,b,w;
        scanf("%d %d %d", &a, &b, &w);
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }

    dist[1] = 0;
    q.push({0,1});
    while (!q.empty()){
        pii cur = q.top();
        q.pop();
        int x = cur.second;
        int d = cur.first;
        if (explored[x]){
            continue;
        }
        explored[x] = true;
        for (edge e : g[x]){
            int tdist = d + e.w;
            if (tdist < dist[e.tgt]){
                dist[e.tgt] = tdist;
                q.push({tdist,e.tgt});
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (edge e : g[i]){
            if (dist[i] + e.w == dist[e.tgt]){
                children[i].push_back(e.tgt);
            }
        }
    }

    int best = 0;
    int hi = 1e9 + 7;
    int lo = 0;

    while (lo <= hi){
        int mid = (lo + hi)/2;
        if (decision(mid)){
            lo = mid+1;
            best = mid;
        }
        else{
            hi = mid-1;
        }
    }
    printf("%d %d\n", dist[n], best);
}
#include <iostream>
#include <map>
#include <algorithm>
#define MAXN 100005
#define LL long long
using namespace std;
int N;
struct block {int l,w,h;} B[MAXN];

class segtree {
    LL ST[MAXN * 4];
public:
    void upd(int ind, LL val, int l, int r, int cur) {
        if (ind < l || ind > r) {return;}
        if (l == r) {
            ST[cur] = max(ST[cur], val);
        } else {
            int mid = (l + r) >> 1;
            upd(ind, val, l, mid, 2*cur);
            upd(ind, val, mid+1, r, 2*cur+1);
            ST[cur] = max(ST[2*cur], ST[2*cur+1]);
        }
    }

    LL ask(int lo, int hi, int l, int r, int cur) {
        if (lo > r || hi < l) {return(0);}
        if (lo <= l && hi >= r) {
            return(ST[cur]);
        } else {
            int mid = (l + r) >> 1;
            return(max(ask(lo, hi, l, mid, 2*cur),
                       ask(lo, hi, mid+1, r, 2*cur+1)));
        }
    }
} ST;
LL dp[MAXN], res;

//coord compress
map <int,int> Lookup;
int Compress[MAXN], ptr=1;

int main() {
    freopen("sample.txt","r",stdin);
    scanf("%d",&N);
    for (int i=1; i<=N; i++) {
        scanf("%d %d %d",&B[i].l, &B[i].w, &B[i].h);
        Compress[i] = B[i].w;
    }
    sort(B+1, B+N+1, [](block a, block b) {return(a.l < b.l);});
    //coord compress
    sort(Compress+1, Compress+N+1);
    for (int i=1; i<=N; i++) {
        if (Compress[i] != Compress[i-1]) {
            Lookup[Compress[i]] = ptr++;
        }
    }
    for (int i=1; i<=N; i++) {
        B[i].w = Lookup[B[i].w];
    }

    //dp
    for (int i=1; i<=N; i++) {
        dp[i] = ST.ask(0, B[i].w, 0, MAXN, 1) + B[i].h;
        ST.upd(B[i].w, dp[i], 0, MAXN, 1);
        res = max(res, dp[i]);
    }

    printf("%lld\n",res);
}



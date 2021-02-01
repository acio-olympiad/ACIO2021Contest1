#include <iostream>
#include <utility>
#define MAXD 1000000005
#define LL long long
#define MAXN 100005
using namespace std;
LL N, K , Q, P[MAXN];

class LazyCreate {
    LL ST[MAXN * 35][2]; //sum of subtree, number in subtree
    int L[MAXN * 35], R[MAXN * 35], ptr = 2; //l r
public:
    void pushup(int cur) {
        ST[cur][0] = ST[L[cur]][0] + ST[R[cur]][0];
        ST[cur][1] = ST[L[cur]][1] + ST[R[cur]][1];
    }

    void addnode(int cur) {
        L[cur] = ptr++;
        R[cur] = ptr++;
    }

    void upd(LL val, bool b, int l, int r, int cur) { //b = 1 is add, -1 minus
        if (l > val || r < val) {return;}
        if (l == r) {
            ST[cur][0] += (b ? 1 : -1) * val;
            ST[cur][1] += (b ? 1 : -1);
            return;
        }
        if (!L[cur]) {addnode(cur);}
        int mid = (l + r) >> 1;
        upd(val, b, l, mid, L[cur]);
        upd(val, b, mid+1, r, R[cur]);
        pushup(cur);
    }

    pair<LL,LL> ask(int lo, int hi, int l, int r, int cur) {
        if (!cur || lo > r || hi < l) {
            return(pair<LL,LL> {0,0});
        } else if (lo <= l && hi >= r) {
            return(pair<LL,LL> {ST[cur][0], ST[cur][1]});
        } else {
            int mid = (l + r) >> 1;
            pair<LL,LL> r1 = ask(lo, hi, l, mid, L[cur]),
            r2 = ask(lo, hi, mid+1, r, R[cur]);
            return(pair<LL,LL> {r1.first + r2.first, r1.second + r2.second});
        }
    }

    bool can(LL t) { //can we take t times?
        auto res = ask(0, t, 0, MAXD, 1);
        return(res.first + (N-res.second)*t >= t*K);
    }
} ST;

void slv() {
    int lo = -1, hi = MAXD;
    while (lo + 1 != hi) {
        int mid = (lo + hi) >> 1;
        if (ST.can(mid)) {lo = mid;}
        else {hi = mid;}
    }
    printf("%lld\n", K * ((LL) lo));
}

int main() {
    freopen("sample.txt","r",stdin);
    scanf("%lld %lld %lld",&N,&K,&Q);
    for (int i=1; i<=N; i++) {
        scanf("%lld",&P[i]);
        ST.upd(P[i], 1, 0, MAXD, 1);
    }
    slv();
    for (int i=0; i<Q; i++) {
        LL a,b;
        scanf("%lld %lld",&a,&b); //num pancakes, position
        ST.upd(P[b], 0, 0, MAXD, 1);
        ST.upd(a, 1, 0, MAXD, 1);
        P[b] = a;
        slv();
    }
}

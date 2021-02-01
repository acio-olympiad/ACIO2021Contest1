#include <iostream>
#include <utility>
#define MAXD 1000000005
#define LL long long
#define MAXN 100005
using namespace std;
int N, K , Q, P[MAXN];

bool can(int t) {
    LL sum = 0;
    for (int i=1; i<=N; i++) {
        sum += min(P[i], t);
    }
    return(sum >= ((LL) K)*((LL) t));
}

void slv() {
    int lo = -1, hi = MAXD;
    while (lo + 1 != hi) {
        int mid = (lo + hi) >> 1;
        if (can(mid)) {lo = mid;}
        else {hi = mid;}
    }
    printf("%lld\n", ((LL) K) * lo);
}

int main() {
    freopen("sample.txt","r",stdin);
    scanf("%d %d %d",&N,&K,&Q);
    for (int i=1; i<=N; i++) {
        scanf("%d",&P[i]);
    }
    slv();
    for (int i=0; i<Q; i++) {
        int a,b;
        scanf("%d %d",&a,&b); //num pancakes, position
        P[b] = a;
        slv();
    }
}


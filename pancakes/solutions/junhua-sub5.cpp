#include <iostream>
#include <utility>
#define MAXD 50000000000005
#define LL long long
#define MAXN 100005
using namespace std;
int N, K , Q, P[MAXN];

bool can(LL t) {
    LL sum = 0;
    for (int i=1; i<=N; i++) {
        sum += min((LL)P[i], t);
    }
    return(sum >= ((LL) K)*((LL) t));
}

void slv() {
    long long lo = -1, hi = MAXD;
    while (lo + 1 != hi) {
        long long mid = (lo + hi) >> 1;
        if (can(mid)) {lo = mid;}
        else {hi = mid;}
    }
    printf("%lld\n", ((LL) K) * lo);
}

int main() {
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


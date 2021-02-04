#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

int n;

long long dp[2005][2005];

struct box{
    long long x,y,h;
};
vector<long long> ccv;
vector<box> bv;
map<long long, int> ccm;

long long st[400005];

void update(int si, int sl, int sr, int x, long long v){
    if (sl == sr){
        st[si] = v;
        return;
    }
    int mid = (sl + sr)/2;
    if (x <= mid){
        update(si*2+1,sl,mid,x,v);
    }
    else{
        update(si*2+2,mid+1,sr,x,v);
    }
    st[si] = max(st[si*2+1],st[si*2+2]);
}


long long query(int si, int sl, int sr, int ql, int qr){
    if (ql > qr) return 0;
    if (sl > qr || sr < ql){
        return 0;
    }
    if (sl >= ql && sr <= qr){
        return st[si];
    }
    int mid = (sl + sr)/2;
    return max(query(si*2+1,sl,mid,ql,qr),query(si*2+2,mid+1,sr,ql,qr));
}

int main(){
    scanf("%d", &n);
    int ncnt = 1;
    for (int i = 1; i <= n; i++){
        box b;
        long long x,y,h;
        scanf("%lld %lld %lld", &x, &y, &h);
        b.x = x;
        b.y = y;
        b.h = h;
        bv.push_back(b);
        ccv.push_back(y);
    }

    sort(ccv.begin(),ccv.end());
    ccv.erase(unique(ccv.begin(),ccv.end()),ccv.end());
    for (int i = 0; i < ccv.size(); i++){
        ccm[ccv[i]] = i+1;
    }
    
    for (int i = 0; i < n; i++){
        bv[i].y = ccm[bv[i].y];
    }
    
    sort(bv.begin(),bv.end(),[](box l, box r){
        if (l.x == r.x){
            return l.y > r.y;
        }
        return l.x > r.x;
    });
    
    for (box cur : bv){
        long long ans = query(0,0,n,cur.y,n);
        update(0,0,n,cur.y,ans + cur.h);
    }

    printf("%lld\n", query(0,0,n,0,n));
}
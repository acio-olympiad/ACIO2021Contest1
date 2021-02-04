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
int main(){
    assert(n <= 2000);

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
    
    // dp[cn][cy] = max tower height with current base width cy out of first cn blocks.
    // 
    for (int cn = 1; cn <= n; cn++){
        // printf("%lld %lld %lld\n", bv[cn-1].x,bv[cn-1].y,bv[cn-1].h);
        long long cm = 0;
        for (int cy = n; cy >= 1; cy--){
            dp[cn][cy] = dp[cn-1][cy];
            cm = max(cm,dp[cn][cy]);
            if (cy == bv[cn-1].y){   
                dp[cn][cy] = cm + bv[cn-1].h;
            }
        }
    }
    long long cm = 0;
    for (int i = 1; i <= n; i++){
        cm = max(dp[n][i],cm);
    }
    printf("%lld\n", cm);

}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N, l[100005], w[100005], h[100005], ls[100005], ws[100005];
vector<int, pair<int, int>> bruh;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", l+i, w+i, h+i);
        ls[i] = l[i];
        ws[i] = w[i];
    }
    sort(ls, ls+N);
    sort(ws, ws+N);
}

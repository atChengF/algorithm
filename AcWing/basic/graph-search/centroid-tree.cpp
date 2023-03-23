#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;

struct Edge{
    int ne, to;
}e[N * 2];

int h[N], idx;
int n, ans = N;

void add(int a, int b){
    e[idx] = {h[a], b};
    h[a] = idx ++;
}

int dfs(int u, int father){
    int sum = 1, sz = 0;
    for (int i = h[u]; ~i; i = e[i].ne) {
        int j = e[i].to;
        if (j == father) continue;
        int t = dfs(j, u);
        sz = max(sz, t);
        sum += t;
    }
    sz = max(sz, n - sum);
    ans = min(ans, sz);
    return sum;
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 0; i < n - 1; i ++ ) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}

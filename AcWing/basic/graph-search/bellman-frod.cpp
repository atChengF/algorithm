#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010;

struct Edge{
    int from, to, val;
} e[N];

int n, m, k, idx;

void add(int a, int b, int c){
    e[idx ++ ] = {a, b, c};
}

int dst_pre[N], dst_cur[N];

void bellman_ford(){
    //松弛k次
    
    memset(dst_cur, 0x3f, sizeof dst_cur);
    dst_cur[1] = 0;
    for(int i = 0; i < k; i ++ ) {
        memcpy(dst_pre, dst_cur, sizeof dst_cur);
        for(int j = 0; j < m; j ++ ){
            dst_cur[e[j].to] = min(dst_cur[e[j].to], dst_pre[e[j].from] + e[j].val);
        }
    }
    if (dst_cur[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
    else  cout << dst_cur[n] << endl;
    return;
}

int main(){
    cin >> n >> m >> k;
    int a, b, c;
    for(int i = 0; i < m; i ++ ){
        cin >> a >> b >> c;
        add(a, b, c);
    }
    bellman_ford();
    
    return 0;
}


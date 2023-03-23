#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010, MAX = 0x3f3f3f3f;

struct Edge{
    int to, ne, val;
} e[N];

int h[N], idx;

int n, m;
int dst[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = {b, h[a], c};
    h[a] = idx ++ ;
}

int dijkstra(int i, int j){
    dst[1] = 0;
    // n - 1 次
    for(int i = 1; i < n; i ++ ){
        int t = -1;
        for(int j = 1; j <= n; j ++ ){
            if(!st[j] && (t == -1 || dst[j] < dst[t])) t = j;
        }
        // t 是距离最近点
        for(int j = h[t]; j != -1; j = e[j].ne){
            int k = e[j].to;
            dst[k] = min(dst[k], dst[t] + e[j].val);
        }
        //t 是已经求出的最小值点
        st[t] = true;
    }
    if(dst[j] == MAX) return -1;
    return dst[j];
}


int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(dst, 0x3f, sizeof dst);
    int a, b, c;
    for(int i = 0; i < m; i ++ ){
        cin >> a >> b >> c;
        add(a, b, c);
    } 
    cout << dijkstra(1, n) << endl;
}
#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;

const int N = 510, M = 200010;

struct Edge{
    int to, ne, val;
} e[M];

int h[N], idx;

void add(int a, int b, int c){
    e[idx] = {b, h[a], c};
    h[a] = idx ++ ;
}

int n, m;

int dst[N];
bool inset[N];
const int INF = 0x3f3f3f3f;

int prime(){
    int res = 0;
    memset(dst, 0x3f, sizeof dst);
    dst[1] = 0;
    
    for(int i = 1; i <=n; i ++ ){
        int sel = -1;
        for(int j = 1; j <= n; j ++ ){
            if(!inset[j] && (sel == -1 || dst[j] < dst[sel])) sel = j;
        }
        
        //判断是否存在孤立点
        if(sel == -1 || dst[sel] == INF) return INF;
        
        inset[sel] = true;
        res += dst[sel];
        
        for(int j = h[sel]; j != -1; j = e[j].ne){
            int to = e[j].to;
            if(dst[to] > e[j].val) dst[to] = e[j].val;
        }
        
    }
    return res;
    
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b, c;
    while(m -- ){
        cin >> a >> b >> c;
        add(a ,b, c);
        add(b ,a, c);
    }
    int t = prime();

    if(t == INF) cout << "impossible" << endl;
    else cout << t << endl;
}

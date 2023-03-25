#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int N = 100010;

struct Edge{
    int to, ne, val;
} e[N];

int h[N], n, m, idx;

void add(int a, int b, int c){
    e[idx] = {b, h[a], c};
    h[a] = idx ++ ;
}

//距离 1 号点的距离
int dst[N];
bool st[N];
queue<int> q;
int spfa(){
    memset(dst, 0x3f, sizeof dst);
    dst[1] = 0;
    q.push(1);
    st[1] = true;
    
    while(q.size()){
        int t = q.front();
        q.pop();
        
        st[t] = false;
        for(int i = h[t]; i != -1; i = e[i].ne){
            int j = e[i].to;

            if(e[i].val + dst[t] < dst[j]){
                //更新路径
                dst[j] = e[i].val + dst[t];
                
                if(!st[t]){
                    q.push(j);
                    st[j] = true;
                }
                
            } 
        }
    }

    return dst[n];
    
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i ++ ){
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int t =  spfa();
    if(spfa() > 0x3f3f3f3f / 2) cout << "impossible" << endl;
    else cout << t << endl;

}
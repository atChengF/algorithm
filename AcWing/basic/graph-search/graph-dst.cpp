#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;

struct Edge{
    int to, ne;
} e[N];

int h[N], idx, n, m; 

int dst[N];

void add(int a, int b){
    e[idx] = {b, h[a]};
    h[a] = idx ++ ;
}

// 求 1 - n 的距离
int bfs(){
    queue<int> q;
    q.push(1);
    dst[1] = 0;
    while(q.size()){
        int p = q.front();
        q.pop();
        for(int i = h[p]; i != -1; i = e[i].ne){
            int j = e[i].to;
            if(dst[j] != -1) continue;
            dst[j] = dst[p] + 1;
            q.push(j);
        }
    }
    
    return dst[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(dst, -1, sizeof dst);
    int a, b;
    for(int i = 0; i < m; i ++ ){
        cin >> a >> b;
        add(a, b);
    } 
    cout << bfs() << endl;
}
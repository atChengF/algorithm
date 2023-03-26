#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 2 * N;

typedef struct Edge{
    int from, to, val;
} Edge;

Edge e[M];

int idx;


void add(int a, int b, int c){
    e[idx ++ ] = {a, b, c};
}

int parent[N];

int find(int x){
    if(x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

bool cmp(Edge A, Edge B)
{
    return A.val < B.val;
}


int n, m;
void kruskal(){

    int cnt = 0, res = 0;
    for(int i = 1; i < N; i ++ ) parent[i] = i;

    sort(e, e + m, cmp);

    
    for(int i = 0; i < m; i ++ ){  //循环范围为0到m-1
        int x = e[i].from, y = e[i].to;
        int xp = find(x), yp = find(y);
        if(xp != yp){
            parent[xp] = yp;
            res += e[i].val;
            cnt ++ ;
        }
    }
    
    cout << res << " " << cnt << " " << n <<  endl;
    if(cnt != n - 1) cout << "impossible" << endl;
    else  cout << res << endl;
}

int main(){
   
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i ++ ){
        cin >> a >> b >> c;
        add(a, b, c);
    }
    kruskal();
}






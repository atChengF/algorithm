#include <iostream>
#include <queue>
#include <cstring>


using namespace std;

const int N = 100010;

struct Edge{
    int to,ne;
} e[N];

int h[N], idx, in[N];

int n, m;

void add(int a, int b){
    e[idx] = {b, h[a]};
    h[a] = idx ++ ;

    in[b] ++ ;
}

//topsort 利用队列使得 入度为0的点入队，

int q[N];
int tail = -1, head = 0;

bool topsort(){
    for(int i = 1; i <= n; i ++ ) if(in[i] == 0) q[++ tail] = i;
    while(head <= tail){
        int p = q[head ++ ];
        for(int i = h[p]; i != -1; i = e[i].ne){
            int j = e[i].to;
            in[j] -- ;
            if(in[j] == 0) q[++ tail] = j;
        }
    }
    return tail == n - 1;
}


int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i ++ ) {
        cin >> a >> b;
        add(a, b);
    }
    
    if(topsort()){
        for(int i = 0; i < n; i ++ ) cout << q[i] << " ";
        cout << endl;
    } else cout << -1 << endl;
    return 0;
}

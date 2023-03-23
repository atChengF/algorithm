#include <iostream>
#include <cstring>


using namespace std;

const int N = 110;

typedef pair<int, int> PII;
int a[N][N];
int d[N][N];
PII q[N * N];
int tail = -1, head = 0;
int n, m;

int bfs(){
    q[++ tail] = {0, 0};
    memset(d, -1, sizeof d);
    
    d[0][0] = 0;
    
    int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
    
    //队列不空
    while(head <= tail){
        PII c = q[head ++ ];
        
        for(int i = 0; i < 4; i ++ ){
            int x =  c.first + dx[i], y = c.second + dy[i];
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            //距离没有更新的点 才进行扩展 ，因为 bfs 先扩展的节点一定是最先接近的点， 所以通过 bfs可以进行扩展
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[c.first][c.second] + 1;
                q[++ tail] = {x, y};
            }
        }
    }
    
    return  d[n - 1][m - 1];
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ) cin >> a[i][j];
    }
    cout << bfs() << endl;
}

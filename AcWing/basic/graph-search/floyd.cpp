#include <iostream>
#include <cstring>

using namespace std;

const int N = 210;
int n, m, k;
int dst[N][N];


int main(){
    cin >> n >> m >> k;
    memset(dst, 0x3f, sizeof dst);
    int a, b, c;
    for(int i = 1; i <= m; i ++ ){
        cin >> a >> b >> c;
        dst[a][b] = min(c, dst[a][b]);
    }
    for(int i = 1; i <= n; i ++ ) dst[i][i] = 0;
    
    for(int t = 1; t <= n; t ++ ){
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                dst[i][j] = min(dst[i][t] + dst[t][j], dst[i][j]);
            }
        }
    }
    int x, y;
    while(k -- ){
        cin >> x >> y;
        if(dst[x][y] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
        else cout << dst[x][y] << endl;
    }
}
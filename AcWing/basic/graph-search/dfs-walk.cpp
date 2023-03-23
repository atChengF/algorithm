#include <iostream>

using namespace std;

const int N = 110;

int a[N][N];
int d[N][N]; // 可以剪枝，不过就不能使用这个方法了
bool vi[N][N];

int n,m;
int res = N * N;

void dfs(int i, int j, int steps){
    if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] || vi[i][j] || steps >= res) return;
    if(i == n - 1 && j == m - 1) {
     res = min(res, steps);
     return;
    }
    vi[i][j] = true;
    dfs(i - 1, j, steps + 1);
    dfs(i + 1, j, steps + 1);
    dfs(i, j - 1, steps + 1);
    dfs(i, j + 1, steps + 1);
    vi[i][j] = false;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ) cin >> a[i][j];
    }
    dfs(0, 0, 0);
    
    cout << res << endl;
}
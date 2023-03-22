#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

bool used[8];
vector<int> path;
// 全排序
void dfs(int n, int depth){
    if(depth == n){
        for(int i = 0; i < n; i ++ ) cout << path[i] << " ";
        cout << endl;
        return ;
    }
    for(int i = 1; i <= n ; i ++ ){
        if(used[i]) continue;
        path.push_back(i);
        used[i] = true;
        dfs(n, depth + 1);
        path.pop_back();
        used[i] = false;
    }
}
    

int main(){
    int n;
    cin >> n;
    dfs(n, 0);
}
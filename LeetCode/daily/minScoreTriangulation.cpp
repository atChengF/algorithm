#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
// LeetCode 1039 daily 2023/4/2
class Solution0 {
public:
    // 记忆化搜索加上剪枝，可以吗？
    // 动态规划？以加入的点的数量进行划分？
    
    int f[55][55];
    int minScoreTriangulation(vector<int>& values) {
        // 通过
        memset(f, 0x3f, sizeof f);
        int n = values.size();
        for(int i = 0; i < n - 1; i ++ ) f[i][i + 1] = 0; 
        
        //俩个点的距离
        for(int i = 2; i < n; i ++ ){
            for(int j = 0; j < n - i; j ++ ){
                int x = j, y = j + i;
                for(int k = x + 1; k < y; k ++ ){
                    f[x][y] = min(f[x][k] + f[k][y] + values[x] * values[k] * values[y], f[x][y]);
                }
            }
        }
        return f[0][n - 1];

    }
};
class Solution1 {
public:
    // 记忆化搜索加上剪枝，可以吗？
    // 动态规划？以加入的点的数量进行划分？

    int f[55][55];
    vector<int> v;
    int recur(int x, int y){
        if(f[x][y] != 0x3f3f3f3f) return f[x][y];
        for(int i = x + 1; i < y; i ++ ){
            f[x][y] = min(recur(x, i) + recur(i, y) + v[x] * v[i] * v[y], f[x][y]); 
        }
        return f[x][y];
       
    }
    int minScoreTriangulation(vector<int>& values) {
        v = values;
        int n = values.size();

        memset(f, 0x3f, sizeof f);
        for(int i = 0; i < n - 1; i ++ ) f[i][i + 1] = 0;

        
        return recur(0, n - 1);
    }
};
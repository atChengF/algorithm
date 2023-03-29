#include <iostream>
#include <cstring>


using namespace std;

//优化到一维空间
int knapsack01(int* v, int* w, int N, int V){
    int f[V + 1]; 
    memset(f, 0, sizeof f);
    for(int i = 1; i <= N; i ++ ){
        for(int j = V; j >= v[i]; j -- ){
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }
    return f[V];
}

//考虑 恰好等于 V 的情况
int knapsack01_01(int* v, int* w, int N, int V){
    int f[V + 1];
    for(int i = 1; i <= V; i ++ ) f[i] = -1e9;
    f[0] = 0;
    for(int i = 1; i <= N; i ++ ){
        for(int j = V; j >= v[i]; j -- ){
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }
    return f[V];

}

//方案数量问题 v[i]是占用体积， N是物品数量， V是总体积 ,求总体积不超过 V 的最大方案数量
int knapsack01_02(int* v, int N, int V){
    int f[V + 1]; //前 i 个物品，体积和 小于等于 j 的个数
    for(int i = 0; i <= V; i ++ ) f[i] = 1;
    for(int i = 1; i <= N; i ++ ){
        for(int j = V; j >= v[i]; j -- ){
            f[j] += f[j - v[i]];
        }
    }
    return f[V];
}

//方案数量问题 v[i]是占用体积， N是物品数量， V是总体积 ,求总体积恰好等于 V 的最大方案数量
int knapsack01_03(int* v, int N, int V){
    int f[V + 1]; //前 i 个物品，体积和 小于等于 j 的个数
    memset(f, 0, sizeof f);
    f[0] = 1;
    for(int i = 1; i <= N; i ++ ){
        for(int j = V; j >= v[i]; j -- ){
            f[j] += f[j - v[i]];
        }
    }
    return f[V];
}

// 空间二维
int main(){
    int N, V;
    cin >> N  >> V;
    int v[N + 1], w[N + 1];
    for(int i = 1; i <= N; i ++ ){
        cin >> v[i] >> w[i];
    }
    int f[N + 1][V + 1];
    memset(f, 0, sizeof f);
    
    for(int i = 1; i <= N ; i ++ ){
        for(int j = 1; j <= V; j ++ ){
            if(j < v[i]) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j]);
        }
    }
    
    cout << f[N][V] << endl;
}
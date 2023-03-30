// 考虑背包问题
// 多重背包问题
// 给定 v[N], w[N], c[N], 最大体积 V , N 个物品 , 求最大价值是多少？
// c[N] 是数量

// 朴素做法, 将物品 c[N] 个物品拆开看，变成了 01 背包问题 ,
// attention : 方案数量用这种写法
#include <iostream>
#include <cstring>
using namespace std;
int knapsack01(int * v, int * w, int * c, int N, int V){
    int f[V + 1];
    memset(f, 0, sizeof f);
    for(int i = 1; i < N ; i ++ ){
        for(int j = 1; j <= c[i]; j ++ ){
            for(int k = V; k >= v[i]; k -- ){
                f[k] = max(f[k], f[k - v[i]] + w[i]);
            }
        }
    }
    return f[V];
}


// 01背包
int knapsack02(int * v, int * w, int * c, int N, int V){
    int f[V + 1];
    memset(f, 0, sizeof f);
    for(int i = 1; i < N ; i ++ ){
        for(int j = V; j >= v[i]; j -- ){
            for (int k = 0; k <= c[i] && k * v[i] <= j; k ++ ){
                f[j] = max(f[j], f[j - v[i] * k] + w[i] * k);
            }
        }
    }
    return f[V];
}



// 二进制优化，
int knapsack03(int * v, int * w, int * c, int N, int V){
    int f[V + 1];
    memset(f, 0, sizeof f);

    for(int i = 1; i < N ; i ++ ){
        int val = c[i], level = 1;
        while(val > 0){
            level = min(level, val);
            val -= level;
            for(int j = V; j >= level * v[i]; j -- ){
                f[j] = max(f[j], f[j - level * v[i]] + level * w[i]);
            }
            level = level >> 1;
        }
    }
    return f[V];
}

//
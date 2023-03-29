//完全背包推导
// 考虑每一个物品可以选择多个
// f(i, j) = max{f(i - 1, j), f(i - 1, j - v[i]) + w[i], f(i - 1, j - 2 * v[i]) + 2 * w[i], ..., f(i - 1, j - k * v[i]) + k * w[i]}
//  j - k * v[i] >= 0;
// 考虑 f(i, j - v[i]) = max(f(i - 1, j - v[i]), f(i - 1, j - v[i]) + w[i], ..., f(i - 1, j - k * v[i]) + (k - 1) * w[i]});
// f(i, j) = max(f(i - 1, j), f(i, j - v[i]) + w[i])
// 直观上考虑和理解，其实是 f(i, j - v[i]) 已经考虑过了加上当前点，所以直接利用这个位置进行转移，实际上就已经考虑了多个物品添加的情况
#include <cstring>
#include <iostream>
using namespace std;
int knapsackProblemComplete(int *v, int *w, int N, int V){
    int f[V + 1];
    memset(f, 0, sizeof f);
    for(int i = 1; i <= N; i ++ ){
        for(int j = v[i]; j <= V; j ++ ){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
}
#include <iostream>
#include <cstring>
#include <vector>
#include <limits.h>
using namespace std;

// leetcode 377 排列问题  
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 完全背包 还是 分组背包？？
        int f[target + 1];
        memset(f, 0, sizeof f);
        // 初始化
        f[0] = 1;
        for(int i = 0; i <= target;i ++ ){
            for(int j = 0; j < nums.size(); j ++ ){
                if(i >= nums[j] && f[i - nums[j]] < INT_MAX - f[i]) f[i] += f[i - nums[j]];
            }
        }
        return (int)f[target];
    }
};
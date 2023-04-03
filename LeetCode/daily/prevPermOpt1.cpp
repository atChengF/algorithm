#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


//Leetcode 1092 daily 2023/4/3
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        // 从右往左寻找
        int idx = -1;
        for(int i = arr.size() - 1; i > 0; i -- ){
            if(arr[i - 1] > arr[i]) {
                idx = i - 1;
                break;
            }
        }
        if(idx == -1) return arr;
        int max = idx + 1;
        for(int i = arr.size() - 1; i > idx; i -- ) if(arr[i] >= arr[max] && arr[i] < arr[idx]) max = i;
        swap(arr[max], arr[idx]);
        return arr;
    }
};
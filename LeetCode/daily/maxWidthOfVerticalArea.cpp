#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// LeetCode 1637 daily 2023/3/30
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res = 0;
        for(int i = 1; i < points.size(); i ++ ){
            res = max(res, points[i][0] - points[i - 1][0]);
        }
        return res;

    }
};
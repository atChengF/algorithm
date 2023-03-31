#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//Leetcode 1641 daily 2023/3/31
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        // key value
        std::set<int> s;
        for(int i = 0; i < nums.size(); i ++ ) s.insert(nums[i]);
        int res = 0;
        for(int i = 0; i < nums.size(); i ++ ) if(s.find(nums[i] - diff) != s.end() 
        && s.find(nums[i] + diff) != s.end()) res ++;
        return res;
    }
};
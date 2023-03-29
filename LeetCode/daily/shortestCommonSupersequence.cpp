#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//Leetcode 1092 daily 2023/3/28
string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    int f[n + 1][m + 1];
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            if(str1[i - 1] == str2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    vector<int> p1, p2;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(str1[i - 1] == str2[j - 1]){
            p1.push_back(-- i);
            p2.push_back(-- j);
        } else if (f[i][j] == f[i - 1][j]) i -- ;
        else j -- ;
    }
    i = 0, j = 0;
    reverse(p1.begin(), p1.end());
    reverse(p2.begin(), p2.end());
    string res = "";
    i = 0, j = 0;
    for(int t = 0; t < p1.size(); t ++ ){
        while(i != p1[t]) res += str1[i ++ ];
        while(j != p2[t]) res += str2[j ++ ];
        res += str1[p1[t]];
        i ++ ;
        j ++ ;
    }
    while(i < n) res += str1[i ++ ];
    while(j < m) res += str2[j ++ ];
    return res;
}

int main(){
    string str1 = "abac", str2 = "cab";
    cout << shortestCommonSupersequence(str1, str2) << endl;

}
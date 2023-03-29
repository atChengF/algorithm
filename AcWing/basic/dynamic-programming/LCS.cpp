#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int longest_common_subsequence(int * a, int * b, int n1, int n2){
    int f[n1 + 1][n2 + 1];
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n1; i ++ ){
        for(int j = 1; j <= n2; j ++ ){
            if(a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    return f[n1][n2];
}

int main(){
    int n1 = 4, n2 = 5;
    int a[] = {1, 3, 2, 4}, b[] = {1, 2, 5, 4, 3};
    cout << longest_common_subsequence(a, b, n1, n2) << endl;
    return 0;
}
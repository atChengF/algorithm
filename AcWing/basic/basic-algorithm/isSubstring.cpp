#include<iostream>

using namespace std;

const int N = 100010;
int n, m, a[N], b[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < m; i ++ ) cin >> b[i];
    int i = 0, j = 0;
    for(; i < n && j < m ; j ++ ){
        if(a[i] == b[j]) i ++ ;
    }
    if(i == n) cout << "Yes" << endl;
    else  cout << "No" << endl;
    
}
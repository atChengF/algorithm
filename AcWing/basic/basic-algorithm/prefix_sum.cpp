//AcWing 795 

#include <iostream>

using namespace std;

const int N = 100010;
 
int prefixsum[N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) {
        cin >> prefixsum[i];
        prefixsum[i] += prefixsum[i - 1];
    } 
    for(int i = 0; i < m; i ++ ){
        int l, r;
        cin >> l >> r;
        cout << prefixsum[r] - prefixsum[l - 1] << endl;
    }
}
#include <iostream>


using namespace std;

const int N = 4 * 1000000, M = 100000;
struct Tire {
    int sons[2];
} tires[N];

int root = 0, idx = 0, A[100000];

void insert(int x){
    int p = root;
    for(int i = 31; i >= 0; i -- ){
        int u = x >> i & 1;
        if(tires[p].sons[u] == 0) tires[p].sons[u] = ++ idx;
        p = tires[p].sons[u];
    }
}

int query(int x){
    int p = root;
    int res = 0;
    for(int i = 31; i >= 0; i -- ){
        int u = x >> i & 1;
        if(tires[p].sons[1 - u] != 0) {
            p = tires[p].sons[1 - u];
            res += 1 << i;
        } else p = tires[p].sons[u];
    }
    return res;

}


int main(){
    int n; 
    cin >> n;
    for(int i = 0; i < n; i ++ ) {
        cin >> A[i];
        insert(A[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i ++ ) res = max(res, query(A[i]));
    cout << res << endl;
    
}
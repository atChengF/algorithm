#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

struct Edge{
    int to, ne;
} e[N];

int h[N],  idx;
void add(int a, int b){
    e[idx] = {b, h[a]};
    h[a] = idx ++ ;
}

int color[N];

bool coloring(int u, int c){

    color[u] = c;
    
    for(int i = h[u]; i != -1; i = e[i].ne){
        int j = e[i].to;
        if(color[j] == 0) {
            if(!coloring(j, -c)) return false;
        } else if(color[j] == c) return false;
    }
    return true;
}

int n, m;
int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    while(m -- ){
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bool is = true;
    for(int i = 1; i <= n; i ++ ){
        if(color[i] == 0) {
            if(!coloring(i, 1)) {
                is = false;
                break;
            }
        }
    }
    
    if(is) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
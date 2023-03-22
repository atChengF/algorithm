#include <iostream>

using namespace std;

const int N = 100010;
int sz;
// 小根堆
int h[N];

void up(int x){
    int u = x;
    while (u / 2 && h[u] < h[u / 2]){
        swap(h[u], h[u / 2]);
        u >>= 1;
    }
}

void down(int u)
{
    int t = u;
    if (u * 2 < sz && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 < sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}



int main(){
    int m;
    cin >> sz >> m;
    for(int i = 0; i < sz; i ++ ) cin >> h[i];
    
    for(int i = sz / 2; i >= 0; i -- ) down(i);
    for(int i = 0; i < m; i ++ ) {
        cout << h[0] << " ";
        swap(h[0], h[ -- sz]);
        down(0);
    }
    
}
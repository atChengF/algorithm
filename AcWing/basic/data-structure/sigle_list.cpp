#include <iostream>

using namespace std;

const int N = 100010;

int head, v[N], ne[N], idx;

void init(){
    head = -1;
    idx = 0;
}

void add_to_head(int val){
    v[idx] = val, ne[idx] = head, head = idx ++ ;
}

void add_after_x(int x, int val){
    v[idx] = val, ne[idx] = ne[x], ne[x] = idx ++ ;
}
//删除 x 后的一个点
void remove(int x){
    ne[x] = ne[ne[x]];
}

int main(){
    init();
    int n ;
    cin >> n;
    while(n -- ){
        char c;
        cin >> c;
        if(c == 'H'){
            int c;
            cin >> c;
            add_to_head(c);
        } else if(c == 'I') {
            int x, c;
            cin >> x >> c;
            add_after_x(x - 1, c);
        } else{
            int x;
            cin >> x;
            if(x == 0) head = ne[head];
            else remove(x - 1);
        }
    }
    
    for(int p = head; p != -1; p = ne[p]){
        cout << v[p] << " ";
    }
    cout << endl;
    
}
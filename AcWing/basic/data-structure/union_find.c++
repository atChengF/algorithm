#include <iostream>

using namespace std;

const int N = 100010;
struct Node{
    int parent;
} Node[N];

void init(int n){
    for(int i = 0; i < n; i ++ ) Node[i].parent = i;
}
//get the parent
int find(int x){
    if(Node[x].parent != x) Node[x].parent = find(Node[x].parent);
    return Node[x].parent;
}

int un(int x, int y){
    int xp = find(x), yp =find(y);
    if(xp != yp) Node[xp].parent = yp;

}

int query(int x, int y){
    int xp = find(x), yp =find(y);
    if(xp != yp) return 0;
    else return 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    init(n);
    char c;
    int x, y;
    
    while(m -- ){
        cin >> c >> x >> y;
        if(c == 'M'){
            un(x, y);
        } 
        else {
            if(query(x, y)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}



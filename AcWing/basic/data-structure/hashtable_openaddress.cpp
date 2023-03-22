#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

void init(){
    memset(h, 0x3f, sizeof h);
}

void insert(int x){
    int p = ((x % N) + N) % N;
    while(h[p] != null){
         p ++ ;
         if(p == N){ 
             printf("over array \n");
             return;
         }
    }
    h[p] = x;
}

bool find(int x){
    int p = ((x % N) + N) % N;
    while(h[p] != null && p < N){
        if(h[p] == x) return true;
        p ++; 
    }
    return false;
    
}

int main(){
    init();
    int n;
    cin >> n;
    char c;
    int x;
    while(n -- ){
        cin >> c >> x;
        if(c == 'I') insert(x);
        else {
            if(find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
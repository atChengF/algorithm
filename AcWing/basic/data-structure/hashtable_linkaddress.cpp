#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000003, null = 0x3f3f3f3f;



struct Node{
     int val;
     Node * ne;
};
Node head[N];

void insert(int x){
    int p = (x % N + N) % N;
    Node * node = &head[p];
    while(node->ne != NULL){
        //已经存在
        if(node->ne->val == x) return;
        node = node->ne;
    }
    node->ne = new Node;
    node->ne->val = x;
}

bool query(int x){
    int p = (x % N + N) % N;
    Node * node = &head[p];
    while(node->ne != NULL){
        if(node->ne->val == x) return true;  
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    char c;
    int x;
    while(n -- ){
        cin >> c >> x;
        if(c == 'I') insert(x);
        else {
            if(query(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
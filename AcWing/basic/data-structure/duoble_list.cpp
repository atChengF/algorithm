#include <iostream>

using namespace std;

const int N = 1000010;
// 0 作为头节点，不赋值
int l[N], r[N], v[N], idx;

void init(){
    idx = 1;
    l[0] = 0;
    r[0] = 0;
}

void add_to_left(int val){
    v[idx] = val, l[idx] = 0, r[idx] = r[0], r[0] = idx ++ ;
}

void add_to_right(int val){
    v[idx] = val, r[idx] = 0, l[idx] = l[0], l[0] = idx ++ ;
}



int main(){
    
}
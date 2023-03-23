#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 10010, M = 1000010;

struct Edge {  
    int to, wight;  // v 是 改边的终点，w 是边权
    int ne;    // ne 是当前节点的下一条边的 编号 -1代表没有下一条边存在
} e[M];

struct Head{
    int val;
    int edge; // 指向首条边
} h[N];

int idx;  // idx 表示边的可用序号

void init(){
    idx = 0;
    memset(h, -1, sizeof h);    
}

void add_edge(int a, int b, int c) {  // 添加一条边 a->b，权值为 c
    e[idx] = {b, c, h[a].edge}; 
    h[a].edge = idx ++ ;
}

void add_head_val(int a, int v){
    h[a].val = v;
}

int main(){


}
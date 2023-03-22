#include <iostream>

using namespace std;

const int N = 100010;
int stack[N], sp;

void init(){
    sp = 0;
}

void put(int val){
    stack[sp ++ ] = val;
}

int pop(){
    return stack[--sp]; 
}
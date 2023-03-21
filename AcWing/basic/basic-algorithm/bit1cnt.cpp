#include <iostream>

using namespace std;


int get1bitcnt(int n){
    int cnt = 0;
    int c = n;
    while(c != 0){
        cnt ++ ;
        c -=  c& -c;
    }
    return cnt;
}

int get1bitcnt1(int n){
    int cnt = 0;
    while(n != 0){
        cnt ++ ;
        n = n & (n - 1);
    }
    return cnt;
}



int main(){
    cout << get1bitcnt(5) << endl;
    cout << get1bitcnt(-1) << endl;
    cout << get1bitcnt1(5) << endl;
    cout << get1bitcnt1(-1) << endl;
    int n = 10;
    cout << (n ^(n - 1)) << endl;

}
#include <iostream>

using namespace std;

const int N = 100010;
int ne[N];
int n;

void get_ne(string pattern){
    ne[0] = -1;
    int i = 0, j = -1;
    while(i < n){
        if(j != - 1 && pattern[i] != pattern[j]) j = ne[j];
        else ne[++ i] = ++ j;
    }
    return;
}

int get_idx_str(string pattern, string source){
    int j = -1;
    for(int i = 0; i < source.size(); i ++ ){
        j ++ ;
        while(j != -1 && pattern[j] != source[i]) j = ne[j];
        //do some thing
        if(j == n - 1) return i - n + 1;
    }
    return -1;
}

int get_cnt_str(string pattern, string source){
    int j = -1;
    int cnt = 0;
    for(int i = 0; i < source.size(); i ++ ){
        j ++ ;
        while(j == n || j != -1 && pattern[j] != source[i]) j = ne[j];
        //do some thing
        if(j == n - 1) cnt ++ ;
    }
    return cnt;
}


int main(){
    string pattern = "ab";
    string source = "aababcbababbab";
    n = pattern.size();
    get_ne(pattern);
    cout << get_cnt_str(pattern, source) << endl;
}
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int C[N][N];


int main(){
    for(int i = 0; i < N; i ++ ){
        for(int j = 0; j < N && j < i; j ++ ){
            if(j == 0) C[i][j] = 0;
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
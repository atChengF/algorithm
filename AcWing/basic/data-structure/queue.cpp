#include <iostream>

using namespace std;

int const N = 1000010;

int a[N], q[N];



int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i ++ ){
        //出队列 , 队头元素 不再k里面
        if(hh <= tt && i - k + 1 > q[hh]) hh ++ ;
        
        while(hh <= tt && a[q[tt]] > a[i]) tt -- ;
        
        q[++ tt] = i;
        
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
    cout << " " << endl;
    //[hh, tt]  求最大值，单调递增队列
    hh = 0, tt = -1;
    for(int i = 0; i < n; i ++ ){
        //出队列 , 队头元素 不再k里面
        if(hh <= tt && i - k + 1 > q[hh]) hh ++ ;
        
        while(hh <= tt && a[q[tt]] < a[i]) tt -- ;
        
        q[++ tt] = i;
        
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
    
    return 0;
    
}
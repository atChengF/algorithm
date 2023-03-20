// 查找逆序对数量

#include <iostream>

using namespace std;

int find(int * arr, int l, int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    int res = find(arr, l, mid);
    res += find(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    int tmp[r - l + 1];
    while(i <= mid && j <= r) {
        if(arr[j] < arr[i]) {
            res += j - (k + l); 
            tmp[k ++ ] = arr[j ++ ];
        }  else tmp[k ++ ] = arr[i ++ ];
    
    }
    while(j <= r){
        res += j - (k + l); 
        tmp[k ++ ] = arr[j ++ ];
    }
    while(i <= mid) tmp[k ++ ] = arr[i ++ ];
    i = l, k = 0;
    while(i < r) arr[i ++ ] = tmp[k ++ ];
    return res;
}

int main(){
    int arr[] = {2, 3, 4, 5, 6, 1};
    cout << find(arr, 0, 5) << endl;

}

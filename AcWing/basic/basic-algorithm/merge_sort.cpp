#include <iostream>

using namespace std;

void merge_sort(int* arr, int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int tmp[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(arr[i] < arr[j]) tmp[k ++ ] = arr[i ++ ];
        else tmp[k ++ ] = arr[j ++ ]; 
    }
    while(i <= mid) tmp[k ++ ] = arr[i ++ ];
    while(j <= r) tmp[k ++ ] = arr[j ++ ];
    for(i = l, k = 0; i <= r; ) arr[i ++ ] = tmp[k ++ ];
}

int main(){
    int arr[5] = {2, 1, 7, -3, 0};
    merge_sort(arr, 0, 4);
    for(int i = 0; i < 5; i ++ ) cout << arr[i] << " ";
    cout << endl;
}
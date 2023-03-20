#include <iostream>

using namespace std;

int findNth(int* arr, int l, int r, int t){
    if(l == r) return arr[l];
    int i = l - 1, j = r + 1, x = arr[l + r >> 1];
    while(i < j){
        do i ++ ; while(arr[i] < x);
        do j -- ; while(arr[j] > x);
        if(i < j) swap(arr[i], arr[j]);
    }
    if(t <= j) return findNth(arr, l, j, t);
    else return findNth(arr, j + 1, r, t);
    
}

int main(){
    int arr[8] = {3, 1, 2, 7, 3, 2, 6, 9};
    for(int i = 0; i < 8; i ++ ) cout << findNth(arr, 0, 7, i) << " ";
    cout << endl;
}
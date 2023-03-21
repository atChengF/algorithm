#include <iostream>

using namespace std;
const int N = 100010;
int arr[N];

void quick_sort(int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = arr[l + r >> 1];
    while(i < j) {
        do i ++ ; while(arr[i] < x);
        do j -- ; while(arr[j] > x);
        if(i < j) swap(arr[i], arr[j]);
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main(){
    arr[0] = 2;
    arr[1] = 1;
    arr[2] = 7;
    arr[3] = -3;
    arr[4] = 0;
    quick_sort(0, 4);
    for(int i = 0; i < 5; i ++ ) cout << arr[i] << " ";
    cout << endl;
}
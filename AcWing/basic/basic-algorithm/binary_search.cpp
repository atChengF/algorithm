#include <iostream>

using namespace std;

//return the max idx (a[idx] <= x)
int binary_search(int * arr, int l, int r, int x){
    int i = l - 1, j = r + 1, mid = (i + j) / 2;
    while(i != j - 1) {
        if(arr[mid] <= x) i = mid;
        else j = mid;
        mid = (i + j) / 2;
    }
    return i;
}

int main(){
    int arr[5] = {1, 1, 2, 4, 4};
    cout << binary_search(arr, 0, 4, 0) << endl;
    cout << binary_search(arr, 0, 4, 1) << endl;
    cout << binary_search(arr, 0, 4, 3) << endl;
    cout << binary_search(arr, 0, 4, 4) << endl;
    cout << binary_search(arr, 0, 4, 5) << endl;
}
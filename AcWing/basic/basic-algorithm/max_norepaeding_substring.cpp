#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
int res = 0;
int arr[100010];
int cnt[100010];

int main(){
    cin >> n;
    for(int i = 0; i < n ; i ++ ){
        cin >> arr[i];
    }
    
    for(int i = -1, j = 0; j < n; j ++ ){
        if(cnt[arr[j]] == 0) cnt[arr[j]] ++ ;
        else {
            while(arr[++i] != arr[j]) cnt[arr[i]] -- ;
        }
        res = max(res, j - i);
    }
    cout << res << endl;
}
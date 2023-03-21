#include <iostream>
#include <cstring>
using namespace std;

void insert(int *b, int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    int n = 9;
    int a[] = {1, 2, 3, 4, 2, 3, 6, 1, 3};
    int b[9];
    memset(b, 0, sizeof(a));
    for(int i = 0; i < 9; i ++ ) insert(b, i, i, a[i]);
    insert(b, 1, 3, 2);
    insert(b, 0, 2, 1);
    int res = 0;
    for(int i = 0; i < 9; i ++) {
        res += b[i];
        cout << res << " ";
    }
    cout << endl;
    return 0;
}

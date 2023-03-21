//离散化
//稀疏的数据范围进行操作，可以使用离散化的方式，

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 300010;
typedef pair<int, int> PII;

int a[N], s[N], n, m;

vector<PII> add, query;

vector<int> alls;

//通过二分找到对应的下标，返回小于等于x的最大下标
int find(int x){
    int i = -1, j = alls.size();
    int mid = (i + j) >> 1;
    while(i != j - 1){
        if(alls[mid] <= x) i = mid;
        else j = mid;
        mid = i + j >> 1;
    }
    return i + 1; //将整体右移一位，从而避免考虑边界问题
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    
    for(int i = 0; i < m; i ++ ){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    
    sort(alls.begin(), alls.end());  // 对alls容器中的元素进行排序
    // 使用unique函数删除alls中相邻的重复元素，并返回指向去重后的尾部的迭代器
    // unique函数不会真正删除重复元素，而是将重复元素移动到尾部，并返回指向尾部的迭代器
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); 
    
    for(int i = 0; i < n; i ++ ){
        PII p = add[i];
        a[find(p.first)] += p.second;
    }
    for(int i = 0; i < alls.size(); i ++ ) cout << a[i] << " ";
    
    //预处理前缀和
    for(int i = 1; i <= alls.size(); i ++ ){
        s[i] = a[i] + s[i - 1];
    }
    
    for(int i = 0; i < m; i ++ ){
        PII p = query[i];
        
        cout << s[find(p.second)] - s[find(p.first) - 1] << endl;
    }

    
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return a < b; //从大到小
    }
};

int main(){
    priority_queue<int, vector<int>, cmp> q;
    q.push(10);
    q.push(2);
    q.push(3);
    q.push(6);
    cout << q.top() << " ";
    q.pop();
    cout << q.top() << " ";
}
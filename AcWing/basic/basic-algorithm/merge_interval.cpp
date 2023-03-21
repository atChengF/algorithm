#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
vector<PII> segs;

void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int l = -2e9, r = -2e9;
    for(int i = 0; i < segs.size(); i ++ ){
        PII p = segs[i];
        if(r < p.first){
            if(l != -2e9) res.push_back({l, r});
            l = p.first;
            r = p.second;
        } else {
            r = max(r, p.second);
        }
    }
    if(l != -2e9) res.push_back({l,r});
    segs = res;
    return;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}
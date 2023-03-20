#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//make sure vector has not prefix 0

// a[0] -> a[n] 0 is the low bit of num
vector<int> s2v(string s){
    vector<int> A;
    for(int i = s.size() - 1; i >= 0; i -- ) A.push_back(s[i] - '0');
    return A;
}

string v2s(vector<int> A){
    string res;
    for(int i = A.size() - 1; i >= 0; i -- ) res += A[i] + '0';
    return res;
}


//if A > B return positive, else A = B return 0 else return negative
int cmp(vector<int> A, vector<int> B){
    if(A.size() != B.size()) return A.size() - B.size();
    for(int i = A.size(); i > 0; i ++ ) {
        if(A[i] != B[i]) return A[i] - B[i];
    }
    return 0;
}

//make sure the size of A > B
vector<int> add(vector<int> A, vector<int> B){
    if(A.size() < B.size()) return add(B, A);
    int carry = 0;
    vector<int> C;
    for(int i = 0; i < A.size(); i ++){
        carry += A[i];
        carry += i < B.size() ? B[i] : 0;
        C.push_back(carry % 10);
        carry = carry / 10;
    }
    if(carry > 0) C.push_back(1);
    return C;
}

// make sure A > B
vector<int> sub(vector<int> A, vector<int> B){
    int c = cmp(A, B);
    vector<int> C;
    if(c == 0){
        C.push_back(0);
        return C;
    } 
    if(c < 0) return sub(B, A);

    int carry = 0;
    for(int i = 0; i < A.size(); i ++ ){
        carry = A[i] + carry;
        carry -= i < B.size() ? B[i] : 0;
        C.push_back((carry + 10) % 10);
        if(carry < 0){
            carry = -1;
        } else {
            carry = 0;
        }
    }
    //need to keep 1 bit 0
    while(C.back() == 0 && C.size() > 1) C.pop_back();
    return C;
}

vector<int> mul(vector<int> A, int b){
    vector<int> C;
    if(b == 0) {
        C.push_back(0);
        return C;
    }

    int carry = 0;
    for(int i = 0; i < A.size() || carry != 0; i ++ ){
        if(i < A.size()) carry += A[i] * b;
        C.push_back(carry % 10);
        carry /= 10;
    }
    
    //while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

vector<int> div(vector<int> A, int b){
    vector<int> C;
    int carry = 0;
    for(int i = A.size() - 1; i >= 0 ; i -- ){
        carry = carry * 10 + A[i];
        C.push_back(carry / b);
        carry = carry % b; 
    }

    reverse(C.begin(), C.end());
    while(C.back() == 0 && C.size() > 1) C.pop_back();

    return C;
}


int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << v2s(add(s2v(s1), s2v(s2)));
    cout << endl;
    cout << v2s(sub(s2v(s1), s2v(s2)));
    cout << endl;
    //mul
    string s3;
    int b;
    cin >> s3 >> b;
    cout << v2s(mul(s2v(s3), b)) << endl;
    cout << v2s(div(s2v(s3), b)) << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int diffculty(const vector<int>& v) {
    bool ok = true;
    int vn = v.size();
    for(int i=0; i<vn; i++) {
        if (v[i] != v[0])
            ok = false;
    }
    if (ok) return 1;

    bool ok1 = true, ok2 = true;
    for(int i=0; i<vn-1; i++) {
        if (abs(v[i+1]-v[i]) != 1)
            ok1 = false;
    }
    for(int i=0; i<vn-2; i++) {
        if (v[i+1]-v[i] != v[i+2]-v[i+1])
            ok2 = false;
    }
    if (ok1 && ok2) return 2;
    bool ok3 = true;
    for(int i=0; i<vn; i+=2) {
        if (v[i] != v[i%2])
            ok3=false;
    }
    if (ok3) return 4;
    if (ok2) return 5;
    return 10;
}

int N, cache[11111];
string s;
vector<int> A;
const int INF = 1e6;
int pi(int index) {
    if (index == N) return 0;
    if (index+2 >= N) return INF;
    int& ret = cache[index];
    if (ret != -1) return ret;
    ret = INF;
    vector<int> piece;
    for(int i=0; i<5 && index+i < N; i++) {
        piece.push_back(A[index+i]);
        if (i >= 2) ret = min(ret, diffculty(piece)+pi(index+i+1)); 
    }
    return ret;
}


int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> s;
        N = s.size();
        A.resize(N);
        
        for(int i=0; i<N; i++) {
            A[i] = s[i]-'0';
            cache[i] = -1;
        }
        cout << pi(0) << endl;
    }
}
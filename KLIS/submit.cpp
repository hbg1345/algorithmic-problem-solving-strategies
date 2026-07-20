#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[550], cache[550];
long long countCache[550];

int N, K;
int lis(int start) {
    int& ret = cache[start+1];
    if (ret != -1) return ret;
    ret = 1;
    for(int next=start+1; next<N; next++) {
        if (start == -1 || A[next] > A[start])
            ret = max(ret, 1+lis(next));
    }
    return ret;
}

const long long MAX = 1e10;
long long countLis(int start) {
    long long& ret = countCache[start+1];
    if (ret != -1) return ret;
    int len = lis(start);
    ret = 0;
    for(int next=start+1; next<N; next++) {
        if (start == -1 || A[next] > A[start])
            if (len == 1+lis(next)) {
                ret += countLis(next);
            }
    }
    ret = min(MAX, max(1ll, ret));
    return ret;
}

void kth(int start, int k, vector<int>& picked) {
    if (start == N) return;
    int len = lis(start);
    vector<pair<int, int>> V;
    for(int next=start+1; next<N; next++) {
        if (start == -1 || A[next] > A[start])
            if (len == 1+lis(next)) {
                V.push_back({A[next], next});
            }
    }
    sort(V.begin(), V.end());
    long long sum = 0;
    for(int i=0; i<V.size(); i++) {
        int value = V[i].first, index = V[i].second;
        if (sum + countLis(index) >= k) {
            picked.push_back(value);
            return kth(index, k-sum, picked);
        }
        sum += countLis(index);
    }
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        for(int i=0; i<550; i++)
            cache[i] = countCache[i] = -1;
        
        cin >> N >> K;
        for(int i=0; i<N; i++)
            cin >> A[i];
        vector<int> picked;
        kth(-1, K, picked);
        cout << picked.size() << endl;
        for(auto pp: picked) cout << pp << ' ';
        cout << endl;
    }    
}
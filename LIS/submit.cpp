#include <iostream>
#include <vector>
using namespace std;

int A[550], cache[550];
int N;

int getLengthOfLIS(int i) {
    if (i == N)
        return 0;
    int& ret = cache[i];
    if (ret != -1)
        return ret;
    ret = 1;
    for(int j=i+1; j<N; j++) {
        if (A[j] > A[i]) 
            ret = max(ret, 1+getLengthOfLIS(j));
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> A[i];
            cache[i] = -1;
        }
        int ans = 1;
        for(int i=0; i<N; i++)
            ans = max(ans, getLengthOfLIS(i));
        cout << ans << endl;
    }
}
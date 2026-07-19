#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int n;
long long cache[101];
long long tiling(int i) {
    if (i == n) return 1;
    long long& ret = cache[i];
    if (ret != -1) return ret;
    ret = tiling(i+1);
    if (i+2 <= n) ret += tiling(i+2);
    return ret % MOD;
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        for(int i=0; i<n; i++)
            cache[i] = -1;      
        cout << tiling(0) << endl;
    }
}

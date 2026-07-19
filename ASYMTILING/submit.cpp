#include <iostream>
using namespace std;

const long long MOD = 1e9+7;
long long cache[110];

long long tiling(int x) {
    if (x <= 1) return 1;
    long long& ret = cache[x];
    if (ret != -1) return ret;
    ret = tiling(x-1)+tiling(x-2);
    return ret % MOD;
}

int main() {
    int C;
    cin >> C;
    for(int i=0; i<110; i++)
        cache[i] = -1;

    while (C--) {
        int n;
        cin >> n;
        long long ans = tiling(n);
        long long symmetric = 0;
        if (n & 1) 
            symmetric = tiling((n-1) / 2);
        else 
            symmetric = (tiling(n/2) + tiling(n/2-1)) % MOD;
        cout << (ans+MOD-symmetric)%MOD << endl;
    }    
}
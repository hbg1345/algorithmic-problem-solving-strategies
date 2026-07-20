#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9+7;
int n, m;
vector<int> ve, cve;

long long cache[22][1<<15][2];
long long count(int sum, int used, int equal, int vIndex) {
    if (used == (1<<n)-1) {
        if (sum == 0) return 1;
        return 0;
    }
    long long& ret = cache[sum][used][equal];
    if (ret != -1) return ret;
    ret = 0;
    for(int i=0; i<n; i++) {
        if (used & (1<<i) || (i != 0 && cve[i] == cve[i-1] && !(used & (1<<(i-1)))))
            continue;
        if (!equal)
            ret += count((sum*10+cve[i])%m, used+(1<<i), 0, vIndex+1);
        else if (cve[i] <= ve[vIndex]) {
            int nextEqual = (cve[i] == ve[vIndex]) ? 1 : 0;
            ret += count((sum*10+cve[i])%m, used+(1<<i), nextEqual, vIndex+1);
        }
        ret %= MOD;
    }
    return ret;
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        for(int i=0; i<22; i++)
            for(int j=0; j<(1<<15); j++)
                cache[i][j][0] = cache[i][j][1] = -1;
        long long e;
        cin >> e >> m;
        long long ce = e;
        ve.clear();
        while (ce) {
            ve.push_back(ce%10);
            ce /= 10;  
        }
        n = ve.size();
        reverse(ve.begin(), ve.end());
        cve = ve;
        sort(cve.begin(), cve.end());
        long long ans = count(0, 0, 1, 0);
        if (e % m == 0)
            ans = (ans+MOD-1)%MOD;
        cout << ans << endl;
    }
}
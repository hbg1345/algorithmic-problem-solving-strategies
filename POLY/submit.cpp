#include <iostream>
using namespace std;

const int MOD = 1e7;
long long cache[110][110];

long long count(int n, int top) {
    if (n == 0) return 1;
    long long& ret = cache[n][top];
    if (ret != -1) return ret;
    ret = 0;
    for(int use=1; use<=n; use++) {
        if (top == 0) ret += count(n-use, use);
        else ret += (top+use-1)*count(n-use, use);
        ret %= MOD;
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    for(int i=0; i<110; i++)
        for(int j=0; j<110; j++)
            cache[i][j] = -1;

    while (C--) {
        int n;
        cin >> n;
        cout << count(n, 0) << endl;    
    }    
}
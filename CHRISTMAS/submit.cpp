#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int dolls[101010], pSum[101010], cnt[101010], cache[101010];
int nxt[101010];
vector<int> pos[101010];
const int MOD = 20091101;

int maxOrders(int start) {
    if (start == N+1) return 0;
    if (start > N+1) return -N;
    int& ret = cache[start];
    if (ret != -1) return ret;
    return ret = max(maxOrders(start+1), 1 + maxOrders(nxt[start]));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for(int i=0; i<101010; i++)
            cnt[i] = 0, cache[i] = -1, pos[i].clear();        
        cin >> N >> K;
        for(int i=0; i<101010; i++)
            nxt[i] = N+2;
        for(int i=0; i<N; i++)
            cin >> dolls[i+1];
        pSum[0] = 0;
        for(int i=1; i<=N; i++) {
            pSum[i] = pSum[i-1] + dolls[i];
            pSum[i] %= K;
        }
        cnt[0] = 1;
        int ans1 = 0;
        for(int i=1; i<=N; i++) {
            ans1 += cnt[pSum[i]];
            ans1 %= MOD;
            cnt[pSum[i]]++;
        }
        
        for(int i=0; i<=N; i++) {
            vector<int>& vec = pos[pSum[i]];
            if (vec.size())
                nxt[vec.back()+1] = i+1;
            vec.push_back(i);
        }
        cout << ans1 << ' ' << maxOrders(1) << endl;

    }   
        
}
#include <iostream>
#include <algorithm>
using namespace std;

int N, K, M, L;
int R[14], C[11];

int cache[11][1<<12];
const int INF = 200;

int minSemester(int start, int taken) {
    if (__builtin_popcount(taken) >= K) return 0;
    if (start == M) return INF;
    int& ret = cache[start][taken];
    if (ret != -1)  return ret;
    ret = minSemester(start+1, taken);
    int canTake = 0;
    for(int i=0; i<N; i++) {
        if ((taken & R[i]) == R[i]) canTake += 1<<i;
    }
    canTake &= C[start];
    canTake &= ~taken;
    for(int take=canTake; take; take=(take-1)&canTake) {
        if (__builtin_popcount(take) <= L) {
            ret = min(ret, 1 + minSemester(start+1, taken | take));
        }
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for(int i=0; i<14; i++)
            R[i] = 0;
        for(int i=0; i<11; i++)
            C[i] = 0;
        for(int i=0; i<11; i++)
            for(int j=0; j<(1<<12); j++)
                cache[i][j] = -1;
        
        cin >> N >> K >> M >> L;
        for(int i=0; i<N; i++) {
            int r;
            cin >> r;
            while(r--) {
                int required;
                cin >> required;
                R[i] |= 1<<required;   
            }
        }
        for(int i=0; i<M; i++) {
            int c;
            cin >> c;
            while (c--) {
                int subject;
                cin >> subject;
                C[i] |= 1<<subject;
            }
        }
        int ans = minSemester(0, 0);
        if (ans == INF) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }   
        
}
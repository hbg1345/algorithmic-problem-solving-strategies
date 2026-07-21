#include <iostream>
#include <algorithm>
using namespace std;

int N;
int x[101], y[101], r[101], ans[101];
bool included[101];
pair<int, int> ri[101];
int main() {
    int T;
    cin >> T;
    while (T--) {
        for(int i=0; i<101; i++)
            included[i] = false, ans[i] = 1;
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> x[i] >> y[i] >> r[i];
        }
        
        for(int i=0; i<N; i++)
            ri[i] = {r[i], i};
        sort(ri, ri+N);
        int ret = 0;
        for(int i=0; i<N; i++) {
            int idx = ri[i].second;
            int mx1, mx2;
            mx1 = mx2 = 0;
            for(int j=0; j<i; j++) {
                if (included[j]) continue;
                int jdx = ri[j].second;
                if ((x[idx]-x[jdx])*(x[idx]-x[jdx])
                    + (y[idx]-y[jdx])*(y[idx]-y[jdx]) <= (r[idx]-r[jdx])*(r[idx]-r[jdx])) {
                    included[j] = true;
                    if (ans[j] > mx2) {
                        mx2 = ans[j];
                        if (mx2 > mx1) swap(mx1, mx2);
                    }
                    ans[i] = max(ans[i], 1+ans[j]);
                }
            }
            ret = max(ret, mx1+mx2);
        }
        cout << ret << endl;
    }   
        
}
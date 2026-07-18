#include <iostream>
#include <vector>
using namespace std;

int clocks[16];
vector<int> connectedClocks[10];
const int INF = 1e5;

int minPushes(int button) {
    bool allSet = true;
    for(int i=0; i<16; i++) {
        if (clocks[i] != 4) {
            allSet = false;
        }
    }
    if (allSet) {
        return 0;
    }
    if (button == 10) return INF;
    int oldClocks[16];
    for(int i=0; i<16; i++)
        oldClocks[i] = clocks[i];
    int ret = INF;
    for(int i=0; i<4; i++) {
        for(auto c: connectedClocks[button]) {
            clocks[c] = (clocks[c]-1+4+i) % 4 + 1;
        }
        ret = min(ret, i+minPushes(button+1));
        for(int j=0; j<16; j++)
            clocks[j] = oldClocks[j];
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    connectedClocks[0] = {0, 1, 2};
    connectedClocks[1] = {3, 7, 9, 11};
    connectedClocks[2] = {4, 10, 14, 15};
    connectedClocks[3] = {0, 4, 5, 6, 7};
    connectedClocks[4] = {6, 7, 8, 10, 12};
    connectedClocks[5] = {0, 2, 14, 15};
    connectedClocks[6] = {3, 14, 15};
    connectedClocks[7] = {4, 5, 7, 14, 15};
    connectedClocks[8] = {1, 2, 3, 4, 5};
    connectedClocks[9] = {3, 4, 5, 9, 13};
    
    while (C--) {
        vector<bool> pushed;
        for(int i=0; i<16; i++) {
            cin >> clocks[i];
            clocks[i] /= 3;
        }
        int ans = minPushes(0);
        if (ans >= INF) ans = -1;
        cout << ans << endl;
    }
}
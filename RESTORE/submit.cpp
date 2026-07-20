#include <iostream>

using namespace std;

int k;
string subStrs[20];
int olcache[20][20];

int overlap(int a, int b) {
    if (a == -1) return 0;
    int an = subStrs[a].size(), bn = subStrs[b].size();
    int& ret = olcache[a][b];
    if (ret != -1) return ret;
    int minn = min(an, bn);
    for(ret=minn; ret >= 0; ret--) {
        if (subStrs[a].substr(an-ret, ret) == subStrs[b].substr(0, ret))
            return ret;
    }
    return 0;
}
int lenCache[20][1<<15];
const int INF = 1e3;
int minLen(int start, int used) {
    if (used == (1<<k)-1) return 0;
    int& ret = lenCache[start+1][used];
    if (ret != -1) return ret;
    ret = INF;
    for(int next=0; next<k; next++) {
        if (!(used & (1<<next))) {
            ret = min(ret, (int)subStrs[next].size()-overlap(start, next) + minLen(next, used+(1<<next)));
        }
    }
    return ret;
}
void reconstruct(int start, int used, string& restored) {
    if (used == (1<<k)-1) return;
    int ret = minLen(start, used);
    for(int next=0; next<k; next++) {
        if (!(used & (1<<next))) {
            if (ret == (int)subStrs[next].size()-overlap(start, next) + minLen(next, used+(1<<next))) {
                restored += subStrs[next].substr(overlap(start, next), subStrs[next].size()-overlap(start, next));
                return reconstruct(next, used+(1<<next), restored);
            }
        }
    }
}

void precal() {
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            olcache[i][j] = -1;
    for(int i=0; i<20; i++)
        for(int j=0; j<(1<<15); j++)
            lenCache[i][j] = -1;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        precal();
        cin >> k;
        for(int i=0; i<k; i++) {
            cin >> subStrs[i];
        }
        int used = 0;
        for(int i=0; i<k; i++) {
            if (used & (1<<i)) continue;
            for(int j=0; j<k; j++) {
                if (!(used & 1<<j) && i != j) {
                    if (subStrs[i].find(subStrs[j]) != string::npos)
                        used += 1<<j;
                }
            }
        }
        string restored;
        reconstruct(-1, used, restored);
        cout << restored << endl;
    }
}
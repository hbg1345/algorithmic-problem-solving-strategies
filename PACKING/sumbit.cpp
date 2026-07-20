#include <iostream>
#include <vector>
using namespace std;

int n, w;
int cache[110][1010], volume[110], value[110];
string name[110];

void precal() {
    for(int i=0; i<110; i++)
        for(int j=0; j<1010; j++)
            cache[i][j] = -1;
}
const int INF = 1e7;
int packing(int start, int capacity) {
    if (capacity < 0) return -INF;
    if (start == n) return 0;
    int& ret = cache[start][capacity];
    if (ret != -1) return ret;
    int notuse = packing(start+1, capacity);
    int use = value[start] + packing(start+1, capacity-volume[start]);
    ret = max(use, notuse);
    return ret;
}

void reconstruct(int start, int capacity, vector<int>& picked) {
    if (capacity < 0 || start == n) return;
    if (packing(start, capacity) == packing(start+1, capacity))
        return reconstruct(start+1, capacity, picked);
    picked.push_back(start);
    return reconstruct(start+1, capacity-volume[start], picked);
}

int main() {
    int C;
    cin >> C;

    while (C--) {
        precal();
        cin >> n >> w;
        for(int i=0; i<n; i++) {
            cin >> name[i] >> volume[i] >> value[i];
        }
        cout << packing(0, w) << ' ';
        vector<int> picked;
        reconstruct(0, w, picked);
        cout << picked.size() << endl;
        for(auto pp: picked) {
            cout << name[pp] << endl;
        }
        
    }    
}
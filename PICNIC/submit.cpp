#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> friends;

int makePair(int student, int numPairs, vector<bool> &paired) {
    if (2*numPairs == N) 
        return 1;
    if (student == N)
        return 0;
    if (paired[student]) 
        return makePair(student+1, numPairs, paired);
    int ret = 0;
    for(auto f: friends[student]) {
        if (!paired[f]) {
            paired[f] = true;
            ret += makePair(student+1, numPairs+1, paired);
            paired[f] = false;
        }
    }
    return ret;
}

int makePair2(vector<bool> &paired) {
    int student = -1;
    for(int i=0; i<N; i++) {
        if (!paired[i]) {
            student = i;
            break;
        }
    }
    if (student == -1)
        return 1;
    int ret = 0;
    for(auto f: friends[student]) {
        if (!paired[f]) {
            paired[student] = paired[f] = true;
            ret += makePair2(paired);
            paired[student] = paired[f] = false;
        }
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> N >> M;
        friends.clear();
        friends.resize(N);
        for(int i=0; i<M; i++) {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            friends[a].push_back(b);
        }
        vector<bool> paired(N);
        // cout << makePair2(paired) << endl;
        cout << makePair(0, 0, paired) << endl;
    }
}
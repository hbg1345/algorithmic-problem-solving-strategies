#include <iostream>
#include <vector>

using namespace std;

void makePermutation(int n, vector<bool> &picked, vector<int> &P) {
    bool allPicked = true;
    for(int i=0; i<n; i++) {
        if (!picked[i]) {
            allPicked = false;
            picked[i] = 1;
            P.push_back(i);
            makePermutation(n, picked, P);
            P.pop_back();
            picked[i] = 0;
        }
    }
    if (allPicked) {
        for(auto &elem: P) {
            cout << elem << ' ';
        }
        cout << endl;
    }
}
int main() {
    int N = 4;
    vector<bool> picked(N);
    vector<int> P;
    makePermutation(N, picked, P);
}
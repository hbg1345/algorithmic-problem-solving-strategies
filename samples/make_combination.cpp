#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &vec) {
    for(auto v: vec)
        cout << v << ' ';
    cout << endl;
}
void pick(int n, int toPick, vector<int> &picked) {
    if (toPick == 0) {
        print(picked);
        return;
    }
    int smallest = picked.empty() ? 1 : picked.back()+1;
    for(int next=smallest; next<=n; next++) {
        picked.push_back(next);
        pick(n, toPick-1, picked);
        picked.pop_back();
    }
}
int main() {
    int N = 4;
    int M = 2;
    vector<int> test;
    pick(N, M, test);
}
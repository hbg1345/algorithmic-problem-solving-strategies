#include <iostream>
#include <vector>
using namespace std;

vector<int> h;
int maxRectangle(int lo, int hi) {
    if (lo==hi) return h[hi];
    int mid = (hi+lo)/2;
    int ret = max(maxRectangle(lo, mid), maxRectangle(mid+1, hi));
    int left = mid;
    int right = mid+1;
    int height = min(h[left], h[right]);
    ret = max(ret, height*2);
    while (lo < left || right < hi) {
        if (lo == left || (right < hi && h[right+1] > h[left-1])) {
            right++;
        } else {
            left--;
        }
        height = min(h[left], height);
        height = min(h[right], height);
        ret = max(ret, height*(right-left+1));
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        int N;
        cin >> N;
        h.clear();
        h.resize(N);
        for(int i=0; i<N; i++)
            cin >> h[i];
        cout << maxRectangle(0, N-1) << endl;
    }
}
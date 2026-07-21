#include <iostream>
#include <vector>
using namespace std;

int N;
int pre[101], in[101];

void post(int a, int b, int c, int d, vector<int>& ans) {
    if (b-a <= 0) return;
    if (b-a == 1) {
        ans.push_back(pre[a]);
        return;
    }
    int root = pre[a];
    int leftlen = 0;
    while(leftlen < d-c && in[c+leftlen] != root) {
        leftlen++;
    }
    post(a+1, a+1+leftlen, c, c+leftlen, ans);
    post(a+1+leftlen, b, c+1+leftlen, d, ans);
    ans.push_back(root);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> pre[i];
        for(int i=0; i<N; i++)
            cin >> in[i];
        vector<int> ans;
        post(0, N, 0, N, ans);
        for(int i=0; i<N; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }   
        
}
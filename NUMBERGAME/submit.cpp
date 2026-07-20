#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, A[55], cache[55][55];
const int NOTFILLED = -1e5;

int scoreDiff(int a, int b, int len) {
    if (len == 0) return 0;
    int& ret= cache[a][b];
    if (ret != NOTFILLED) return ret;
    ret = max(ret, A[a]-scoreDiff(a+1, b, len-1));
    ret = max(ret, A[b]-scoreDiff(a, b-1, len-1));
    if (len >= 2) {
        ret = max(ret, -scoreDiff(a+2, b, len-2));
        ret = max(ret, -scoreDiff(a, b-2, len-2));
    }
    return ret;
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        for(int i=0; i<55; i++)
            for(int j=0; j<55; j++)
                cache[i][j] = NOTFILLED;
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> A[i];    
        cout << scoreDiff(0, n-1, n) << endl;
    }
        
}
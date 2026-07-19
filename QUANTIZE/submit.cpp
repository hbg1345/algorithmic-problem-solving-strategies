#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, A[101], pSum[101], pSqSum[101];
int cache[101][11];
const int INF = 1e9;

void precal() {
    pSum[0] = A[0];
    pSqSum[0] = A[0]*A[0];
    for(int i=1; i<N; i++) {
        pSum[i] = pSum[i-1]+A[i];
        pSqSum[i] = pSqSum[i-1]+A[i]*A[i];
    }
}

int minError(int a, int b) {
    int len = b-a+1;
    int sum = pSum[b]-pSum[a]+A[a];
    int mean = (int)(0.5+(double)sum / len);
    return pSqSum[b]-pSqSum[a]+A[a]*A[a]+len*mean*mean-2*mean*sum;
}
int MSE(int i, int used) {
    if (i == N) return 0;
    if (used == S) return INF;
    int& ret = cache[i][used];
    if (ret != -1) return ret;
    ret = INF;
    for(int len=1; i+len <= N; len++) {
        ret = min(ret, MSE(i+len, used+1) + minError(i, i+len-1));
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> N >> S;
        for(int i=0; i<N; i++)
            cin >> A[i];
        for(int i=0; i<N; i++)
            for(int j=0; j<=S; j++)
                    cache[i][j] = -1;
        sort(A, A+N);    
        precal();
        cout << MSE(0, 0) << endl;
    }
}
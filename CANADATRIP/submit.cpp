#include <iostream>
using namespace std;

int N, K;
int L[5005], M[5005], G[5005];

bool decision(int x) {
    long long num = 0;
    for(int i=0; i<N && num<K; i++) {
        if (x-L[i]+M[i] >= 0)
            num += min((x-L[i]+M[i])/G[i], M[i]/G[i])+1;
        }
    return num >= K;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for(int i=0; i<N; i++)
            cin >> L[i] >> M[i] >> G[i];
        int wa = -1, ac = 8030000;
        while (ac - wa > 1) {
            int mid = (wa+ac)/2;
            if (decision(mid)) ac = mid;
            else wa = mid;
        }
        cout << ac << endl;
    }   
        
}
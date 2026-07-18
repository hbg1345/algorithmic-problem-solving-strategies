#include <iostream>
#include <vector>
using namespace std;
int main() {
    int C;
    cin >> C;
    cout.precision(15);
    cout << fixed;
    while (C--) {
        int N, L;
        cin >> N >> L;
        vector<int> arr(N);
        for(int i=0; i<N; i++) 
            cin >> arr[i];
        
        double ans = 1e6;
        for(int i=0; i<N; i++) {
            int len = 0;
            int sum = 0;
            for(int j=i; j<N; j++) {
                len++;
                sum += arr[j];
                if (len >= L)
                    ans = min(ans, (double)sum/len);
            }
        }
        cout << ans << endl;
    }
}
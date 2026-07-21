#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const long long MOD = 1ll<<32;
int main() {
    int C;
    cin >> C;
    while (C--) {
        int K, N;
        cin >> K >> N;
        deque<long long> ranges;
        long long sum = 0;
        long long a = 1983;
        int zero = 0;
        long long ans = 0;
        for(int i=0; i<N; i++) {
            if (i > 0) a = (a* 214013 + 2531011) % MOD;
            int input = a % 10000 + 1;
            ranges.push_back(input);
            sum += input;
            while (sum > K) {
                sum -= ranges.front();
                ranges.pop_front();
                zero = 0;
            }
            if (sum == K) {
                while (ranges.size() && ranges.front() == 0) {
                    zero++;
                    ranges.pop_front();
                }
                ans += zero+1;
            }
        }
        cout << ans << endl;
    }
}
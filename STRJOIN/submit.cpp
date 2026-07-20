#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int C;
    cin >> C;
    while (C--) {
        int N;
        cin >> N;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<N; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }
        int sum = 0;
        while (pq.size() > 1) {
            int min1 = pq.top();
            pq.pop();
            int min2 = pq.top();
            pq.pop();
            sum += min1 + min2;
            pq.push(min1+min2);
        }
        cout << sum << endl;
    }   
        
}
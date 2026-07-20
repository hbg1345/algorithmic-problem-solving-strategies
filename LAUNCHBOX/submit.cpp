#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int C;
    cin >> C;
    while (C--) {
        int N;
        cin >> N;
        vector<pair<int, int>> ems(N);
        for(int i=0; i<N; i++)
            cin >> ems[i].second;
        for(int i=0; i<N; i++) 
            cin >> ems[i].first;
        sort(ems.begin(), ems.end());
        reverse(ems.begin(), ems.end());
        int msum = 0;
        int eatEnd = 0;
        for(int i=0; i<N; i++) {
            int e = ems[i].first, m = ems[i].second;
            msum += m;
            eatEnd = max(eatEnd, msum+e);
        }
        cout << eatEnd << endl;
    }   
        
}
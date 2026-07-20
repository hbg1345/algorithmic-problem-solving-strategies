#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double cameras[201];
int N, M;
bool canPlace(double x) {
    int start = 0;
    int place = 1;
    for(int i=1; i<M; i++) {
        if (cameras[i] - cameras[start] >= x) {
            place++;
            start = i;
        }
    }
    return place >= N;
}

int main() {
    cout.precision(2);
    cout << fixed;
    int C;
    cin >> C;
    while (C--) {
        cin >> N >> M;
        for(int i=0; i<M; i++)
            cin >> cameras[i];
        if (N == 1) {
            cout << 0 << endl;
        } else {
            double lo = 0, hi = 241;
            for(int rep=0; rep<100; rep++) {
                double mid = (lo+hi)*0.5;
                if (canPlace(mid)) lo = mid;
                else hi = mid;
            }
            cout << lo << endl;
        }
    }   
        
}
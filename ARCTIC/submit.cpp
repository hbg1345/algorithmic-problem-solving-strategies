#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double x[201], y[201];
bool visit[201];
int N;

double dist(int i, int j) {
    return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}
double canCover(double x) {
    for(int i=0; i<201; i++)
        visit[i] = 0;
    visit[0] = 1;
    vector<int> visited;
    visited.push_back(0);
    int num = 1;
    while (num < N && visited.size()) {
        int i = visited.back();
        visited.pop_back();
        for(int j=0; j<N; j++) {
            if (!visit[j] && dist(i, j) <= x) {
                visit[j] = 1;
                visited.push_back(j);
                num++;
            }
        }
    }
    return num == N;
}

int main() {
    cout.precision(2);
    cout << fixed;
    int C;
    cin >> C;
    while (C--) {
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> x[i] >> y[i];
        double lo = 0, hi = 2e6;
        for(int it=0; it<100; it++) {
            double mid = (lo+hi)/2;
            if (canCover(mid)) hi = mid;
            else lo = mid;
        }
        cout << sqrt(lo) << endl;
    }   
        
}
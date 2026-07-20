#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double x[110], y[110], r[110];
pair<double, double> ranges[110];
int n;
double pi = 2 * acos(0);

void converToRagnes() {
    for(int i=0; i<n; i++) {
        double loc = fmod(2*pi+atan2(y[i], x[i]), 2*pi);
        double range = 2*asin(r[i]/16);
        ranges[i].first = loc-range;
        ranges[i].second = loc+range;
    }
    sort(ranges, ranges+n);
}

int solveLinear(double begin, double end) {
    int used = 0, i = 0;
    while (begin < end) {
        double maxRight = -1;
        while (i < n && ranges[i].first <= begin) {
            maxRight = max(maxRight, ranges[i].second);
            i++;
        }
        if (maxRight <= begin) {
            return n+1;
        } 
        begin = maxRight;
        used++;
    }
    return used;
}
int solveCircular() {
    int ret = n+1;
    for(int i=0; i<n; i++) {
        if (ranges[i].first <= 0 || ranges[i].second >= 2*pi) {
            double begin = fmod(ranges[i].second, 2*pi);
            double end = fmod(ranges[i].first+2*pi, 2*pi);
            ret = min(ret, 1+solveLinear(begin, end));
        }
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    while (C--) {

        cin >> n;
        for(int i=0; i<n; i++)
             cin >> y[i] >> x[i] >> r[i];
        converToRagnes();
        int ans = solveCircular();
        if (ans == n+1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }   
        
}
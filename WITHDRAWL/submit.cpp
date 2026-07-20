#include <iostream>
#include <algorithm>
using namespace std;

int r[1010], c[1010];
double b[1010];
int n, k;
bool decision(double x) {
    for(int i=0; i<n; i++)
        b[i] = x*c[i]-r[i];
    sort(b, b+n);
    reverse(b, b+n);
    double sum = 0;
    for(int i=0; i<k; i++)
        sum += b[i];
    return sum >= 0;
}

int main() {
    cout.precision(15);
    cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for(int i=0; i<n; i++) {
            cin >> r[i] >> c[i];
        }
        double wa = 0, ac = 1;
        for(int it=0; it<100; it++) {
            double mid = (ac + wa) *0.5;
            if (decision(mid)) ac = mid;
            else wa = mid;
        }
        cout << ac << endl;
    }   
        
}
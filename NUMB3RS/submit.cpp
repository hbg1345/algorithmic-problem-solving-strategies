#include <iostream>
using namespace std;

double cache[55][110];
int A[55][55], degree[55];
int n, d, p;

double probability(int town, int day) {
    if (day == 0 && town == p) return 1;
    if (day == 0) return 0;

    double& ret = cache[town][day];
    if (ret != -1) return ret;
    ret = 0;
    for(int before=0; before<n; before++) {
        if (A[town][before]) {
            ret += probability(before, day-1) / degree[before];
        }
    }
    return ret;
}
void precal() {
    for(int i=0; i<55; i++)
        for(int j=0; j<110; j++)
            cache[i][j] = -1;
}

int main() {
    cout.precision(15); cout << fixed;
    int C;
    cin >> C;

    while (C--) {
        precal();
        cin >> n >> d >> p;
        for(int i=0; i<n; i++) {
            degree[i] = 0;
            for(int j=0; j<n; j++) {
                cin >> A[i][j];
                degree[i] += A[i][j];
            }
        }
        int t;
        cin >> t;
        while (t--) {
            int q;
            cin >> q;
            cout << probability(q, d) << ' ';
        }
        cout << endl;
    }    
}
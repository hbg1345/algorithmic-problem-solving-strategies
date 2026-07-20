#include <iostream>
#include <vector>

using namespace std;

int cache[201], price[22], value[22];

int main() {
    int C;
    cin >> C;
    while (C--) {
        int n, m;
        
        cin >> n >> m;
        m /= 100;
        for(int i=0; i<201; i++)
            cache[i] = 0;
        for(int i=0; i<n; i++) {
            cin >> price[i] >> value[i];
            price[i] /= 100;
        }
        for(int i=0; i<=m; i++) {
            for(int j=0; j<n; j++) {
                if (i-price[j] >= 0)
                    cache[i%201] = max(cache[i%201], value[j] + cache[(i-price[j]) % 201]);
            }
        }
        cout << cache[m%201] << endl;
    }
        
}
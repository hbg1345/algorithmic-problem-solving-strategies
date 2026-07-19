#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int cache[110][110];
int triangle[110][110];

int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> N;
        for(int i=0; i<N; i++) {
            for(int j=0; j<i+1; j++) {
                cin >> triangle[i][j];
                cache[i][j] = 0;
            }
        }
        cache[0][0] = triangle[0][0];
        for(int i=1; i<N; i++)
            for(int j=0; j<i+1; j++) {
                cache[i][j] = max(cache[i][j], triangle[i][j]+cache[i-1][j]);
                if (j-1 >= 0)
                    cache[i][j] = max(cache[i][j], triangle[i][j]+cache[i-1][j-1]);
            }
        cout << *max_element(cache[N-1], cache[N-1]+N) << endl;
    }
}
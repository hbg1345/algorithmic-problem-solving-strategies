#include <iostream>
#include <vector>

using namespace std;
string d[3] = {"FX", "FX+YF", "FX+YF+FX-YF"};

int cache[55];
const int MAX = 1e9;
int len(int n) {
    if (n <= 2) return d[n].size();
    int& ret = cache[n];
    if (ret != -1) return ret;
    ret = 0;
    for(int i=n-1; i>=0; i--) {
        ret += len(i)+1;
        if (ret >= MAX) break;
    }
    ret += 2;
    ret = min(ret, MAX);
    return ret;
}
char kth(int n, int k) {
    if (n <= 2) return d[n][k-1];
    int sum = 0;
    for(int i=n-1; i>=0; i--) {
        if (sum + len(i) >= k) 
            return kth(i, k-sum);
        sum += len(i)+1;
        if (sum == k) {
            if (i == n-1) return '+';
            return '-';
        }
    }
    if (sum+1 == k) return 'Y';
    return 'F';
}

int main() {
    for(int i=0; i<55; i++)
        cache[i] = -1;
    int C;
    cin >> C;
    while (C--) {
    int n, p, l;
    cin >> n >> p >> l;
    for(int k=0; k<l; k++)
        cout << kth(n, p+k);
    cout << endl;
    }    
}
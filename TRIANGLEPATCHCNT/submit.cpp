#include <iostream>
using namespace std;

int n;
int cache[101][101], board[100][100], scoreCache[100][100];
void precal() {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cache[i][j] = scoreCache[i][j] = -1;
}
int score(int y, int x) {
    if (y == n) return 0;
    int& ret = scoreCache[y][x];
    if (ret != -1) return ret;

    ret = board[y][x]+max(score(y+1, x), score(y+1, x+1));
    return ret;
}
int count(int y, int x) {
    if (y == n-1) return 1;
    int& ret = cache[y][x];
    if (ret != -1)
        return ret;
    if (score(y+1, x) == score(y+1, x+1))
        ret = count(y+1, x) + count(y+1, x+1);
    else if (score(y+1, x) > score(y+1, x+1))
        ret = count(y+1, x);
    else
        ret = count(y+1, x+1);
    return ret;
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        for(int i=0; i<n; i++) 
            for(int j=0; j<i+1; j++)
                cin >> board[i][j];
        precal();
        cout << count(0, 0) << endl;
    }
}
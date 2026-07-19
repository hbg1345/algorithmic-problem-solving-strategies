#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
int cache[110][110];
int n;
int reach(int x, int y) {
    if (x >= n || y >= n) return 0;
    if (x == n-1 && y == n-1) return 1;
    int& ret = cache[x][y];
    if (ret != -1) return ret;
    int jumpSize = board[x][y];
    ret = reach(x+jumpSize, y) | reach(x, y+jumpSize);
    return ret;
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        board.clear();
        board.resize(n);

        for(int i=0; i<n; i++) {
            board[i].resize(n);
            for(int j=0; j<n; j++)  {
                cin >> board[i][j];  
                cache[i][j] = -1;
            }          
        }        
        if (reach(0, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
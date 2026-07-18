#include <iostream>
#include <vector>
using namespace std;

vector<string> board(5);
int dp[10][5][5];
int search(string &target, int found, int x, int y) {
    if (board[x][y] != target[found])
        return 0;
    if (found == target.size()-1)
        return 1;
    if (dp[found][x][y] != -1)
        return dp[found][x][y];
    int &ret = dp[found][x][y];
    ret = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int nx = x+i, ny = y+j;
            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && (nx != x || ny != y)) {
                if (board[nx][ny] == target[found+1]) {
                    if (search(target, found+1, nx, ny))
                        ret = 1;
                }
            }  
        }
    }
    return ret;
}
void clearDP() {
    for(int i=0; i<10; i++)
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                dp[i][j][k] = -1;
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        for(string &row: board) cin >> row;
        int N;
        cin >> N;
        for(int i=0; i<N; i++) {
            clearDP();
            string target;
            cin >> target;
            bool ok = false;
            for(int i=0; i<5 && !ok; i++)
                for(int j=0; j<5 && !ok; j++)
                    if (search(target, 0, i, j)) {
                        ok = true;
                    }
            if (ok) cout << target << ' ' << "YES" << endl;
            else cout << target << ' ' << "NO" << endl;
        }
    }
   
}
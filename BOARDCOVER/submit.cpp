#include <iostream>
#include <vector>
using namespace std;
int H, W;
vector<string> board;
int countCoverings() {
    int x = -1, y = -1;
    for(int i=0; i<H && x == -1; i++) {
        for(int j=0; j<W; j++) {
            if (board[i][j] == '.') {
                x = i, y = j;
                break;
            }
        }
    }
    if (x == -1)
        return 1;
    int ret = 0;
    int d[4][2][2] = 
        {{{0, 1}, {1, 0}},
        {{1, 0}, {1, -1}},
        {{0, 1}, {1, 1}},
        {{1, 0}, {1, 1}}};
    for(int i=0; i<4; i++) {
        int nx1, nx2, ny1, ny2;
        nx1 = x + d[i][0][0];
        nx2 = x + d[i][1][0];
        ny1 = y + d[i][0][1];
        ny2 = y + d[i][1][1];
        if (0 <= nx1 && nx1 < H && 0 <= nx2 && nx2 < H &&
            0 <= ny1 && ny1 < W && 0 <= ny2 && ny2 < W &&
            board[nx1][ny1] == '.' && board[nx2][ny2] == '.') {
                board[x][y] = board[nx1][ny1] = board[nx2][ny2] = '#';
                ret += countCoverings();
                board[x][y] = board[nx1][ny1] = board[nx2][ny2] = '.';
            }
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> H >> W;
        board.clear();
        board.resize(H);
        for(auto &row: board) cin >> row;
        cout << countCoverings() << endl;
    }
}
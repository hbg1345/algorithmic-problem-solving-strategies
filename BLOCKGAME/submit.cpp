#include <iostream>
#include <vector>

using namespace std;

inline int cell(int y, int x) {
    return 1<<(y*5 + x);
}
vector<int> blocks;
void pushBlocks() {
    for(int y=0; y<5; y++) {
        for(int x=0; x<4; x++) {
            blocks.push_back(cell(y, x) + cell(y, x+1));
        }
    }
    for(int y=0; y<4; y++) {
        for(int x=0; x<5; x++) {
            blocks.push_back(cell(y, x) + cell(y+1, x));
        }
    }
    for(int y=0; y<4; y++) {
        for(int x=0; x<4; x++) {
            int dy[] = {0, 0, 1, 1}, dx[] = {0, 1, 0, 1};
            int square = 0;
            for(int k=0; k<4; k++) {
                square += cell(y+dy[k], x+dx[k]);
            }
            for(int k=0; k<4; k++) {
                blocks.push_back(square - cell(y+dy[k], x+dx[k]));   
            }
        }
    }
}
char cache[1<<25];

char canWin(int board) {
    char& ret = cache[board];
    if (ret != -1) return ret;
    ret = 0;
    for(int block: blocks) {
        if ((board & block) == 0) {
            board += block;
            if (!canWin(board)) ret = 1;
            board -= block;
        }
    }
    return ret;
}
int main() {
    pushBlocks();
    for(int i=0; i<(1<<25); i++) 
        cache[i] = -1;
    int C;
    cin >> C;
    while (C--) {
        string board[5];
        for(int i=0; i<5; i++)
            cin >> board[i];
        int bitBoard = 0;
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if (board[i][j] == '#')
                    bitBoard += cell(i, j);
            }
        }
        if (canWin(bitBoard)) cout << "WINNING";
        else cout << "LOSING";
        cout << endl;
    }

}
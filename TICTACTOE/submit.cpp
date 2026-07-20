#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum State {
    P1 = 0,
    P2 = 1,
    TIE = 2,
};

map<string, int> cache;
int whoWin(string& board) {
    if (cache.count(board))
        return cache[board];
    int& ret = cache[board];
    int player = 0;
    for(int i=0; i<9; i++)
        if (board[i] != '.') 
            player ^= 1;
    
    for(int i=0; i<3; i++) {
        if (board.substr(3*i, 3) == "xxx") 
            return ret = State::P1;
        if (board.substr(3*i, 3) == "ooo")
            return ret = State::P2;
    }
    for(int j=0; j<3; j++) {
        string col;
        for(int i=0; i<3; i++) {
            col.push_back(board[3*i+j]);
        } 
        if (col == "xxx") 
            return ret = State::P1;
        if (col == "ooo") 
            return ret = State::P2;
    }
    string diag;
    for(int i=0; i<3; i++) {
        diag.push_back(board[3*i+i]);
    }
    if (diag == "xxx") 
        return ret = State::P1;
    if (diag == "ooo") 
        return ret = State::P2;
    diag.clear();
    for(int i=0; i<3; i++) {
        diag.push_back(board[3*i+2-i]);
    }
    if (diag == "xxx") 
        return ret = State::P1;
    if (diag == "ooo") 
        return ret = State::P2;
    bool finished = true;
    bool tie = false;
    bool win = false;
    char put = player == State::P1 ? 'x' : 'o';
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            if (board[3*i+j] == '.') {
                finished = false;
                board[3*i+j] = put;
                int winner = whoWin(board);
                if (winner == State::TIE) tie = true;
                else if (winner == player) win = true;
                board[3*i+j] = '.';
            }
        }
    
    if (finished) return ret = State::TIE;
    if (win) return ret = player;
    if (tie) return ret = State::TIE;
    return ret = 1^player;
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        string board;
        for(int i=0; i<3; i++) {
            string row;
            cin >> row;
            board += row;
        }
        int ret = whoWin(board);
        if (ret == 0) cout << "x";
        else if (ret == 1) cout << "o";
        else cout << "TIE";
        cout << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string wildCard;
vector<string> fileNames;
int N, cache[55][110][110];

int match(int fileNumber, int fileNameMatched, int wildCardMatched) {
    int wildCardLen = wildCard.size();
    int fileNameLen = fileNames[fileNumber].size();

    if (wildCardMatched == wildCardLen && fileNameMatched == fileNameLen)
        return 1;
    if (wildCardMatched == wildCardLen)
        return 0;
    if (wildCard[wildCardMatched] != '*' && fileNameMatched == fileNameLen)
        return 0;

    int& ret = cache[fileNumber][fileNameMatched][wildCardMatched];
    if (ret != -1) return ret;
    ret = 0;
    if (fileNameMatched == fileNameLen) {
        ret = match(fileNumber, fileNameLen, wildCardMatched+1);
    }
    else if (wildCard[wildCardMatched] == '*') {
        ret |= match(fileNumber, fileNameMatched+1, wildCardMatched);
        ret |= match(fileNumber, fileNameMatched, wildCardMatched+1);
        // ret |= match(fileNumber, fileNameMatched+1, wildCardMatched+1);
    } else if (wildCard[wildCardMatched] == '?' || 
        wildCard[wildCardMatched] == fileNames[fileNumber][fileNameMatched]) {
        ret |= match(fileNumber, fileNameMatched+1, wildCardMatched+1);
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> wildCard;
        int N;
        cin >> N;
        fileNames.clear();
        fileNames.resize(N);
        vector<string> ans;
        for(int i=0; i<N; i++) 
            cin >> fileNames[i];
        for(int i=0; i<N; i++) 
            for(int j=0; j<110; j++)
                for(int k=0; k<110; k++)
                    cache[i][j][k] = -1;
        
        for(int i=0; i<N; i++) {
            if (match(i, 0, 0)) ans.push_back(fileNames[i]);
        }
        sort(ans.begin(), ans.end());
        for(auto &matchedString: ans)
            cout << matchedString << endl;
    }
}
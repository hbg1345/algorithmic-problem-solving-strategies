#include <iostream>
#include <vector>
#include <map>
using namespace std;

int m, q, n;
string words[505];
double B[505], T[505][505], M[505][505], cache[110][505];
vector<int> Q;

double probability(int start, int before) {
    if (start == Q.size()) return 1;
    double& ret = cache[start][before];
    if (ret != -1) return ret;
    ret = 0;
    if (start == 0) {
        for(int i=0; i<m; i++) 
            ret = max(ret, B[i]*M[i][Q[start]] * probability(start+1, i));
    } else {
        for(int i=0; i<m; i++) 
            ret = max(ret, T[before][i]*M[i][Q[start]] * probability(start+1, i));
    }
    return ret;
}

void reconstruct(int start, int before, vector<string>& picked) {
    if (start == Q.size()) return;
    double ret = probability(start, before);
    if (start == 0) {
        for(int i=0; i<m; i++) 
            if (ret == B[i]*M[i][Q[start]] * probability(start+1, i)) {
                picked.push_back(words[i]);
                reconstruct(start+1, i, picked);
            }
    } else {
        for(int i=0; i<m; i++) 
            if (ret == T[before][i]*M[i][Q[start]] * probability(start+1, i)) {
                picked.push_back(words[i]);
                reconstruct(start+1, i, picked);
            }
    }
}


void precal() {
    for(int i=0; i<110; i++)
        for(int j=0; j<505; j++)
            cache[i][j] = -1;
}

int main() {
    cin >> m >> q;
    for(int i=0; i<m; i++)
        cin >> words[i];
    for(int i=0; i<m; i++)
        cin >> B[i];
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            cin >> T[i][j];
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            cin >> M[i][j];
    map<string, int> wordToNum;
    for(int i=0; i<m; i++)
        wordToNum[words[i]] = i;
    
    while (q--) {
        cin >> n;
        Q.clear();
        precal();
        for(int i=0; i<n; i++) {
            string word;
            cin >> word;
            Q.push_back(wordToNum[word]);
        }
        vector<string> picked;
        reconstruct(0, 0, picked);
        for(auto c: picked) cout << c << ' ';
        cout << endl;
    }
    
}
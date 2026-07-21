#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<char> stck;
        bool ok = true;
        for(char c: s) {
            if (c == ')') {
                if (stck.empty() || stck.back() != '(') {
                    ok = false;
                    break;
                } else stck.pop_back();
            } else if (c == '}') {
                if (stck.empty() || stck.back() != '{') {
                    ok = false;
                    break;
                } else stck.pop_back();
            } else if (c == ']') {
                if (stck.empty() || stck.back() != '[') {
                    ok = false;
                    break;
                } else stck.pop_back();
            } else {
                stck.push_back(c);
            }
        }
        if (stck.empty() && ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
        
}
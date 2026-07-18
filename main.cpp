#include <iostream>
#include <vector>
using namespace std;

void normalize(vector<int>& num) {
    /* normalize <-> erase carry and borrow */
    num.push_back(0);
    for(int i=0; i<num.size(); i++) {
        if (num[i] < 0) { // negative case
            int borrow = (abs(num[i])+9)/10; // ceil(|n_i|/10)
            num[i+1] -= borrow;
            num[i] += 10*borrow;
        } else { // positve case
            int carry = num[i] / 10;
            num[i+1] += carry;
            num[i] %= 10;
        }
    }
    while (num.size() > 1 && num.back() == 0)
        num.pop_back();
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<int> c(a.size()+b.size()+1);
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<b.size(); j++)
            c[i+j] = a[i]*b[j];
    normalize(c);
    return c;
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        string members, fans;
        cin >> members >> fans;
        vector<int> a(members.size());
        vector<int> b(fans.size());
        for(int i=0; i<a.size(); i++) 
            a[a.size()-1-i] = members[i] == 'M' ? 1:0;
        for(int i=0; i<b.size(); i++) 
            b[i] = fans[i] == 'M' ? 1:0;
        auto ret = multiply(a, b);
        for(auto v: ret) cout << v << ' ';
        cout << endl;
    }
}
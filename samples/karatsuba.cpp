#include <iostream>
#include <vector>
using namespace std;

void normalize(vector<int>& num) {
    /* normalize <-> erase carry and borrow */
    num.push_back(0);
    for(int i=0; i+1<num.size(); i++) {
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

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size()+b.size()+1);
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<b.size(); j++)
            c[i+j] += a[i]*b[j];
    normalize(c);
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
    // a += bx10^k
    while(a.size() < b.size()+k) a.push_back(0);
    for(int i=0; i<b.size(); i++) {
        a[i+k] += b[i];
    }
    normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b) {
    // a -= b
    for(int i=0; i<b.size(); i++) {
        a[i] -= b[i];
    }
    normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b, a);
    if (bn == 0) return vector<int> ({0});
    if (an <= 50) return multiply(a, b);
    int half = an/2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min<int>(b.size(), half));
    vector<int> b1(b.begin()+min<int>(b.size(), half), b.end());
    // z2 = a1b1
    auto z2 = karatsuba(a1, b1);
    // z0 = a0b0
    auto z0 = karatsuba(a0, b0);
    // a0 = a0+a1; b0 = b0+b1
    addTo(a0, a1, 0); addTo(b0, b1, 0); 
    // z1 = a0b0-z0-z2
    auto z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);
    // ret = z0+z1x10^half+z2x10^(2half)
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, 2*half);
    return ret;
}
int main() {
    vector<int> a({1, 2}), b({3, 4});
    vector<int> c = multiply(a, b); // 21*43 = 903
    for(auto cc: c) cout << cc << ' '; // {3, 0, 9}
    cout << endl;
}
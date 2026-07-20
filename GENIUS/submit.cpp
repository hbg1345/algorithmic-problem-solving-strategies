#include <iostream>
#include <vector>

using namespace std;
double T[55][55];
int L[55];

int N;
vector<vector<double>> W;
void precal() {
    W.clear();
    W.resize(4*N);
     for(int i=0; i<4*N; i++)
        for(int j=0; j<4*N; j++)
            W[i].push_back(0);
    
    for(int i=0; i<3; i++) {
        for(int y=0; y<N; y++) {
            W[N*i + y][N*(i+1) + y] = 1;
        }
    }
    for(int grp=0; grp<4; grp++) {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) {
                if (L[j] + grp == 4) {
                    W[3*N+i][N*grp + j] = T[j][i];
                }
            }
    }
}

vector<vector<double>> multiply(vector<vector<double>> a, vector<vector<double>> b) {
    vector<vector<double>> ret = a;
    for(int i=0; i<4*N; i++)
        for(int j=0; j<4*N; j++) {
            ret[i][j] = 0;
            for(int k=0; k<4*N; k++)
                ret[i][j] += a[i][k] * b[k][j];
        }
    return ret;
}
vector<vector<double>> pow(vector<vector<double>> a, int k) {
    vector<vector<double>> ret = a;
    for(int i=0; i<4*N; i++)
        for(int j=0; j<4*N; j++)
            ret[i][j] = 0;
    if (k == 0) {
        for(int i=0; i<4*N; i++)
            ret[i][i] = 1;
        return ret;
    }
    if (k%2) return multiply(a, pow(a, k-1));
    ret = pow(a, k/2);
    return multiply(ret, ret);
}


int main() {
    cout.precision(15);
    cout << fixed;
    int C;
    cin >> C;
    while (C--) {
        int K, M;
        cin >> N >> K >> M;
        for(int i=0; i<N; i++)
            cin >> L[i];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> T[i][j];
        precal();
        vector<vector<double>> Wk = pow(W, K);
        for(int i=0; i<M; i++) {
            int q;
            cin >> q;
            double ans = 0;
            for(int d=0; d<L[q]; d++) {
                ans += Wk[(3-d)*N+q][3*N];
            }
            cout << ans << ' ';
        }
        cout << endl;
    }   
        
}
#include <iostream>
#include <algorithm>

using namespace std;

int A[110], B[110];
int main() {
    int C;
    cin >> C;
    while (C--) {
        int N;
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> A[i];
        for(int i=0; i<N; i++)
            cin >> B[i];
        sort(A, A+N);
        sort(B, B+N);
        int win = 0;
        int j = 0;
        for(int i=0; i<N; i++) {
            while (j < N && B[j] < A[i])
                j++;
            if (j == N)
                break;
            j++;
            win++;
        }
        cout << win << endl;
    }   
        
}
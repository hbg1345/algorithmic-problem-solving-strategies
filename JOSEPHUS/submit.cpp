#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int v;
    ListNode *prev, *next;
};

void delNode(ListNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        ListNode *one = new ListNode({1, nullptr, nullptr});
        ListNode *prev = one;        
        for(int i=2; i<=N; i++) {
            ListNode *cur = new ListNode({i, prev, nullptr});
            prev->next = cur;
            if (i == N) {
                cur->next = one;
                one->prev = cur;
            }
            prev = cur;
        }
        ListNode *cur = one;
        for(int it=0; it<N-2; it++) {
            ListNode *ncur = cur->next;
            delNode(cur);
            for(int it2=0; it2<(K-1)%(N-1); it2++)
                ncur = ncur->next;
            cur = ncur;
        }
        int a = cur->v, b = cur->next->v;
        if (a > b) swap(a, b);
        cout << a << ' ' << b << endl;
        ListNode *nxt = cur->next;
        delNode(cur); 
        delNode(nxt);
    }   
        
}
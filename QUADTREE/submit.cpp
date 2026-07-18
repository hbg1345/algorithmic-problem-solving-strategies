#include <iostream>
#include <vector>
using namespace std;

int findLine(string &quadTree, int i) {
    if (quadTree[i] == 'w' || quadTree[i] == 'b')
        return i+1;
    i++;
    for(int j=0; j<4; j++) {
        i = findLine(quadTree, i);
    }
    return i;
}

void reverseQuadtree(string &quadTree, int i) {
    if (quadTree[i] == 'w' || quadTree[i] == 'b') {
        cout << quadTree[i];
        return;
    }
    cout << 'x';
    int q1 = findLine(quadTree, i+1);
    int q2 = findLine(quadTree, q1);
    int q3 = findLine(quadTree, q2);
    reverseQuadtree(quadTree, q2);
    reverseQuadtree(quadTree, q3);
    reverseQuadtree(quadTree, i+1);
    reverseQuadtree(quadTree, q1);
}

string reverseQuadtree2(string::iterator& it) {
    char head = *it;
    it++;
    if (head == 'w' || head == 'b') {
        return string(1, head);
    }
    string upperLeft = reverseQuadtree2(it);
    string upperRight = reverseQuadtree2(it);
    string lowerLeft = reverseQuadtree2(it);
    string lowerRight = reverseQuadtree2(it);
    return "x"+lowerLeft+lowerRight+upperLeft+upperRight;
}


int main() {
    int C;
    cin >> C;
    while (C--) {
        string quadtree;
        cin >> quadtree;
        reverseQuadtree(quadtree, 0);
        // string::iterator it = quadtree.begin();
        // cout << reverseQuadtree2(it);
        cout << endl;
    }
}
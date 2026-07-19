#include <iostream>
using namespace std;

int n, m;
double cache[1010][1010];

double escapeProbability(int pos, int day) {
    if (pos <= 0) return 1.;
    if (day == 0) return 0.;
    double& ret = cache[pos][day];
    if (ret != -1) return ret;
    ret = 0.25*escapeProbability(pos-1, day-1);
    ret += 0.75*escapeProbability(pos-2, day-1);
    return ret;
}

void precal() {
    for(int i=0; i<1010; i++) 
        for(int j=0; j<1010; j++)
            cache[i][j] = -1;
}
int main() {
    
}
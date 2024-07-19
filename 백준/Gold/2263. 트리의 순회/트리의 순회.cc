#include <iostream>
#include <vector>

using namespace std;

int n, preIdx;
vector<int> inOrd, preOrd, postOrd;

void cmpOrd(int is, int ie, int ps, int pe){
    if(is > ie || ps > pe)return;

    preOrd[preIdx++] = postOrd[pe];

    if(is == ie)return;

    int idx;
    for(idx = 0; idx <= ie - is; idx++)if(inOrd[is + idx] == postOrd[pe])break;

    cmpOrd(is, is + idx - 1, ps, ps + idx - 1);
    cmpOrd(is + idx + 1, ie, ps + idx, pe - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    inOrd.resize(n);
    preOrd.resize(n);
    postOrd.resize(n);

    for(int i = 0; i < n; i++)cin >> inOrd[i];
    for(int i = 0; i < n; i++)cin >> postOrd[i];

    cmpOrd(0, n - 1, 0, n - 1);

    for(int i = 0; i < n; i++)cout << preOrd[i] << " ";

    return 0;
}

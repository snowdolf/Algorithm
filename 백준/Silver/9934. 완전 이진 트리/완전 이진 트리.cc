#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void f(int l, int r, int d, const vector<int> &v, vector<int> &b){
    if(l > r)return;

    int m = (l + r) / 2;

    f(l, m - 1, 2 * d, v, b);
    b[d] = v[m];
    f(m + 1, r, 2 * d + 1, v, b);

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    vector<int> v((int)pow(2, k));
    vector<int> b(v.size(), 0);
    for(int i = 1; i < v.size(); i++)cin >> v[i];

    f(1, v.size() - 1, 1, v, b);

    int idx = 1;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < (int)pow(2, i); j++){
            cout << b[idx] << " ";
            idx++;
        }
        cout << "\n";
    }

    return 0;
}
#include <iostream>

using namespace std;

int p[5], t[105], l, r, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> p[1] >> p[2] >> p[3];
    for(int i = 0; i < 3; i++){
        cin >> l >> r;
        for(int j = l; j < r; j++)t[j]++;
    }

    for(int i = 1; i <= 100; i++){
        ans += t[i] * p[t[i]];
    }

    cout << ans;

    return 0;
}
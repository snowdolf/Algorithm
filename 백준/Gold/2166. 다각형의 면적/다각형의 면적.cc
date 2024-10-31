#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<pair<double, double>> pos;
double ans = 0.0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    pos.resize(n);
    for(int i = 0; i < n; i++){
        cin >> pos[i].first >> pos[i].second;
    }

    for(int i = 0; i < n - 1; i++){
        ans = ans + pos[i].first * pos[i + 1].second - pos[i].second * pos[i + 1].first;
    }
    ans = ans + pos[n - 1].first * pos[0].second - pos[n - 1].second * pos[0].first;

    ans = abs(ans) / 2;

    cout << fixed;
    cout.precision(1);
    cout << ans;

    return 0;
}